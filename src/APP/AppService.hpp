#ifndef APPSERVICE_HPP
#define APPSERVICE_HPP

#include <iostream>

#include "PathSetting.hpp"
#include "AppSetting.hpp"

namespace APP
{
    /**
     *  @brief AppSerivice
     *
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
        // member function

        void init();


    private:

        //>>>-------------------------------------------------------------------
        // member variant

        std::string m_pathSettingPath {""};
        PathSetting m_pathSetting;
        AppSetting m_appSetting;

        //<<<-------------------------------------------------------------------

    };
}// End of namespace APP

#endif // APPSERVICE_HPP
