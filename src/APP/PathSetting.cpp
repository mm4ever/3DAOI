#include "PathSetting.hpp"

using namespace APP;

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constructor & destructor

PathSetting::PathSetting()
{
    try
    {
        this->m_appSettingPath = "./config/AppSetting.ini";
        this->m_exportXmlPath = "../data/xml/ExportXml.ini";
        this->m_defaultJobFolderPath = "../data/job/";
        this->m_inspectionSettingPath = "./config/InspectionSetting.ini";
        this->m_userAccountPath = "./config/UserAccount.ini";
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Constructor error!");
}

PathSetting::~PathSetting()
{
    try
    {

    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Destructor error!");
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
            this->m_exportXmlPath = configFile.value("ExportXmlPath").toString();

            //>>>---------------------------------------------------------------
            // step2.3 加载DefaultJobFolderPath
            this->m_defaultJobFolderPath = configFile.value("DefaultJobFolderPath").toString();

            //>>>---------------------------------------------------------------
            // step2.4 加载InspectionSettingPath
            this->m_inspectionSettingPath = configFile.value("InspectionSettingPath").toString();

            //>>>---------------------------------------------------------------
            // step2.5 加载RegistrationInfoPath
            this->m_userAccountPath = configFile.value("UserAccountPath").toString();

        }
        else
        {
            // 没有配置文件则写入默认配置
            QSettings configFile(path,QSettings::IniFormat);

            configFile.setValue("AppSettingPath",m_appSettingPath );
            configFile.setValue("ExportXmlPath",m_exportXmlPath);
            configFile.setValue("DefaultJobFolderPath",m_defaultJobFolderPath);
            configFile.setValue("InspectionSettingPath",m_inspectionSettingPath);
            configFile.setValue("UserAccountPath",m_userAccountPath);
        }
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Load config file error!");
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
