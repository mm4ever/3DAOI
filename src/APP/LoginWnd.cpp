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
        // 用户选择游客登录、注册账户、登录账户
        int runningType;
        do
        {
            cout << "\n1:register account" << endl
                 << "2:login account" << endl
                 << "3:login as a tourist" << endl
                 << "Choice number:";
            cin >> runningType;
            while(!cin)                 // 输入不是数字
            {
                cout << "Not a digit!Try again:";
                cin.clear();            // 清空输入的缓存
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> runningType;     // 输入登录模式的序号
            }
            if( 1 == runningType )      // 输入1为注册账户
            {
                cin.clear();            // 清空输入的缓存
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                this->registerAccount();
            }
            else if( 2 == runningType ) // 输入2为登录
            {
                cin.clear();            // 清空输入的缓存
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                this->login();
            }
            else                        // 输入其他为访客登录
            {
                cout << "Login as a tourist." << endl;
                cout << "\n";
            }
        }while ( 1 == runningType );    // 注册完账户选择登录
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
                cout << "Two passwd is same,Register success!" << endl;
                config.setValue( QString::fromStdString(userName),
                                 QString::fromStdString(firstPasswd) );
                break;
            }
            else
            {
                // 两次密码不同,请重新输入
                cout << "Two passwd is different,Try again!" << endl;
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
            if( 0 != inputName )                            // 用户名是否正确
            {
                std::cout << "Please input password:";
                getline(cin,passwd);                        // 获得密码输入
                auto inputPasswd = config.value(QString::fromStdString(name)).toString();
                if ( inputPasswd.toStdString() == passwd )  // 判断密码是否正确
                {
                    cout << "Longin successful!\n" << endl; // 登录成功
                    break;
                }
                else
                {
                    cout << "Invalid password! Try again!" << endl; // 密码错误
                }
            }
            else
            {
                cout << "Invalid user! Try again!" << endl; // 账户错误
            }
        }
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Login error!");
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

