#include "PathSetting.hpp"

using namespace APP;

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constructor & destructor

PathSetting::PathSetting()
{
    try
    {
        this->m_appSettingPath = "./config/AppSetting.ini";
        this->m_lotInfoPath = "./config/LotInfo.ini";
        this->m_defaultJobFolderPath = "./config/DefaultJobFolder.ini";
        this->m_inspectionSettingPath = "./config/InspectionSetting.ini";
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Constructor error!");
}

PathSetting::~PathSetting()
{

}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// member function

void PathSetting::load(const QString& path)
{
    try
    {
        if(QFile::exists(path))  // 加载配置文件
        {
            QSettings configFile(path,QSettings::IniFormat);

            //>>>---------------------------------------------------------------
            // step2.1 加载AppSettingPath
            this->m_appSettingPath = configFile.value("AppSettingPath").toString();

            //>>>---------------------------------------------------------------
            // step2.2 加载LotInfoPath
            this->m_lotInfoPath = configFile.value("LotInfoPath").toString();

            //>>>---------------------------------------------------------------
            // step2.3 加载DefaultJobFolderPath
            this->m_defaultJobFolderPath = configFile.value("DefaultJobFolderPath").toString();

            //>>>---------------------------------------------------------------
            // step2.4 加载InspectionSettingPath
            this->m_inspectionSettingPath = configFile.value("InspectionSettingPath").toString();

        }
        else
        {
            // 没有配置文件则写入默认配置
            QSettings configFile(path,QSettings::IniFormat);

            configFile.setValue("AppSettingPath",m_appSettingPath );
            configFile.setValue("LotInfoPath",m_lotInfoPath);
            configFile.setValue("DefaultJobFolderPath",m_defaultJobFolderPath);
            configFile.setValue("InspectionSettingPath",m_inspectionSettingPath);
        }
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Load config file error!");
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
