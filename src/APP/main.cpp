#include <iostream>

#include "GlobalVariable.hpp"
#include "UIManager.hpp"
#include "CustomException.hpp"

#include "DataGenerator.hpp"


using namespace std;

using namespace APP;

int main()
{
    try
    {
        //>>>-------------------------------------------------------------------
        // 设置PathSetting.ini路径
//        QString pathSettingPath = "./config/PathSetting.ini";

//        //>>>-------------------------------------------------------------------
//        // 初始化appService和sequence
//        APP::g_pSequence = new Sequence();
//        APP::g_pAppService = new AppService();

//        APP::g_pAppService->setPathSettingPath(pathSettingPath);

//        APP::g_pAppService->init();
//        APP::g_pSequence->init();

//        //>>>-------------------------------------------------------------------
//        // StartupWnd
//        UIManager uiManager;
//        uiManager.run();
        DataGenerator data;
        Job::InspectionData ins;
        data.generateInspectionData(ins);
    }
    CATCH_AND_PRINT_EXCEPTION();

    return 0;
}
