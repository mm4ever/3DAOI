#ifndef APPSERVICE_HPP
#define APPSERVICE_HPP

#include <iostream>

#include "PathSetting.hpp"
#include "AppSetting.hpp"

namespace APP
{
    /**
     *  @brief AppSerivice
     *      该类存放了pathSettingPath路径和各配置的类
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
        virtual~AppService();

        //>>>-------------------------------------------------------------------
        // set & get function

        void setPathSettingPath(QString& path)
        {
            this->m_pathSettingPath = path;
        }
        QString pathSettingPaht(){return this->m_pathSettingPath;}

        void setPathSetting(PathSetting& pathSetting)
        {
            this->m_pathSetting = pathSetting;
        }
        PathSetting pathSetting(){return this->m_pathSetting;}

        void setAppSetting(AppSetting& appSetting)
        {
            this->m_appSetting = appSetting;
        }
        AppSetting appSetting(){return this->m_appSetting;}

        //>>>-------------------------------------------------------------------
        // member function

        /**
         * @brief init
         *      加载存放路径的配置文件，初始化类的成员变量
         *  1.加载存放路径的配置文件
         *  2.加载软件界面需要的配置文件
         * @param N/A
         * @return N/A
         */
        void init();


    private:

        //>>>-------------------------------------------------------------------
        // member variant

        QString m_pathSettingPath {""};
        PathSetting m_pathSetting;
        AppSetting m_appSetting;

        //<<<-------------------------------------------------------------------

    };
}// End of namespace APP

#endif // APPSERVICE_HPP
