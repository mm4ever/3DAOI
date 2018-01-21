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
     *          UIManager类负责调度软件UI界面的类
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

        LoginWnd& loginWnd(){return this->m_loginWnd;}

        StartupWnd& startupWnd(){return this->m_startupWnd;}

        MainWnd& mainWnd(){return this->m_mainWnd;}
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

        StartupWnd m_startupWnd;       // 启动界面
        LoginWnd m_loginWnd;           // 登录界面
        MainWnd m_mainWnd;             // 主界面

        //<<<-------------------------------------------------------------------

    };
}// End of namespace APP


#endif // UIMANAGE_HPP
