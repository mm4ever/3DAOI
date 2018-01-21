#include "MainWnd.hpp"

using namespace std;

using namespace APP;
using namespace Job;
using namespace SSDK;
using namespace SSDK::DB;

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constructor & destructor

MainWnd::MainWnd()
{
    try
    {

    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Constructor error!");
}

MainWnd::~MainWnd()
{
    try
    {

    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Destructor error!");
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// member function

void MainWnd::run()
{
    try
    {
        // 扫描检测程式
        this->scanJobFolder();

        // 加载完程式,检测
        cout << "Press \"y\" to inspect:" << endl;
        char inspect {'y'};
        cin >> inspect;
        if( 'y' == inspect )
        {
            do
            {
                this->inspectClick();
                cout << "Press \"y\" to inspect again:" << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cin >> inspect;
            }while ( 'y' == inspect );
        }
        cout << "Quit ..." << endl;
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Running main window error!");
}

void MainWnd::scanJobFolder()
{
    QString path = APP::g_pAppService->pathSetting().defaultJobFolderPath();
    try
    {
        //>>>-------------------------------------------------------------------
        // 1.判断文件夹是否存在，不存在则创建
        QDir dir(path);
        if(!dir.exists())
        {
            std::cout << path.toStdString() << " is not exists!"<< std::endl;
            if( !dir.mkpath(path) )    // 创建失败
            {
                // 创建配置文件失败,抛出异常
                THROW_EXCEPTION("No job path and create error!");
            }
        }
        //>>>-------------------------------------------------------------------
        // 2.扫描程式文件
        QStringList filters;    // 创建过滤器列表，过滤xml、txt为后缀的文件
        filters << "*[^xml|^txt]";
        dir.setNameFilters(filters);

        dir.setFilter(QDir::Files);
        QFileInfoList list = dir.entryInfoList();


        // 先显示"创建程式"的提示信息,再将扫描的文件打印
        cout << "0:Create default job" << endl;
        for (int i = 0; i < list.size(); ++i)
        {
            cout<<qPrintable(QString("%1:%2\n").arg(i+1).arg(list.at(i).fileName()));
        }
        int index {-1};
        do  // 选择创建程式或需要加载的程式文件
        {
            cout << "\nChoice number to create or load job:\n";
            cin >> index;
            if(!cin)       // 输入不是数字
            {
                cout << "Error! Not a digit!" << std::endl;
                index = -1;
            }
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        while( index > list.size() || index < 0);
        //>>>-------------------------------------------------------------------
        // 3.创建程式或加载程式
        if( 0 == index )
        {
            // 创建新的程式
            QString jobPath {path};
            string jobName;
            cout << "Please input job name:";
            getline(cin,jobName);
            jobPath.append(QString::fromStdString(jobName));
            createDefaultJob(jobPath);
        }
        else
        {
            // 加载用户选择的程式
            QString jobPath = list.at(index-1).filePath();
            loadJob(jobPath);
        }
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Catch exception and rethrow");
}

void MainWnd::inspectClick()
{
    try
    {
        APP::g_pSequence->inspectCycle();
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Inspect click error!");
}

void MainWnd::loadJob(const QString& jobPath)
{

}

void MainWnd::createDefaultJob(const QString& jobName)
{

}
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
