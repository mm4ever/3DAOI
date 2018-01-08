#include <iostream>

#include "App.hpp"
#include "CustomException.hpp"

using namespace std;

using namespace APP;

int main()
{
    try
    {
        //>>>-------------------------------------------------------------------
        // 设置PathSetting.ini路径
        QString pathSettingPath = "./config/PathSetting.ini";
        appService.setPathSettingPath(pathSettingPath);

        //>>>-------------------------------------------------------------------
        // 初始化appService和sequence
        appService.init();
        sequence.init();


    }
    CATCH_AND_PRINT_EXCEPTION();

    return 0;
}
