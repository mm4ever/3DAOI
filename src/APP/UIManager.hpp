#ifndef UIMANAGE_HPP
#define UIMANAGE_HPP

#include "MainWnd.hpp"
#include "LoginWnd.hpp"
#include "StartupWnd.hpp"

namespace APP
{
    class UiManager
    {
    public:

        //>>>-------------------------------------------------------------------
        // constructor & destructor

        UiManager();
        virtual~UiManager();

        //>>>-------------------------------------------------------------------
        // member function

        void init();


    private:

        //>>>-------------------------------------------------------------------
        // member variant

        MainWnd m_mainWnd;
        LoginWnd m_loginWnd;
        StartupWnd m_startupWnd;

        //<<<-------------------------------------------------------------------

    };
}// End of namespace APP


#endif // UIMANAGE_HPP
