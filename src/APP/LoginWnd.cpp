#include "LoginWnd.hpp"

using namespace std;

using namespace APP;

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constructor & destructor

LoginWnd::LoginWnd()
{
    try
    {

    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Constructor error!");
}

LoginWnd::~LoginWnd()
{
    try
    {

    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Destructor error!");
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// member function

void LoginWnd::run()
{
    try
    {
        // 用户选择注册账户、登录账户或游客登录
        int runningType {1};          // 1为注册账户,2为登录账户,3为游客登录
        while ( 1 == runningType )    // 选择注册账户后需要继续选择登录方式
        {
            cout << "\n"
                 << "1:register account\n"
                 << "2:login account\n"
                 << "3:login as a tourist\n"
                 << "Choice number:";
            runningType = -1;         // 输入的值不在范围内,循环输入直至输入正确
            while( runningType > 4 || runningType < 0 )
            {
                cin >> runningType;   // 输入登录模式的序号
                if(!cin)              // 输入不是数字
                {
                    cout << "Not a digit! Please input 1 to 3:";
                    runningType = -1;
                }
                else if( runningType > 3 || runningType < 0 ) // 输入不在范围内
                {
                    cout << "Out of range! Please input 1 to 3:";
                    runningType = -1;
                }
                cin.clear();          // 清空输入的缓存
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if( 1 == runningType )    // 输入1为注册账户
            {
                this->registerAccount();
            }
            else if(2 == runningType) // 输入2为登录
            {
                this->login();
            }
            else                      // 输入3为访客登录
            {
                cout << "Login as a tourist.\n\n";
            }
        }
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Running login window error!");
}

void LoginWnd::registerAccount()
{
    try
    {
        //获取用户账户信息配置文件的路径
        QString path = APP::g_pAppService->pathSetting().userAccountPath();
        QSettings config(path,QSettings::IniFormat);
        //用户名称,首次输入密码,确认输入密码
        string userName{""},firstPasswd{""},secondPasswd{""};

        cout << "Please input your name:";
        getline(cin,userName);          // 输入用户名
        while( true )
        {
            cout << "Please input your passwd:";
            getline(cin,firstPasswd);   // 输入密码

            cout << "Please input your passwd again:";
            getline(cin,secondPasswd);  // 再次输入密码

            if(firstPasswd == secondPasswd)
            {
                // 两次密码输入正确,将账户信息写入配置文件中
                cout << "Two passwd is same,Register success!\n";
                config.setValue( QString::fromStdString(userName),
                                 QString::fromStdString(firstPasswd) );
                break;
            }
            else
            {
                // 两次密码不同,请重新输入
                cout << "Two passwd is different,Try again!\n";
                cout << "Please input your name:";
                getline(cin,userName);          // 再次输入用户名
            }
        }
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Register account error!");
}

void LoginWnd::login()
{
    try
    {
        //获取用户账户信息配置文件的路径
        QString path = APP::g_pAppService->pathSetting().userAccountPath();
        QSettings config(path,QSettings::IniFormat);
        //输入的用户名及密码
        string name {""},passwd{""};
        //用户输入名称的索引,0为配置文件中没有该账户,否则表示配置文件存在该账户
        int inputName {0};

        while( true )
        {
            cout << "Please input user name:";
            getline(cin,name);                              // 获得用户名输入

            // 判断输入的账户是否存在ini文件中
            inputName = config.value(QString::fromStdString(name)).toInt();
            if( 0 != inputName )                            // 用户名正确
            {
                cout << "Please input password:";
                getline(cin,passwd);                        // 获得密码输入
                auto inputPasswd = config.value(QString::fromStdString(name)).toString();
                if ( inputPasswd.toStdString() == passwd )  // 判断密码是否正确
                {
                    cout << "Longin successful!\n\n";       // 登录成功
                    break;
                }
                else
                {
                    cout << "Invalid password! Try again!\n"; // 密码错误
                }
            }
            else                                            // 用户名错误
            {
                cout << "Invalid user! Try again!\n";       // 没有该账户
            }
        }
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Login error!");
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

