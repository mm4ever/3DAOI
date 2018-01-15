#ifndef UIMANAGE_HPP
#define UIMANAGE_HPP

#include <iostream>
#include <string>
#include <cstring>

#include "StartupWnd.hpp"
#include "LoginWnd.hpp"
#include "MainWnd.hpp"
#include "CustomException.hpp"

namespace APP
{
    /**
     *  @brief UIManager
     *          UIManager类组合了开始界面、登录界面、主界面
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
        // set & get function

        LoginWnd& loginWnd(){return this->m_pLoginWnd;}

        //>>>-------------------------------------------------------------------
        // member function

        /**
         * @brief init
         *      初始化类的成员变量
         * @param N/A
         * @return N/A
         */
        void init();

        /**
         * @brief run
         *      运行程序,依次显示启动界面,登录界面和主界面
         * @param N/A
         * @return N/A
         */
        void run();


    private:

        //>>>-------------------------------------------------------------------
        // member variant

        StartupWnd m_pStartupWnd;       // 启动界面
        LoginWnd m_pLoginWnd;           // 登录界面
        MainWnd m_pMainWnd;             // 主界面

        //<<<-------------------------------------------------------------------

    };
}// End of namespace APP


#endif // UIMANAGE_HPP
