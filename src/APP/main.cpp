#include <iostream>

#include "App.hpp"
#include "CustomException.hpp"

using namespace std;

using namespace APP;

int main()
{
    try
    {
        QString pathSettingPath = "./config/PathSetting.ini";
        appService.setPathSettingPath(pathSettingPath);
        appService.init();
    }
    CATCH_AND_PRINT_EXCEPTION();

    return 0;
}
