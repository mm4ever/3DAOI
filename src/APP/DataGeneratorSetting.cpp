#include "DataGeneratorSetting.hpp"

using namespace std;

using namespace APP;

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constructor & destructor

DataGeneratorSetting::DataGeneratorSetting()
{
    try
    {

    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Constructor error!");
}

DataGeneratorSetting::~DataGeneratorSetting()
{
    try
    {
        int componentTypeCnt = this->m_componentTypesVector.size();
        for (int i = 0 ; i < componentTypeCnt ; ++i )
        {
            if (nullptr != this->m_componentTypesVector[i])
            {
                delete this->m_componentTypesVector[i];
                this->m_componentTypesVector[i] = nullptr;
            }
        }
    }
    catch(...)
    {
        int componentTypeCnt = this->m_componentTypesVector.size();
        for (int i = 0 ; i < componentTypeCnt ; ++i )
        {
            if (nullptr != this->m_componentTypesVector[i])
            {
                delete this->m_componentTypesVector[i];
                this->m_componentTypesVector[i] = nullptr;
            }
        }
    }
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// member function

void DataGeneratorSetting::load(const QString &path)
{
    try
    {
        //>>>-------------------------------------------------------------------
        //step1　判断路径下有没有文件，有则把数据存入到相关vector中，没有生成默认配置文件存到vector中
        if(!QFile::exists(path))
        {
            writeDefaultSettingFile(path);
        }

        QSettings settings(path, QSettings::IniFormat);
        vector<ComponentStyle> *pComponentType;

        //>>>-------------------------------------------------------------------
        //step2 几种大类的元件类型存到vector中，例如CHIP,SOP
        int componentTypeCnt = settings.beginReadArray("COMPONENT_TYPE");
        QString str;
        for (int i = 0; i < componentTypeCnt; ++i)
        {
            settings.setArrayIndex(i);
            str = settings.value("componentType").toString();
            this->m_componentTypes.push_back(str);
        }
        settings.endArray();

        //>>>-------------------------------------------------------------------
        //step3 为每个类型的元件创建一个vector,比如一个CHIP大类是一个vector
        ComponentStyle component;
        int componentCnt=0;
        for (int i = 0; i < componentTypeCnt; ++i)
        {
            componentCnt = settings.beginReadArray(this->m_componentTypes[i]);
            pComponentType = new vector<ComponentStyle>;
            for (int i = 0; i < componentCnt; ++i)
            {
                settings.setArrayIndex(i);
                component.componentName = settings.value("componentName").toString();
                component.width = settings.value("width").toDouble();
                component.height = settings.value("height").toDouble();
                pComponentType->push_back(component);
            }
            this->m_componentTypesVector.push_back(pComponentType);
            settings.endArray();
        }
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Load config file error!");
}

void DataGeneratorSetting::writeDefaultSettingFile(const QString &path)
{
    try
    {
        QSettings settings(path, QSettings::IniFormat);

        //>>>-------------------------------------------------------------------
        //step1 设置chip类原件和其他类型元件个数
        settings.setValue("chipCnt",500);
        settings.setValue("otherComponentCnt",100);

        //>>>-------------------------------------------------------------------
        //step2 设置board信息
        settings.setValue("BOARD/boardWidth",510.00);
        settings.setValue("BOARD/boardHeight",510.00);
        settings.setValue("BOARD/boardOriginX",0.0);
        settings.setValue("BOARD/boardOriginY",0.0);

        //>>>-------------------------------------------------------------------
        //step3 设置fiducialMark信息
        settings.setValue("FICUICIALMARK/fiducialMarkCnt",2);
        settings.setValue("FICUICIALMARK/fiducialMarkWidth",4.0);
        settings.setValue("FICUICIALMARK/fiducialMarkHeight",4.0);
        settings.setValue("FICUICIALMARK/firstFiducialMarkCenterX",2.0);
        settings.setValue("FICUICIALMARK/firstFiducialMarkCenterY",2.0);
        settings.setValue("FICUICIALMARK/secondFiducialMarkCenterX",508.0);
        settings.setValue("FICUICIALMARK/secondFiducialMarkCenterY",508.0);
        settings.setValue("FICUICIALMARK/fiducialMarkAngle",0);

        //>>>-------------------------------------------------------------------
        //step4 设置元件类型（大类）
        vector<QString> componentTypes;
        componentTypes.push_back("CHIP");
        componentTypes.push_back("SOP");
        componentTypes.push_back("SOT");
        componentTypes.push_back("QFN");
        componentTypes.push_back("QFP");
        componentTypes.push_back("BGA");
        settings.beginWriteArray("COMPONENT_TYPE");
        for (uint i = 0; i < componentTypes.size(); ++i)
        {
            settings.setArrayIndex(i);
            settings.setValue("componentType", componentTypes[i]);
        }
        settings.endArray();

        //>>>-------------------------------------------------------------------
        //step5 设置元件类型（小类）把相关数据存到vector中，一次写入到配置文件
        vector<ComponentStyle> CHIP,SOP,SOT,QFN,QFP,BGA;
        ComponentStyle chip,ic;

        //chip类
        chip.componentName = "chip01005";
        chip.width = 0.4;
        chip.height = 0.2;
        CHIP.push_back(chip);

        chip.componentName = "chip0201";
        chip.width = 0.6;
        chip.height = 0.3;
        CHIP.push_back(chip);

        chip.componentName = "chip0402";
        chip.width = 1.0;
        chip.height = 0.5;
        CHIP.push_back(chip);

        chip.componentName = "chip0603";
        chip.width = 1.6;
        chip.height = 0.8;
        CHIP.push_back(chip);

        chip.componentName = "chip0805";
        chip.width = 2.0;
        chip.height = 1.25;
        CHIP.push_back(chip);

        chip.componentName = "chip1206";
        chip.width = 3.2;
        chip.height = 1.6;
        CHIP.push_back(chip);

        //ic类
        ic.componentName = "SOP8";
        ic.width = 6.0;
        ic.height = 5.0;
        SOP.push_back(ic);

        ic.componentName = "SOP14";
        ic.width = 6.0;
        ic.height = 8.5;
        SOP.push_back(ic);

        ic.componentName = "SOP16";
        ic.width = 6.0;
        ic.height = 10.0;
        SOP.push_back(ic);

        ic.componentName = "SOP18";
        ic.width = 10.3;
        ic.height = 11.5;
        SOP.push_back(ic);

        ic.componentName = "SOP20";
        ic.width = 10.3;
        ic.height = 12.7;
        SOP.push_back(ic);

        ic.componentName = "SOP24";
        ic.width = 10.3;
        ic.height = 15.4;
        SOP.push_back(ic);

        ic.componentName = "SOP28";
        ic.width = 10.3;
        ic.height = 17.7;
        SOP.push_back(ic);

        ic.componentName = "SOP30";
        ic.width = 10.3;
        ic.height = 19.0;
        SOP.push_back(ic);

        ic.componentName = "SOT363";
        ic.width = 2.1;
        ic.height = 2.3;
        SOT.push_back(ic);

        ic.componentName = "SOT353";
        ic.width = 2.1;
        ic.height = 2.3;
        SOT.push_back(ic);

        ic.componentName = "SOT23";
        ic.width = 2.1;
        ic.height = 2.9;
        SOT.push_back(ic);

        ic.componentName = "SOT323";
        ic.width = 2.1;
        ic.height = 2.1;
        SOT.push_back(ic);

        ic.componentName = "SOT552";
        ic.width = 5.0;
        ic.height = 3.0;
        SOT.push_back(ic);

        ic.componentName = "SOT663";
        ic.width = 1.6;
        ic.height = 1.6;
        SOT.push_back(ic);

        ic.componentName = "SOT666";
        ic.width = 1.6;
        ic.height = 1.6;
        SOT.push_back(ic);

        ic.componentName = "QFN24";
        ic.width = 4.0;
        ic.height = 4.0;
        QFN.push_back(ic);

        ic.componentName = "QFN32";
        ic.width = 5.0;
        ic.height = 5.0;
        QFN.push_back(ic);

        ic.componentName = "QFN28";
        ic.width = 5.0;
        ic.height = 5.0;
        QFN.push_back(ic);

        ic.componentName = "QFN48";
        ic.width = 5.0;
        ic.height = 5.0;
        QFN.push_back(ic);

        ic.componentName = "QFP44";
        ic.width = 13.5;
        ic.height = 13.5;
        QFP.push_back(ic);

        ic.componentName = "QFP52";
        ic.width = 17.2;
        ic.height = 17.2;
        QFP.push_back(ic);

        ic.componentName = "QFP64";
        ic.width = 17.2;
        ic.height = 17.2;
        QFP.push_back(ic);

        ic.componentName = "LQFP32";
        ic.width = 9.0;
        ic.height = 9.0;
        QFP.push_back(ic);

        ic.componentName = "LQFP44";
        ic.width = 12.0;
        ic.height = 12.0;
        QFP.push_back(ic);

        ic.componentName = "LQFP48";
        ic.width = 9.0;
        ic.height = 9.0;
        QFP.push_back(ic);

        ic.componentName = "LQFP64";
        ic.width = 9.0;
        ic.height = 9.0;
        QFP.push_back(ic);

        ic.componentName = "LQFP80";
        ic.width = 14.0;
        ic.height = 14.0;
        QFP.push_back(ic);

        ic.componentName = "LQFP100";
        ic.width = 16.0;
        ic.height = 16.0;
        QFP.push_back(ic);

        ic.componentName = "LQFP128";
        ic.width = 16.0;
        ic.height = 16.0;
        QFP.push_back(ic);

        ic.componentName = "BGA40";
        ic.width = 5.0;
        ic.height = 5.0;
        BGA.push_back(ic);

        ic.componentName = "BGA56";
        ic.width = 6.0;
        ic.height = 6.0;
        BGA.push_back(ic);

        ic.componentName = "BGA84";
        ic.width = 7.0;
        ic.height = 7.0;
        BGA.push_back(ic);

        ic.componentName = "BGA96";
        ic.width = 8.0;
        ic.height = 8.0;
        BGA.push_back(ic);

        ic.componentName = "BGA132";
        ic.width = 8.0;
        ic.height = 8.0;
        BGA.push_back(ic);

        ic.componentName = "BGA484";
        ic.width = 12.0;
        ic.height = 12.0;
        BGA.push_back(ic);

        settings.beginWriteArray("CHIP");
        for (uint i = 0; i < CHIP.size(); ++i)
        {
            settings.setArrayIndex(i);
            settings.setValue("componentName", CHIP.at(i).componentName);
            settings.setValue("width", CHIP.at(i).width);
            settings.setValue("height", CHIP.at(i).height);
        }
        settings.endArray();
        settings.beginWriteArray("SOP");
        for (uint i = 0; i < SOP.size(); ++i)
        {
            settings.setArrayIndex(i);
            settings.setValue("componentName", SOP.at(i).componentName);
            settings.setValue("width", SOP.at(i).width);
            settings.setValue("height", SOP.at(i).height);
        }
        settings.endArray();

        settings.beginWriteArray("SOT");
        for (uint i = 0; i < SOT.size(); ++i)
        {
            settings.setArrayIndex(i);
            settings.setValue("componentName", SOT.at(i).componentName);
            settings.setValue("width", SOT.at(i).width);
            settings.setValue("height", SOT.at(i).height);
        }
        settings.endArray();

        settings.beginWriteArray("QFN");
        for (uint i = 0; i < QFN.size(); ++i)
        {
            settings.setArrayIndex(i);
            settings.setValue("componentName", QFN.at(i).componentName);
            settings.setValue("width", QFN.at(i).width);
            settings.setValue("height", QFN.at(i).height);
        }
        settings.endArray();

        settings.beginWriteArray("QFP");
        for (uint i = 0; i < QFP.size(); ++i)
        {
            settings.setArrayIndex(i);
            settings.setValue("componentName", QFP.at(i).componentName);
            settings.setValue("width", QFP.at(i).width);
            settings.setValue("height", QFP.at(i).height);
        }
        settings.endArray();

        settings.beginWriteArray("BGA");
        for (uint i = 0; i < BGA.size(); ++i)
        {
            settings.setArrayIndex(i);
            settings.setValue("componentName", BGA.at(i).componentName);
            settings.setValue("width", BGA.at(i).width);
            settings.setValue("height", BGA.at(i).height);
        }
        settings.endArray();
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Create default config file error!");
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
