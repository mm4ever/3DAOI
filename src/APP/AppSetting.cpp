#include "AppSetting.hpp"

using namespace std;

using namespace APP;

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constructor & destructor

AppSetting::AppSetting()
{
    try
    {
        this->m_companyName = "Sung";
        this->m_machineName = "SPI" ;
        this->m_theme = Theme::BLACK ;
        this->m_language = Language::CN ;
        this->m_laneMode = LaneMode::SIMULATOR ;
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Constructor error!");
}

AppSetting::~AppSetting()
{

}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// member function

void AppSetting::load(const QString& appPath)
{
    try
    {
        //>>>-------------------------------------------------------------------
        // step1
        if(QFile::exists(appPath))  // 加载配置文件
        {
            QSettings configFile(appPath,QSettings::IniFormat);

            //>>>---------------------------------------------------------------
            // step2.1 加载CompanyName
            this->m_companyName = configFile.value("Company").toString();

            //>>>---------------------------------------------------------------
            // step2.2 加载MachineName
            this->m_machineName = configFile.value("Machine").toString();

            //>>>---------------------------------------------------------------
            // step2.3 加载Theme
            QString theme = configFile.value("Theme").toString();
            if( theme.toUpper().toStdString() == VAR_TO_STR(Theme::BLACK) )
            {
                this->m_theme = Theme::BLACK;
            }
            else if (theme.toUpper().toStdString() != VAR_TO_STR(Theme::WHITE))
            {
                this->m_theme = Theme::WHITE;
            }
            else
            {
                auto theme = VAR_TO_STR(Theme::BLACK);
                configFile.setValue("Theme",theme.c_str());
                this->m_theme = Theme::BLACK;
            }

            //>>>---------------------------------------------------------------
            //step2.4 加载Language
            QString lang = configFile.value("Language").toString();
            if(lang.toUpper().toStdString() == VAR_TO_STR(Lang::CN))
            {
                this->m_language = Language::CN;
            }
            else if ( lang.toUpper().toStdString() == VAR_TO_STR(Lang::EN) )
            {
                this->m_language = Language::EN;
            }
            else
            {
                auto lang = VAR_TO_STR(Language::CN);
                configFile.setValue("Language",lang.c_str());
                this->m_language = Language::CN;
            }

            //>>>---------------------------------------------------------------
            //step2.5 加载LaneMode
            QString laneMode = configFile.value("LaneMode").toString();
            auto loadLaneMode = laneMode.toUpper().toStdString();
            if( loadLaneMode == VAR_TO_STR(LaneMode::SIMULATOR))
            {
                this->m_laneMode = LaneMode::SIMULATOR;
            }
            else if (loadLaneMode == VAR_TO_STR(LaneMode::SINGLE_LANE))
            {
                this->m_laneMode = LaneMode::SINGLE_LANE;
            }
            else if(loadLaneMode == VAR_TO_STR(LaneMode::DUAL_LANE))
            {
                this->m_laneMode = LaneMode::DUAL_LANE;
            }
            else
            {
                auto laneMode = VAR_TO_STR(LaneMode::DUAL_LANE);
                configFile.setValue("LaneMode",laneMode.c_str());
                this->m_laneMode = LaneMode::DUAL_LANE;
            }
        }
        else
        {
            // 没有配置文件则写入默认配置
            QSettings configFile(appPath,QSettings::IniFormat);

            configFile.setValue( "Company",m_companyName);
            configFile.setValue( "Machine",m_machineName);
            configFile.setValue( "Theme",
                                 QString::fromStdString(VAR_TO_STR(Theme::BLACK)) );
            configFile.setValue( "Language",
                                  QString::fromStdString(VAR_TO_STR(Language::EN)) );
            configFile.setValue( "LaneMode",
                                 QString::fromStdString(VAR_TO_STR(LaneMode::DUAL_LANE)) );
        }
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Load config file error!");
}


//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

