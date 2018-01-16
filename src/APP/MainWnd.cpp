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
        // 扫描检测程式
        this->scanJobFolder();

        // 加载完程式,检测
        cout << "Press \"y\" to inspect:" << endl;
        char inspect {'y'};
        cin >> inspect;
        if( 'y' == inspect )
        {
            do
            {
                this->inspectClick();
                cout << "Press \"y\" to inspect again:" << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cin >> inspect;
            }while ( 'y' == inspect );
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
            cout << "\nChoice number to create or load job:\n";
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
        // 3.创建程式或加载程式
        if( 0 == index )
        {
            // 创建新的程式
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
            loadJob(jobPath);
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
    try
    {

    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Load job file error!");
}

void MainWnd::createDefaultJob(const QString& jobName)
{
    SqliteDB sqlite;
    try
    {
        InspectionData inspectionData = g_pSequence->inspectionManager().inspectionData();
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
        sqlite.execute( sqlInsert, inspectionData.version(),
                                   inspectionData.lastEditingTime() );

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
        sqlite.execute( sqlInsert, inspectionData.board().name(),
                                   inspectionData.board().rectangle().width(),
                                   inspectionData.board().rectangle().height(),
                                   inspectionData.board().originPoint().posX(),
                                   inspectionData.board().originPoint().posY() );

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //3 创建MeasuredObjs表，表中包含字段：ID、Name、CentralX、CentralY、Width、Height、Angle、LibID、IsResultOK
        sqlCreate = "CREATE TABLE MeasuredObjs( "
                    "ID INTEGER, "
                    "Name TEXT, "
                    "CentralX REAL, "
                    "CentralY REAL, "
                    "Width REAL, "
                    "Height REAL, "
                    "Angle REAL, "
                    "LibID INTEGER, "
                    "IsResultOK INTEGER );";
        sqlite.execute( sqlCreate );

        sqlInsert = "INSERT INTO MeasuredObjs( "
                    "ID, Name, CentralX, CentralY, Width, Height, Angle, LibID, IsResultOK ) "
                    "VALUES(?,?,?,?,?,?,?,?,?);";
        int objCnt = inspectionData.board().pObjs().size(); // 元件个数
        int isResultOk = 0; // 检测结果是否OK

        sqlite.prepare( sqlInsert );
        sqlite.begin();
        for (int i = 0; i < objCnt; ++i)
        {
            // 判断检测结果是否OK，OK为0，NG为1
            if (true == inspectionData.board().pObjs().at(i)->isResultOk())
            {
                isResultOk = 0;
            }
            else
            {
                isResultOk = 1;
            }
            sqlite.execute( sqlInsert, inspectionData.board().pObjs().at(i)->id(),
                                       inspectionData.board().pObjs().at(i)->name(),
                                       inspectionData.board().pObjs().at(i)->rectangle().centerPoint().posX(),
                                       inspectionData.board().pObjs().at(i)->rectangle().centerPoint().posY(),
                                       inspectionData.board().pObjs().at(i)->rectangle().width(),
                                       inspectionData.board().pObjs().at(i)->rectangle().height(),
                                       inspectionData.board().pObjs().at(i)->rectangle().angle(),
                                       inspectionData.board().pObjs().at(i)->lib().id(),
                                       isResultOk );
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
        for (int i = 0; i < objCnt; ++i)
        {
            sqlite.execute( sqlInsert, inspectionData.board().pObjs().at(i)->lib().id(),
                                       inspectionData.board().pObjs().at(i)->lib().name() );
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
        string algType = "3D";

        sqlite.prepare( sqlInsert );
        sqlite.begin();
        for (int i = 0; i < objCnt; ++i)
        {
            sqlite.execute( sqlInsert, inspectionData.board().pObjs().at(i)->lib().mainItem().libId(),
                                       inspectionData.board().pObjs().at(i)->lib().mainItem().id(),
                                       inspectionData.board().pObjs().at(i)->lib().mainItem().rectangle().centerPoint().posX(),
                                       inspectionData.board().pObjs().at(i)->lib().mainItem().rectangle().centerPoint().posY(),
                                       inspectionData.board().pObjs().at(i)->lib().mainItem().rectangle().width(),
                                       inspectionData.board().pObjs().at(i)->lib().mainItem().rectangle().height(),
                                       inspectionData.board().pObjs().at(i)->lib().mainItem().rectangle().angle(),
                                       inspectionData.board().pObjs().at(i)->lib().mainItem().name(),
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
        int fiducialMarkCnt = 2; // 基准点设置为2个
        algType = "2D";

        sqlite.prepare( sqlInsert );
        sqlite.begin();
        for (int i = 0; i < fiducialMarkCnt; ++i)
        {
            for(list<SubItem>::iterator j = inspectionData.board().pObjs().at(i)->lib().itemList().begin();
                j != inspectionData.board().pObjs().at(i)->lib().itemList().end(); ++j)
            {
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
