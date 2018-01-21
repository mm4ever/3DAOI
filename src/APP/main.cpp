#include <iostream>

#include "GlobalVariants.hpp"
#include "UIManager.hpp"
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

        //>>>-------------------------------------------------------------------
        // 初始化appService和sequence
        APP::g_pSequence = new Sequence();
        APP::g_pAppService = new AppService();

        APP::g_pAppService->pathSettingPath() = pathSettingPath;

        APP::g_pAppService->init();
        APP::g_pSequence->init();

        //>>>-------------------------------------------------------------------
        // StartupWnd
        UIManager uiManager;
        uiManager.run();

        delete APP::g_pAppService;
        APP::g_pAppService = nullptr;
        delete APP::g_pSequence;
        APP::g_pSequence = nullptr;
    }
    CATCH_AND_PRINT_EXCEPTION();

    return 0;
}
