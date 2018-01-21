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

    enum class MachineType
    {
        AOI,            //设备的检测类型为检测电路板上的元器件
        SPI             //设备的检测类型为检测电路板上的锡膏
    };

    /**
     *  @brief AppSetting
     *          AppSetting类是软件应用层的基本属性设置,如设置软件的主题,语言等
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

        virtual ~AppSetting();

        //>>>-------------------------------------------------------------------
        // get & set function

        QString& companyName(){return this->m_companyName;}

        MachineType& machineType(){return this->m_machineType;}

        Theme& theme(){return this->m_theme;}

        Language& language(){return this->m_language;}

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
        // 机器的类型,AOI为检测电路板上的元器件,SPI为检测电路板上的锡膏
        MachineType m_machineType {MachineType::AOI};
        Theme m_theme {Theme::BLACK};               // 软件主题
        Language m_language {Language::CN};         // 软件语言
        LaneMode m_laneMode {LaneMode::SIMULATOR};  // 机器种类

        //<<<-------------------------------------------------------------------

    };
}// End of namesapce APP

#endif // APPSETTING_HPP
