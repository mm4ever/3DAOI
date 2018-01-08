#ifndef UIMANAGE_HPP
#define UIMANAGE_HPP

#include "MainWnd.hpp"
#include "LoginWnd.hpp"
#include "StartupWnd.hpp"
#include "CustomException.hpp"

namespace APP
{
    /**
     *  @brief UIManager
     *          UIManager类组合了登录界面、开始界面、主界面
     *  软件运行时,依次运行以上三个界面,通过init()函数进行类成员的初始化.
     *
     *  @author peter
     *  @version 1.00 2018-01-06 peter
     *                note:create it
     */
    class UIManager
    {
    public:

        //>>>-------------------------------------------------------------------
        // constructor & destructor

        UIManager();
        virtual~UIManager();

        //>>>-------------------------------------------------------------------
        // member function

        /**
         * @brief init
         *      初始化类的成员变量
         * @param N/A
         * @return N/A
         */
        void init();


    private:

        //>>>-------------------------------------------------------------------
        // member variant

        LoginWnd m_loginWnd;
        StartupWnd m_startupWnd;
        MainWnd m_mainWnd;

        //<<<-------------------------------------------------------------------

    };
}// End of namespace APP


#endif // UIMANAGE_HPP
