#ifndef APPSETTING_HPP
#define APPSETTING_HPP

#include <iostream>

#include <QFile>
#include <QSettings>

#include "CustomException.hpp"
#include "FormatConvertor.hpp"

namespace APP
{

    /**
     * @brief The Theme enum
     *      软件界面使用的主题
     */
    enum class Theme
    {
        BLACK,      // 黑色主题
        WHITE       // 白色主题
    };
    /**
     * @brief The Language enum
     *      软件界面使用的语言
     */
    enum class Language
    {
        EN,         // 英文
        CN          // 中文
    };
    /**
     * @brief The LaneMode enum
     *      机器种类
     */
    enum class LaneMode
    {
        SIMULATOR,      // 模拟器,模拟机器运行的电脑
        SINGLE_LANE,    // 单轨机,只有一条轨道的机器
        DUAL_LANE       // 双轨机,有两条轨道的机器
    };

    /**
     *  @brief AppSetting
     *          AppSetting类是存放配置文件的类,配置文件包括主题、语言等
     *      不是程序运行时所必需的配置;如果不存在则直接创建默认的配置,存在则判
     *      断配置是否正确,不正确则使用默认参数.
     *
     *  @author peter
     *  @version 1.00 2018-01-06 peter
     *                note:create it
     */
    class AppSetting
    {
    public:

        //>>>-------------------------------------------------------------------
        // constructor & destructor

        AppSetting();
        virtual~AppSetting();

        //>>>-------------------------------------------------------------------
        // get & set function

        void setCompanyName(QString companyName)
        {
            this->m_companyName = companyName;
        }
        QString& companyName(){return this->m_companyName;}

        void setMachineName(QString machineName)
        {
            this->m_machineName = machineName;
        }
        QString& machineName(){return this->m_machineName;}

        void setTheme(Theme theme){ this->m_theme = theme;}
        Theme& theme(){return this->m_theme;}

        void setLanguage(Language lang){ this->m_language = lang;}
        Language& language(){return this->m_language;}

        void setLaneMode(LaneMode laneMode){ this->m_laneMode = laneMode;}
        LaneMode& laneMode(){return this->m_laneMode;}



        //>>>-------------------------------------------------------------------
        // member function

        /**
         *  @brief load
         *      该函数功能是读取配置文件中的信息
         *  @param appPath
         *      待读取的配置文件路径
         *  @return N/A
         */
        void load(const QString& appPath);


    private:

        //>>>-------------------------------------------------------------------
        // member variant

        QString m_companyName {"Sung"};             // 公司名称
        QString m_machineName {"SPI"};              // 机器名称
        Theme m_theme {Theme::BLACK};               // 软件主题
        Language m_language {Language::CN};         // 软件语言
        LaneMode m_laneMode {LaneMode::SIMULATOR};  // 机器种类

        //<<<-------------------------------------------------------------------

    };
}// End of namesapce APP

#endif // APPSETTING_HPP
