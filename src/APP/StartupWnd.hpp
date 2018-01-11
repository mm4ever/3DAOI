#ifndef STARTUPWND_HPP
#define STARTUPWND_HPP

#include <chrono>
#include <thread>

#include "CustomException.hpp"

namespace APP
{
    /**
     *  @brief StartupWnd
     *          StartupWnd类是表示程序启动界面的类
     *  运行时显示程序正在加载的等待界面.
     *
     *  @author peter
     *  @version 1.00 2018-01-06 peter
     *                note:create it
     */
    class StartupWnd
    {
    public:

        //>>>-------------------------------------------------------------------
        // constructor & destructor

        StartupWnd();
        virtual~StartupWnd();

        //>>>-------------------------------------------------------------------
        // member function

        /**
         * @brief run
         *      启动界面,显示程序正在加载
         * @param N/A
         * @return N/A
         */
        void run();

        //<<<-------------------------------------------------------------------

    };

}// End of namespace APP


#endif // STARTUPWND_HPP
