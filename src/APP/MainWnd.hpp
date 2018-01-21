#ifndef MAINWND_HPP
#define MAINWND_HPP

#include <iostream>
#include <string>

#include <QDir>

#include "DB/SqliteDb.hpp"
#include "GlobalVariants.hpp"
#include "CustomException.hpp"
#include "FiducialMark.hpp"
#include "Component.hpp"
#include "DataGenerator.hpp"

namespace APP
{
    /**
     *  @brief MainWnd
     *          MainWnd类是表示程序主界面的类
     *
     *  @author peter
     *  @version 1.00 2018-01-06 peter
     *                note:create it
     */
    class MainWnd
    {
    public:

        //>>>-------------------------------------------------------------------
        // constructor & destructor

        MainWnd();
        virtual~MainWnd();

        //>>>-------------------------------------------------------------------
        // member function

        /**
         * @brief run
         *      依次运行startupWnd、loginWnd、mainWnd
         *  startupWnd:启动界面(以延迟2秒模拟启动过程)
         *  loginWnd:登录界面,输入用户名和密码登录
         *  mainWnd:扫描程式文件夹,选择创建程式或加载已存在的程式
         * @param N/A
         * @return N/A
         */
        void run();

        /**
         * @brief scanJobFolder
         *      扫描程式文件
         *  读取配置文件中存放程式文件的文件夹路径,扫描文件夹下的程式文件,
         *  提示用户创建检测程式或打印扫描的文件让用户选择需要加载的程式.
         * @param N/A
         * @return N/A
         */
        void scanJobFolder();

        /**
         * @brief inspectClick
         *      调用Sequence下的spectCycle()函数.
         * @param N/A
         * @return N/A
         */
        void inspectClick();

        /**
         * @brief loadJob
         *      加载程式文件
         * @param jobPath
         *      程式文件的路径
         * @return N/A
         */
        void loadJob(const QString& jobPath);

        /**
         * @brief createDefaultJob
         *      创建检测程式
         * @param jobName
         *      检测程式的名称
         * @return N/A
         */
        void createDefaultJob(const QString& jobName);

        //<<<-------------------------------------------------------------------

    };
}// End of namespace APP

#endif // MAINWND_HPP
