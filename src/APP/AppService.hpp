#ifndef APPSERVICE_HPP
#define APPSERVICE_HPP

#include <iostream>

#include "PathSetting.hpp"
#include "AppSetting.hpp"

namespace APP
{
    /**
     *  @brief AppSerivice
     *          该类是App层参数设置的类,
     *              例如:1.设置软件主题,语言等
     *                  2.配置文件的路径等
     *  @author peter
     *  @version 1.00 2018-01-05 peter
     *                note:create it
     */
    class AppService
    {
    public:

        //>>>-------------------------------------------------------------------
        // constructor & destructor

        AppService();

        virtual ~AppService();

        //>>>-------------------------------------------------------------------
        // set & get function

        QString& pathSettingPath(){return this->m_pathSettingPath;}

        PathSetting& pathSetting(){return this->m_pathSetting;}

        AppSetting& appSetting(){return this->m_appSetting;}

        //>>>-------------------------------------------------------------------
        // member function

        /**
         * @brief init
         *      加载存放路径的配置文件，初始化类的成员变量
         *       1.加载存放路径的配置文件
         *       2.加载软件界面需要的配置文件
         * @param N/A
         * @return N/A
         */
        void init();


    private:

        //>>>-------------------------------------------------------------------
        // member variant

        QString m_pathSettingPath {""};   // 存放各路径的配置文件路径
        PathSetting m_pathSetting;        // 路径配置文件中的配置信息
        AppSetting m_appSetting;          // 软件运行界面的配置信息

        //<<<-------------------------------------------------------------------

    };
}// End of namespace APP

#endif // APPSERVICE_HPP
