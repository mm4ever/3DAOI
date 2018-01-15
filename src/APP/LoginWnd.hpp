#ifndef LOGINWND_HPP
#define LOGINWND_HPP

#include <iostream>
#include <string>
#include <cstring>

#include <QFile>
#include <QSettings>

#include "GlobalVariable.hpp"
#include "CustomException.hpp"

namespace APP
{
    /**
     *  @brief LoginWnd
     *          LoginWnd类是显示登录界面的类
     *      输入账户名,正确则继续输入密码,不正确则重新输入账户名.
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
         *  选择1.注册账户
         *  选择2.登录个人账户
         *  选择3.默认访客登录
         * @param N/A
         * @return N/A
         */
        void run();

        /**
         * @brief registerAccount
         *      注册账户
         *  根据提示输入用户名
         *  根据提示输入密码
         *  根据提示再次输入密码
         *  两次密码相同则注册成功,不相同则再次输入
         * @param N/A
         * @return N/A
         */
        void registerAccount();

        /**
         * @brief loginAccount
         *      输入用户名: 用户名正确: 输入密码:
         *  密码正确:登录成功
         *  密码错误:返回继续输入用户名
         *  用户名错误:返回继续输入用户名
         * @param N/A
         * @return N/A
         */
        void loginAccount();

       //<<<-------------------------------------------------------------------
    };
}// End of namespace APP

#endif // LOGINWND_HPP
