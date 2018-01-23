#include "DataGenerator.hpp"

using namespace std;

using namespace APP;
using namespace Job;

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constructor & destructor

DataGenerator::DataGenerator()
{
    try
    {

    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Constructor error!");
}

DataGenerator::~DataGenerator()
{
    try
    {

    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Destructor error!");
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// member function

std::string DataGenerator::getCurrentTime()
{
    try
    {
        time_t t;
        time(&t);
        struct tm *tmp_time = localtime(&t);
        char sTime[MAX_CANON];
        strftime(sTime, sizeof(sTime), "%04Y%02m%02d%H%M%S", tmp_time);
        return sTime;
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Get current time error!");
}

string DataGenerator::getName(int iVar, string sVar)
{
    try
    {
        string name = sVar + "_" + SSDK::FormatConvertion::intToString(iVar);
        return name;
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Get name error!");
}

bool DataGenerator::check(double centralX, double centralY,
                          double width, double height,
                          std::vector<MeasuredObj *> pObjs)
{
    try
    {
        for (uint i = 0; i < pObjs.size(); ++i)
        {
            if(abs(centralX - pObjs[i]->rectangle().centerPoint().posX()) < (width + pObjs[i]->rectangle().width())/2 &&
                    abs(centralY - pObjs[i]->rectangle().centerPoint().posY()) < (height + pObjs[i]->rectangle().height())/2)
            {
                return false;
            }
        }
        return true;
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Check error!");
}

void DataGenerator::generateBoardData(Board &board)
{
    try
    {
        //>>>-------------------------------------------------------------------
        //step1 加载元件配置文件

        QString dataSettingPath = "./config/DataGenerateSetting.ini"; //数据配置文件路径
        QSettings configFile(dataSettingPath, QSettings::IniFormat);
        m_dataSetting.load(dataSettingPath);


        //>>>-------------------------------------------------------------------
        //step2 从配置文件读取基板尺寸信息并设置到基板中

        string boardName = "Board";
        double boardWidth = configFile.value("BOARD/boardWidth").toDouble(); //基板宽
        double boardHeight = configFile.value("BOARD/boardHeight").toDouble(); //基板高
        double boardOriginX = configFile.value("BOARD/boardOriginX").toDouble(); //基板原点x坐标
        double boardOriginY = configFile.value("BOARD/boardOriginY").toDouble(); //基板原点y坐标

        board.name() = boardName;
        board.rectangle().setWidth(boardWidth);
        board.rectangle().setHeight(boardHeight);
        board.originPoint().setPosX(boardOriginX);
        board.originPoint().setPosY(boardOriginY);
        board.rectangle().centerPoint().setPosX((boardWidth-boardOriginX)/2);
        board.rectangle().centerPoint().setPosY((boardHeight-boardOriginY)/2);

        //>>>-------------------------------------------------------------------
        //step3 生成基板FicuicialMark数据

        //>>>-------------------------------------------------------------------
        //step3.1 定义FicuicialMark相关变量
        int measuredObjId = 0; //元件id
        int libraryId = 0; //库的序号
        int nameId = 0; //拼接检测目标的序号
        int mainItemId = 0; //mainItem的id全都设置为０（一个元件只有一个mainItem）
        int subItemId = 0; //subItemId的id全都设置为０（现在每个基准点只有一个subItem）
        string fiducialMarkName = "FiducialMark"; //基准点名字
        string libPrefix = "lib_"; //库的前缀
        int fiducialMarkCnt = configFile.value("FICUICIALMARK/fiducialMarkCnt").toInt(); //基准点个数
        double fiducialMarkWidth = configFile.value("FICUICIALMARK/fiducialMarkWidth").toDouble(); //基准点宽
        double fiducialMarkHeight = configFile.value("FICUICIALMARK/fiducialMarkHeight").toDouble(); //基准点高
        double fstFiducialMarkCenterX = configFile.value("FICUICIALMARK/firstFiducialMarkCenterX").toDouble(); //第一个基准点中心点x坐标
        double fstFiducialMarkCenterY = configFile.value("FICUICIALMARK/firstFiducialMarkCenterY").toDouble(); //第一个基准点中心点y坐标
        double sndFiducialMarkCenterX = configFile.value("FICUICIALMARK/secondFiducialMarkCenterX").toDouble(); //第二个基准点中心点x坐标
        double sndFiducialMarkCenterY = configFile.value("FICUICIALMARK/secondFiducialMarkCenterY").toDouble(); //第二个基准点中心点x坐标
        double fiducialMarkAngle = configFile.value("FICUICIALMARK/fiducialMarkAngle").toDouble(); //基准点角度
        int componentIdx = fiducialMarkCnt; //元件索引

        //>>>-------------------------------------------------------------------
        //step3.2 生成FicuicialMark的名字、序号等数据
        board.pObjs().push_back(new FiducialMark(measuredObjId++,
                                                 getName(nameId++,fiducialMarkName),
                                                 fstFiducialMarkCenterX,fstFiducialMarkCenterY,
                                                 fiducialMarkWidth,fiducialMarkHeight,
                                                 fiducialMarkAngle));


        board.pObjs().push_back(new FiducialMark(measuredObjId++,
                                                 getName(nameId++,fiducialMarkName),
                                                 sndFiducialMarkCenterX,sndFiducialMarkCenterY,
                                                 fiducialMarkWidth,fiducialMarkHeight,
                                                 fiducialMarkAngle));

        //>>>-------------------------------------------------------------------
        //step3.2 生成FicuicialMark的library数据
        for (int i = 0; i < fiducialMarkCnt; ++i)
        {
            //>>>---------------------------------------------------------------
            //step3.2.1 生成FiducialMark的library名字、序号等数据
            for (uint j = 0; j < board.pLibs().size(); ++j)
            {
                if( (board.pObjs()[i]->rectangle().width() == board.pLibs()[j]->mainItem().rectangle().width()) &&
                        (board.pObjs()[i]->rectangle().height() == board.pLibs()[j]->mainItem().rectangle().height()) )
                {
                    board.pObjs()[i]->setPLib(board.pLibs()[j]);
                }
            }
            if(nullptr == board.pObjs()[i]->pLib())
            {
                board.pObjs()[i]->setPLib(new Library);
                board.pObjs()[i]->pLib()->name() = libPrefix + fiducialMarkName;
                board.pLibs().push_back(board.pObjs()[i]->pLib());

                //>>>-----------------------------------------------------------
                //step3.2.2 生成FiducialMark的library的mainItem数据
                board.pObjs()[i]->pLib()->mainItem().setLibId(libraryId++);
                MainItem& mainItem = board.pObjs()[i]->pLib()->mainItem();
                mainItem.setId(mainItemId);
                mainItem.rectangle().setWidth(fiducialMarkWidth);
                mainItem.rectangle().setHeight(fiducialMarkHeight);
                mainItem.rectangle().centerPoint().setPosX(0);
                mainItem.rectangle().centerPoint().setPosY(0);
                mainItem.name() = board.pObjs()[i]->pLib()->name();
                mainItem.setPAlg(new Alg3D);

                //>>>-----------------------------------------------------------
                //step3.2.3 生成FiducialMark的library的subItem数据
                double subItemAngle = 0; //subItem的角度
                string subItemName = "subItem_" + fiducialMarkName + "1"; //subItem的名字,subItem只有１个
                double subItemWidth = SSDK::NumRandom::randomDouble(0,fiducialMarkWidth); //subItem的宽
                double subItemHeight = SSDK::NumRandom::randomDouble(0,fiducialMarkHeight); //subItem的长
                double subItemShiftX = SSDK::NumRandom::randomDouble(0,fiducialMarkWidth-subItemWidth/2);//subItem的X偏移
                double subItemShiftY = SSDK::NumRandom::randomDouble(0,fiducialMarkHeight-subItemHeight/2);//subItem的Y偏移

                board.pObjs()[i]->pLib()->subItems().push_back(SubItem());
                SubItem& subItem = board.pObjs()[i]->pLib()->subItems().back();
                subItem.setLibId(board.pObjs()[i]->pLib()->id());
                subItem.setId(subItemId);
                subItem.name() = subItemName;
                subItem.setPAlg(new Alg2D);
                subItem.rectangle().centerPoint().setPosX(subItemShiftX);
                subItem.rectangle().centerPoint().setPosY(subItemShiftY);
                subItem.rectangle().setHeight(subItemHeight);
                subItem.rectangle().setWidth(subItemWidth);
                subItem.rectangle().setAngle(subItemAngle);
                subItem.setOrder(i);
            }// end of if(nullptr == board.pObjs()[i]->pLib())
        }//end of for (int i = 0; i < fiducialMarkCnt; ++i)

        //>>>-------------------------------------------------------------------
        //step4 生成基板上元件信息

        //>>>-------------------------------------------------------------------
        //step4.1 定义元件相关变量
        int cycleCnt = 0; //循环次数
        double componentWidth = 0; //元件宽
        double componentHeight = 0; //元件长
        int componentTypeIdx = 0; //元件数据索引
        int perComponentTypeCnt = 0; //每种元件类型的数量
        double mainItemShiftXAndY = 0; //mainItem在x和y方向的偏移都是０（mainItem和component重合）
        string componentType=""; //元件类型
        string componentLibType=""; //元件库的类型
        double componentAngle = 0; //元件角度
        double componentCentralX = 0; //元件中心点x坐标
        double componentCentralY = 0; //元件中心点y坐标
        int chipCnt = configFile.value("chipCnt").toInt(); //chip类型的元件个数
        int otherPerComponentTypeCnt = configFile.value("otherComponentCnt").toInt(); //其他元件类型的个数

        //>>>-------------------------------------------------------------------
        //step4.2 生成所有所有的元件
        srand(time(NULL));
        //遍历元件大类的类型，比如CHIP,SOP,QFN等
        for (uint i = 0; i < this->m_dataSetting.componentTypesVector().size();++i)
        {
            //>>>---------------------------------------------------------------
            //step4.2.1 获取每个大类的元件数量
            if("CHIP"==(this->m_dataSetting.componentTypes()[i].toStdString()))
            {
                perComponentTypeCnt = chipCnt;
            }
            else
            {
                perComponentTypeCnt = otherPerComponentTypeCnt;
            }

            //>>>---------------------------------------------------------------
            //step4.2.2 生成所有元件，如果循环次数大于50000次默认已经不能生成合适的元件
            for (int j = 0; j < perComponentTypeCnt && cycleCnt < 50000;)
            {
                ++cycleCnt; //累加循环次数

                //在范围内随机生成元件中心点坐标
                componentCentralX = SSDK::NumRandom::randomDouble(boardOriginX+fiducialMarkWidth/2,boardWidth-fiducialMarkWidth/2);
                componentCentralY = SSDK::NumRandom::randomDouble(boardOriginY+fiducialMarkWidth/2,boardHeight-fiducialMarkHeight/2);

                //随机生成元件类型索引，比如在QFN大类下有四个小类元件类型索引０－３
                componentTypeIdx = SSDK::NumRandom::randomInt(0,(this->m_dataSetting.componentTypesVector()[i])->size());

                //记录元件长宽
                componentWidth = (this->m_dataSetting.componentTypesVector()[i])->at(componentTypeIdx).width;
                componentHeight = (this->m_dataSetting.componentTypesVector()[i])->at(componentTypeIdx).height;

                //>>>-----------------------------------------------------------
                //step4.2.2.1 生成符合要求的元件
                //检测生成数据的是否符合要求
                if(check(componentCentralX,componentCentralY,
                         componentWidth,
                         (this->m_dataSetting.componentTypesVector()[i])->at(componentTypeIdx).height,
                         board.pObjs()))
                {
                    //>>>-------------------------------------------------------
                    //step4.2.2.1.1 生成元件名字、序等信息
                    componentType = (this->m_dataSetting.componentTypesVector()[i])->at(componentTypeIdx).componentName.toStdString();
                    board.pObjs().push_back(new Component(measuredObjId++,
                                                          getName(nameId++,componentType),
                                                          componentCentralX,
                                                          componentCentralY,
                                                          componentAngle,
                                                          componentWidth,
                                                          componentHeight));

                    //>>>-------------------------------------------------------
                    //step4.2.2.1.2 生成元件的library的名字序号等信息
                    componentLibType = libPrefix + componentType;
                    for (uint k = 0; k < board.pLibs().size(); ++k)
                    {
                        if((abs(componentWidth - board.pLibs()[k]->mainItem().rectangle().width()) < 0.005) &&
                                (abs(componentHeight - board.pLibs()[k]->mainItem().rectangle().height()) < 0.005))
                        {
                            board.pObjs()[componentIdx]->setPLib(board.pLibs()[k]);
                            break;
                        }
                    }

                    if(nullptr == board.pObjs()[componentIdx]->pLib())
                    {
                        board.pObjs()[componentIdx]->setPLib(new Library);
                        board.pObjs()[componentIdx]->pLib()->name() = componentLibType;
                        board.pObjs()[componentIdx]->pLib()->setId(libraryId++);
                        board.pLibs().push_back(board.pObjs()[componentIdx]->pLib());

                        //>>>---------------------------------------------------
                        //step4.2.2.3 生成元件的library的mainItem信息
                        MainItem& item = board.pObjs()[componentIdx]->pLib()->mainItem();
                        item.setLibId(board.pObjs()[componentIdx]->pLib()->id());
                        item.setId(0);
                        item.rectangle().setWidth(componentWidth);
                        item.rectangle().setHeight(componentHeight);
                        item.rectangle().centerPoint().setPosX(mainItemShiftXAndY);
                        item.rectangle().centerPoint().setPosY(mainItemShiftXAndY);
                        item.name() = componentLibType;
                        item.setPAlg(new Alg3D);
                    }
                    componentIdx++; //累计偏移
                    ++j; //数据生成成功计数
                }//end of if(check(...))
            }//end of for (int j = 0; j < perComponentTypeCnt && cycleCnt < 50000;)
        }//end of for (uint i = 0; i < this->m_dataSetting.componentTypesVector().size();++i)
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("生成基板数据出错");
}

void DataGenerator::generateInspectionData(InspectionData &inspectionData)
{
    try
    {
        generateBoardData(inspectionData.board()); //生成基板信息
        string version = "v1"; //版本设为v1
        inspectionData.version() = version;
        inspectionData.lastEditingTime() = getCurrentTime(); //设置当前时间为上次编辑的时间
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("生成检测数据出错");
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
