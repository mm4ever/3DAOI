#ifndef APPSETTING_HPP
#define APPSETTING_HPP

#include <iostream>

namespace APP
{

    /**
     * @brief The MachineName enum
     *      机器名称
     */
    enum class MachineName
    {
        AOI,    // 自动光学检测设备
        SPI     // 锡膏检测设备
    };
    /**
     * @brief The Theme enum
     *      机器软件界面使用的主题
     */
    enum class Theme
    {
        BLACK,      // 黑色主题
        WHITE       // 白色主题
    };
    /**
     * @brief The Language enum
     *      机器软件界面使用的语言
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
        // member function

        void load(std::string& appPath);


    private:

        //>>>-------------------------------------------------------------------
        // member variant

        std::string m_companyName {""};             // 公司名称
        std::string m_machineName {""};             // 机器名称
        Theme m_theme {Theme::BLACK};               // 软件主题
        Language m_lang {Language::CN};             // 软件语言
        LaneMode m_laneMode {LaneMode::DUAL_LANE};  // 软件运行的模式

        //<<<-------------------------------------------------------------------

    };
}// End of namesapce APP

#endif // APPSETTING_HPP
