#include "InspectionSetting.hpp"

using namespace std;
using namespace Job;

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constructor & destructor

InspectionSetting::InspectionSetting()
{
    try
    {
        int width = 4096;
        int height = 3072;
        this->m_imgWidth = width;
        this->m_imgHeight = height;
        this->m_imgBit = ImgBit::BIT8;
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("构造函数出错");
}

InspectionSetting::~InspectionSetting()
{

}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// member function

void InspectionSetting::load(QString &path)
{
    try
    {
        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //step1
        if(QFile::exists(path))                // 文件存在,加载配置文件
        {
            //将类QSettings实例化一个对象
            //path:存放文件的路径,QSettings::IniFormat: 为存放文件的格式
            QSettings configFile(path,QSettings::IniFormat);

            //>>>-------------------------------------------------------------------------------------------------------------------------------------
            //step2.1
            //读取文件Image/Width(图像宽度)数据,并判断是否与系统默认值匹配
            //如果不匹配,则抛出异常
            int imgWidth = configFile.value("Width").toInt();

            if( this->m_imgWidth != imgWidth )
            {
                THROW_EXCEPTION("读取文件数据Width失败!");
            }

            //>>>-------------------------------------------------------------------------------------------------------------------------------------
            //step2.2
            //读取文件Image/Height(图像高度)数据,并判断是否与系统默认值匹配,
            //如果不匹配,则抛出异常
            int imgHeight = configFile.value("Height").toInt();

            if( this->m_imgHeight !=  imgHeight)
            {
                THROW_EXCEPTION("读取文件数据Height失败!");
            }

            //>>>-------------------------------------------------------------------------------------------------------------------------------------
            //step2.3
            //读取文件Image/ImgBit数据,并判断是否是枚举中的元素
            //如果不匹配,则抛出异常
            QString imgBit = configFile.value("ImgBit").toString();

            if(imgBit.toUpper().toStdString() == VAR_TO_STR(ImgBit::BIT8))
            {
                this->m_imgBit = ImgBit::BIT8;
            }
            else if (imgBit.toUpper().toStdString() == VAR_TO_STR(ImgBit::BIT16))
            {
                this->m_imgBit = ImgBit::BIT16;
            }
            else
            {
                THROW_EXCEPTION("读取文件数据ImgBit失败!");
            }
        }
        else                                   //如果文件存在,则读取文件中的数据
        {
            QSettings configFile(path,QSettings::IniFormat);
            configFile.setValue("Width",this->m_imgWidth);
            configFile.setValue("Height",this->m_imgHeight);
            configFile.setValue("ImgBit",
                                QString::fromStdString(VAR_TO_STR(ImgBit::BIT8)));
        }
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("读取InspectionSetting.ini文件异常");
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
