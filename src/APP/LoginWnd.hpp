#ifndef LOGINWND_HPP
#define LOGINWND_HPP

#include <iostream>
#include <string>

#include <QFile>
#include <QSettings>

#include "GlobalVariable.hpp"
#include "CustomException.hpp"

namespace APP
{
    /**
     *  @brief LoginWnd
     *          LoginWnd类是显示登录界面的类
     *  输入账户名,正确则继续输入密码,不正确则重新输入账户名.
     *
     *  @author peter
     *  @version 1.00 2018-01-06 peter
     *                note:create it
     */
    class LoginWnd
    {
    public:

        //>>>-------------------------------------------------------------------
        // constructor & destructor

        LoginWnd();
        virtual~LoginWnd();

        //>>>-------------------------------------------------------------------
        // member function

        /**
         * @brief run
         *      运行登录界面
         *  输入用户名: 用户名正确: 输入密码:
         *                          密码正确:登录成功
         *                          密码错误:返回继续输入用户名
         *              用户名错误:返回继续输入用户名
         *
         * @param N/A
         * @return N/A
         */
        void run();

       //<<<-------------------------------------------------------------------
    };
}// End of namespace APP

#endif // LOGINWND_HPP
