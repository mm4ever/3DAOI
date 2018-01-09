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

}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// member function

void LoginWnd::run()
{
    QString path = APP::g_pAppService->pathSetting().registrationInfoPath();
    if( !QFile::exists(path) )  // 没有配置文件,写入默认值
    {
        QSettings config(path,QSettings::IniFormat);
        config.setValue("default","12345678");
    }

    QSettings config(path,QSettings::IniFormat);
    string name,passwd;
    bool isLogin = false;

    while( !isLogin )
    {
        cout << "Please input user name:";
        getline(cin,name);

        // 判断输入的账户是否存在ini文件中
        int inputName = config.value(QString::fromStdString(name)).toInt();
        if( 0 != inputName )
        {
            std::cout << "Please input password:";
            getline(cin,passwd);
            auto inputPasswd = config.value(QString::fromStdString(name)).toString();
            if ( inputPasswd.toStdString() == passwd )
            {
                isLogin = true;
                cout << "Longin successful!\n" << endl;
            }
            else
            {
                cout << "Invalid password! Try again!" << endl;
            }
        }
        else
        {
            cout << "Invalid user! Try again!" << endl;
        }
    }
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

