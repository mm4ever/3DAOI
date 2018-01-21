#include "MainWnd.hpp"

using namespace std;

using namespace APP;
using namespace Job;
using namespace SSDK;
using namespace SSDK::DB;

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constructor & destructor

MainWnd::MainWnd()
{
    try
    {

    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Constructor error!");
}

MainWnd::~MainWnd()
{
    try
    {

    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Destructor error!");
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// member function

void MainWnd::run()
{
    try
    {
        srand(time(NULL));
        // 扫描检测程式
        this->scanJobFolder();

        // 加载完程式,检测
        cout << "Press \"y\" to inspect:";
        char inspectValue;
        string xmlFileName{""};
        QString xmlPath{""};
        cin >> inspectValue;
        if( 'y' == inspectValue || 'Y' == inspectValue )
        {
            do
            {
                this->inspectClick();
                xmlFileName = APP::g_pSequence->inspectionManager().inspectionData().board().name()
                               + "_" + DataGenerator::getCurrentTime()+".xml";
                xmlPath = APP::g_pAppService->pathSetting().exportXmlPath() +
                                   xmlFileName.c_str();
                APP::g_pSequence->inspectionManager().inspectionData().writeInspectionDataToXml(
                xmlPath);
                cout << "Press \"y\" to inspect again:";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cin >> inspectValue;
            }while ( 'y' == inspectValue || 'Y' == inspectValue );
        }
        cout << "Quit ..." << endl;
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Running main window error!");
}

void MainWnd::scanJobFolder()
{
    QString path = APP::g_pAppService->pathSetting().defaultJobFolderPath();
    try
    {
        //>>>-------------------------------------------------------------------
        // 1.判断文件夹是否存在，不存在则创建
        QDir dir(path);
        if(!dir.exists())
        {
            std::cout << path.toStdString() << " is not exists!"<< std::endl;
            if( !dir.mkpath(path) )    // 创建失败
            {
                // 创建配置文件失败,抛出异常
                THROW_EXCEPTION("No job path and create error!");
            }
        }
        //>>>-------------------------------------------------------------------
        // 2.扫描程式文件
        QStringList filters;    // 创建过滤器列表，过滤xml、txt为后缀的文件
        filters << "*[^xml|^txt]";
        dir.setNameFilters(filters);

        dir.setFilter(QDir::Files);
        QFileInfoList list = dir.entryInfoList();


        // 先显示"创建程式"的提示信息,再将扫描的文件打印
        cout << "0:Create default job" << endl;
        for (int i = 0; i < list.size(); ++i)
        {
            cout<<qPrintable(QString("%1:%2\n").arg(i+1).arg(list.at(i).fileName()));
        }
        int index {-1};
        do  // 选择创建程式或需要加载的程式文件
        {
            cout << "\nChoice number to create or load job:";
            cin >> index;
            if(!cin)       // 输入不是数字
            {
                cout << "Error! Not a digit!" << std::endl;
                index = -1;
            }
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        while( index > list.size() || index < 0);
        //>>>-------------------------------------------------------------------
        // 3.创建或加载程式

        if( 0 == index )                // 创建新的程式
        {
            // 在内存中生成默认的检测数据
            DataGenerator datagenerator;
            datagenerator.generateInspectionData(g_pSequence->inspectionManager().inspectionData());

            QString jobPath {path};
            string jobName;
            cout << "Please input job name:";
            getline(cin,jobName);
            jobPath.append(QString::fromStdString(jobName));
            createDefaultJob(jobPath);
        }
        else
        {
            // 加载用户选择的程式
            QString jobPath = list.at(index-1).filePath();
            g_pSequence->inspectionManager().loadInspectionData(jobPath);
        }
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Catch exception and rethrow");
}

void MainWnd::inspectClick()
{
    try
    {
        APP::g_pSequence->inspectCycle();
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Inspect click error!");
}

void MainWnd::loadJob(const QString& jobPath)
{
    SqliteDB sqlite( jobPath.toStdString() );
    try
    {
        // 打开数据库
        auto isOpened = sqlite.isOpened();
        if( isOpened )
        {
            //>>>----------------------------------------------------------------------------------------------------------
            //1 读取InspectionData表
            // 查询数据表中所有内容
            string selectedString = "select * from InspectionData";
            sqlite.prepare( selectedString );
            sqlite.begin();

            while( true )
            {
                // 逐行读取
                sqlite.step();
                if ( sqlite.latestErrorCode() == SQLITE_DONE )
                {
                    break;
                }
                // 按列读取（第一列为版本号，第二列为上次编辑时间）
                g_pSequence->inspectionManager().inspectionData().version() = boost::get<string>(sqlite.columnValue(0));
                g_pSequence->inspectionManager().inspectionData().lastEditingTime() = boost::get<string>(sqlite.columnValue(1));
            }

            //>>>----------------------------------------------------------------------------------------------------------
            //2 读取Board表
            selectedString = "select * from Board";
            sqlite.prepare( selectedString );
            sqlite.begin();

            while( true )
            {
                sqlite.step();
                if ( sqlite.latestErrorCode() == SQLITE_DONE )
                {
                    break;
                }
                g_pSequence->inspectionManager().inspectionData().board().name() = boost::get<string>(sqlite.columnValue(0));
                g_pSequence->inspectionManager().inspectionData().board().rectangle().setWidth( boost::get<double>(sqlite.columnValue(1)) );
                g_pSequence->inspectionManager().inspectionData().board().rectangle().setHeight( boost::get<double>(sqlite.columnValue(2)) );
                g_pSequence->inspectionManager().inspectionData().board().originPoint().setPosX( boost::get<double>(sqlite.columnValue(3)) );
                g_pSequence->inspectionManager().inspectionData().board().originPoint().setPosY( boost::get<double>(sqlite.columnValue(4)) );
            }

            //>>>-------------------------------------------------------------------------------------------------------------------------------------
            //3 读取Library表
            selectedString = "select * from Library";
            sqlite.prepare( selectedString );
            sqlite.begin();

            // 读取数据表中信息并存到Library容器中
            Library* pLibrary = nullptr;
            while(true)
            {
                sqlite.step();
                if(sqlite.latestErrorCode() == SQLITE_DONE)
                {
                    break;
                }
                pLibrary = new Library();
                pLibrary->setId( boost::get<int>(sqlite.columnValue(0)) );
                pLibrary->name() = boost::get<string>(sqlite.columnValue(1));
                g_pSequence->inspectionManager().inspectionData().board().pLibs().push_back(pLibrary);
            }

            //>>>-------------------------------------------------------------------------------------------------------------------------------------
            //4 读取MainItem表
            selectedString = "select * from MainItem";
            sqlite.prepare( selectedString );
            sqlite.begin();

            // 使用迭代器访问容器vector中的元素
            vector<Library *>::iterator it = g_pSequence->inspectionManager().inspectionData().board().pLibs().begin();
            while(true)
            {
                sqlite.step();
                if(sqlite.latestErrorCode() == SQLITE_DONE)
                {
                    break;
                }
                // 读取并判断数据表中的算法类型，然后在内存中设置相应的算法类型
                if ( VAR_TO_STR(Alg::AlgType::ALG3D) == boost::get<string>(sqlite.columnValue(8)) )
                {
                    (*it)->mainItem().setPAlg( new Alg3D() );
                }
                else if ( VAR_TO_STR(Alg::AlgType::ALG2D) == boost::get<string>(sqlite.columnValue(8)) )
                {
                    (*it)->mainItem().setPAlg( new Alg2D() );
                }
                else
                {
                    THROW_EXCEPTION("MainItem算法类型读取失败！");
                }
                (*it)->mainItem().setLibId( boost::get<int>(sqlite.columnValue(0)) );
                (*it)->mainItem().setId( boost::get<int>(sqlite.columnValue(1)) );
                (*it)->mainItem().rectangle().centerPoint().setPosX( boost::get<double>(sqlite.columnValue(2)) );
                (*it)->mainItem().rectangle().centerPoint().setPosY( boost::get<double>(sqlite.columnValue(3)) );
                (*it)->mainItem().rectangle().setWidth( boost::get<double>(sqlite.columnValue(4)) );
                (*it)->mainItem().rectangle().setHeight( boost::get<double>(sqlite.columnValue(5)) );
                (*it)->mainItem().rectangle().setAngle( boost::get<double>(sqlite.columnValue(6)) );
                (*it)->mainItem().name() = boost::get<string>(sqlite.columnValue(7));
                ++it;
            }

            //>>>-------------------------------------------------------------------------------------------------------------------------------------
            //5 读取SubItem表
            selectedString = "select * from SubItem";
            sqlite.prepare( selectedString );
            sqlite.begin();

            while(true)
            {
                sqlite.step();
                if(sqlite.latestErrorCode() == SQLITE_DONE)
                {
                    break;
                }
                for (vector<Library *>::iterator i = g_pSequence->inspectionManager().inspectionData().board().pLibs().begin();
                     i != g_pSequence->inspectionManager().inspectionData().board().pLibs().end(); ++i)
                {
                    // 在Library容器中找到与数据表中相应的库的ID号，然后将数据表中的信息存放到SubItem容器中
                    if ( (*i)->id() == boost::get<int>(sqlite.columnValue(0)) )
                    {
                        (*i)->itemList().push_back(SubItem());
                        SubItem& item = (*i)->itemList().back();
                        if ( VAR_TO_STR(Alg::AlgType::ALG2D) == boost::get<string>(sqlite.columnValue(8)) )
                        {
                            item.setPAlg( new Alg2D() );
                        }
                        else if ( VAR_TO_STR(Alg::AlgType::ALG3D) == boost::get<string>(sqlite.columnValue(8)) )
                        {
                            item.setPAlg( new Alg3D() );
                        }
                        else
                        {
                            THROW_EXCEPTION("SubItem算法类型读取失败！");
                        }
                        item.setLibId( boost::get<int>(sqlite.columnValue(0)) );
                        item.setId( boost::get<int>(sqlite.columnValue(1)) );
                        item.rectangle().centerPoint().setPosX( boost::get<double>(sqlite.columnValue(2)) );
                        item.rectangle().centerPoint().setPosY( boost::get<double>(sqlite.columnValue(3)) );
                        item.rectangle().setWidth( boost::get<double>(sqlite.columnValue(4)) );
                        item.rectangle().setHeight( boost::get<double>(sqlite.columnValue(5)) );
                        item.rectangle().setAngle( boost::get<double>(sqlite.columnValue(6)) );
                        item.name() = boost::get<string>(sqlite.columnValue(7));
                        item.setOrder( boost::get<int>(sqlite.columnValue(9)) );
                        break;
                    }
                }
            }

            //>>>-------------------------------------------------------------------------------------------------------------------------------------
            //6 读取MeasuredObjs表
            selectedString = "select * from MeasuredObjs";
            sqlite.prepare( selectedString );
            sqlite.begin();

            MeasuredObj *pMeasuredObj = nullptr;
            while(true)
            {
                sqlite.step();
                if(sqlite.latestErrorCode() == SQLITE_DONE)
                {
                    break;
                }
                // 读取并判断数据表中的被测对象类型，然后创建相应的类型的对象
                if (VAR_TO_STR(MeasuredObj::MeasuredObjType::FIDUCIALMARK) == boost::get<string>(sqlite.columnValue(8)) )
                {
                    pMeasuredObj = new FiducialMark();
                }
                else if (VAR_TO_STR(MeasuredObj::MeasuredObjType::COMPONENT) == boost::get<string>(sqlite.columnValue(8)) )
                {
                    pMeasuredObj = new Component();
                }
                else
                {
                    THROW_EXCEPTION("元件类型读取失败！");
                }
                pMeasuredObj->setId( boost::get<int>(sqlite.columnValue(0)) );
                pMeasuredObj->name() = boost::get<string>(sqlite.columnValue(1));
                pMeasuredObj->rectangle().centerPoint().setPosX( boost::get<double>(sqlite.columnValue(2)) );
                pMeasuredObj->rectangle().centerPoint().setPosY( boost::get<double>(sqlite.columnValue(3)) );
                pMeasuredObj->rectangle().setWidth( boost::get<double>(sqlite.columnValue(4)) );
                pMeasuredObj->rectangle().setHeight( boost::get<double>(sqlite.columnValue(5)) );
                pMeasuredObj->rectangle().setAngle( boost::get<double>(sqlite.columnValue(6)) );

                // 在Library容器中找到与数据表中相应的库的ID号，然后设置相应的库的信息
                for (vector<Library *>::iterator i = g_pSequence->inspectionManager().inspectionData().board().pLibs().begin();
                     i != g_pSequence->inspectionManager().inspectionData().board().pLibs().end(); ++i)
                {
                    if( (*i)->id() == boost::get<int>(sqlite.columnValue(7)) )
                    {
                        pMeasuredObj->setPLib((*i));
                        break;
                    }
                }
                g_pSequence->inspectionManager().inspectionData().board().pObjs().push_back(pMeasuredObj);
            }

            sqlite.reset();
            sqlite.close();
        }
        else
        {
            THROW_EXCEPTION("程式加载失败！");
        }
    }
    catch( const CustomException& ex )
    {
        if( sqlite.isOpened() )
        {
            sqlite.reset();
            sqlite.close();
        }
        THROW_EXCEPTION( ex.what() );
    }
}

void MainWnd::createDefaultJob(const QString& jobName)
{
    SqliteDB sqlite;
    try
    {
        // 创建数据库对象，打开传入路径的数据库
        sqlite.open( jobName.toStdString() );

        if( !sqlite.isOpened() )
        {
            THROW_EXCEPTION("数据库打开失败！");
        }
        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //1 创建InspectionData表，表中包含字段：Version、LastEditingTime
        string sqlCreate = "CREATE TABLE InspectionData( "
                           "Version TEXT, "
                           "LastEditingTime TEXT );";
        sqlite.execute( sqlCreate );
        // 插入各字段对应的数据
        string sqlInsert = "INSERT INTO InspectionData( "
                           "Version, LastEditingTime ) "
                           "VALUES(?,?);";
        sqlite.execute( sqlInsert, g_pSequence->inspectionManager().inspectionData().version(),
                                   g_pSequence->inspectionManager().inspectionData().lastEditingTime() );

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2 创建Board表，表中包含字段：Name、SizeX、SizeY、OriginalX、OriginalY
        sqlCreate = "CREATE TABLE Board( "
                    "Name TEXT, "
                    "SizeX REAL, "
                    "SizeY REAL, "
                    "OriginalX REAL, "
                    "OriginalY REAL );";
        sqlite.execute( sqlCreate );

        sqlInsert = "INSERT INTO Board( "
                    "Name, SizeX, SizeY, OriginalX, OriginalY ) "
                    "VALUES(?,?,?,?,?);";
        sqlite.execute( sqlInsert, g_pSequence->inspectionManager().inspectionData().board().name(),
                                   g_pSequence->inspectionManager().inspectionData().board().rectangle().width(),
                                   g_pSequence->inspectionManager().inspectionData().board().rectangle().height(),
                                   g_pSequence->inspectionManager().inspectionData().board().originPoint().posX(),
                                   g_pSequence->inspectionManager().inspectionData().board().originPoint().posY() );

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //3 创建MeasuredObjs表，表中包含字段：ID、Name、CentralX、CentralY、Width、Height、Angle、LibID、MeasuredObjType
        sqlCreate = "CREATE TABLE MeasuredObjs( "
                    "ID INTEGER, "
                    "Name TEXT, "
                    "CentralX REAL, "
                    "CentralY REAL, "
                    "Width REAL, "
                    "Height REAL, "
                    "Angle REAL, "
                    "LibID INTEGER, "
                    "MeasuredObjType TEXT );";
        sqlite.execute( sqlCreate );

        sqlInsert = "INSERT INTO MeasuredObjs( "
                    "ID, Name, CentralX, CentralY, Width, Height, Angle, LibID, MeasuredObjType ) "
                    "VALUES(?,?,?,?,?,?,?,?,?);";

        string measuredObjType = "";

        sqlite.prepare( sqlInsert );
        sqlite.begin();
        for (vector<MeasuredObj *>::iterator i = g_pSequence->inspectionManager().inspectionData().board().pObjs().begin();
             i != g_pSequence->inspectionManager().inspectionData().board().pObjs().end(); ++i)
        {
            // 判断生成的被测对象类型，然后设置相应的类型
            if (MeasuredObj::MeasuredObjType::FIDUCIALMARK == (*i)->measuredObjType() )
            {
                measuredObjType = VAR_TO_STR(MeasuredObjType::FIDUCIALMARK);
            }
            else if (MeasuredObj::MeasuredObjType::COMPONENT == (*i)->measuredObjType() )
            {
                measuredObjType = VAR_TO_STR(MeasuredObjType::COMPONENT);
            }
            else
            {
                THROW_EXCEPTION("元件类型错误！");
            }

            sqlite.execute( sqlInsert, (*i)->id(),
                                       (*i)->name(),
                                       (*i)->rectangle().centerPoint().posX(),
                                       (*i)->rectangle().centerPoint().posY(),
                                       (*i)->rectangle().width(),
                                       (*i)->rectangle().height(),
                                       (*i)->rectangle().angle(),
                                       (*i)->pLib()->id(),
                                       measuredObjType );
        }
        sqlite.commit();

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //4 创建Library表，表中包含字段：ID、Name
        sqlCreate = "CREATE TABLE Library( "
                    "ID INTEGER, "
                    "Name TEXT );";
        sqlite.execute( sqlCreate );

        sqlInsert = "INSERT INTO Library( "
                    "ID, Name) "
                    "VALUES(?,?);";

        sqlite.prepare( sqlInsert );
        sqlite.begin();
        for (vector<Library *>::iterator i = g_pSequence->inspectionManager().inspectionData().board().pLibs().begin();
             i != g_pSequence->inspectionManager().inspectionData().board().pLibs().end(); ++i)
        {
            sqlite.execute( sqlInsert, (*i)->id(),
                                       (*i)->name() );
        }
        sqlite.commit();

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //5 创建MainItem表，表中包含字段：LibID、ID、ShiftX、ShiftY、Width、Height、Angle、Name、Alg
        sqlCreate = "CREATE TABLE MainItem( "
                    "LibID INTEGER, "
                    "ID INTEGER, "
                    "ShiftX REAL, "
                    "ShiftY REAL, "
                    "Width REAL, "
                    "Height REAL, "
                    "Angle REAL, "
                    "Name TEXT, "
                    "Alg TEXT );";
        sqlite.execute( sqlCreate );

        sqlInsert = "INSERT INTO MainItem( "
                    "LibID, ID, ShiftX, ShiftY, Width, Height, Angle, Name, Alg) "
                    "VALUES(?,?,?,?,?,?,?,?,?);";
        string algType = "";

        sqlite.prepare( sqlInsert );
        sqlite.begin();
        for (vector<Library *>::iterator i = g_pSequence->inspectionManager().inspectionData().board().pLibs().begin();
             i != g_pSequence->inspectionManager().inspectionData().board().pLibs().end(); ++i)
        {
            // 判断生成的算法类型，然后设置相应的类型
            if (Alg::AlgType::ALG3D == (*i)->mainItem().pAlg()->algType())
            {
                algType = VAR_TO_STR(AlgType::ALG3D);
            }
            else if (Alg::AlgType::ALG2D == (*i)->mainItem().pAlg()->algType() )
            {
                algType = VAR_TO_STR(AlgType::ALG2D);
            }
            else
            {
                THROW_EXCEPTION("MainItem算法类型错误！");
            }
            sqlite.execute( sqlInsert, (*i)->mainItem().libId(),
                                       (*i)->mainItem().id(),
                                       (*i)->mainItem().rectangle().centerPoint().posX(),
                                       (*i)->mainItem().rectangle().centerPoint().posY(),
                                       (*i)->mainItem().rectangle().width(),
                                       (*i)->mainItem().rectangle().height(),
                                       (*i)->mainItem().rectangle().angle(),
                                       (*i)->mainItem().name(),
                                       algType );
        }
        sqlite.commit();

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //6 创建SubItem表，表中包含字段：LibID、ID、ShiftX、ShiftY、Width、Height、Angle、Name、Alg、Order
        sqlCreate = "CREATE TABLE SubItem( "
                    "LibID INTEGER, "
                    "ID INTEGER, "
                    "ShiftX REAL, "
                    "ShiftY REAL, "
                    "Width REAL, "
                    "Height REAL, "
                    "Angle REAL, "
                    "Name TEXT, "
                    "Alg TEXT, "
                    "'Order' INTEGER );";
        sqlite.execute( sqlCreate );

        sqlInsert = "INSERT INTO SubItem( "
                    "LibID, ID, ShiftX, ShiftY, Width, Height, Angle, Name, Alg, 'Order') "
                    "VALUES(?,?,?,?,?,?,?,?,?,?);";

        sqlite.prepare( sqlInsert );
        sqlite.begin();
        for (size_t i = 0; i < g_pSequence->inspectionManager().inspectionData().board().pLibs().size(); ++i)
        {
            for(list<SubItem>::iterator j = g_pSequence->inspectionManager().inspectionData().board().pLibs()[i]->itemList().begin();
                j != g_pSequence->inspectionManager().inspectionData().board().pLibs()[i]->itemList().end(); ++j)
            {
                if (Alg::AlgType::ALG2D == (*j).pAlg()->algType())
                {
                    algType = VAR_TO_STR(AlgType::ALG2D);
                }
                else if (Alg::AlgType::ALG3D == (*j).pAlg()->algType() )
                {
                    algType = VAR_TO_STR(AlgType::ALG2D);
                }
                else
                {
                    THROW_EXCEPTION("SubItem算法类型错误！");
                }
                sqlite.execute( sqlInsert, (*j).libId(),
                                           (*j).id(),
                                           (*j).rectangle().centerPoint().posX(),
                                           (*j).rectangle().centerPoint().posY(),
                                           (*j).rectangle().width(),
                                           (*j).rectangle().height(),
                                           (*j).rectangle().angle(),
                                           (*j).name(),
                                           algType,
                                           (*j).order() );
            }
        }
        sqlite.commit();

        sqlite.close();
    }
    catch( const CustomException& ex )
    {
        if( sqlite.isOpened() )
        {
            sqlite.reset();
            sqlite.close();
        }
        THROW_EXCEPTION( ex.what() );
    }
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
