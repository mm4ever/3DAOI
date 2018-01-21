#include "InspectionData.hpp"

using namespace Job;

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constructor & destructor

InspectionData::InspectionData()
{
    try
    {

    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("构造函数出错");
}

InspectionData::~InspectionData()
{

}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// member function

void InspectionData::writeInspectionDataToXml(QString path)
{
    try
    {
        //>>>--------------------------------------------------------------------------------------------
        //step1
        //定义一个QDomDocument xml文档类的对象
        //在该文档下生成一个inspectionDataInfo节点,将版本号,上次编辑时间写入在该节点下

        QDomDocument inspectionData;
        QDomElement inspectionDataInfo = inspectionData.createElement("InspectionData");

        //设置inspectionDataInfo元素的属性(版本号,上次编辑时间)
        inspectionDataInfo.setAttribute("版本号",
                             QString::fromStdString(this->version()));
        inspectionDataInfo.setAttribute("上次编辑时间",
                             QString::fromStdString(this->lastEditingTime()));
        inspectionData.appendChild(inspectionDataInfo);

        //>>>---------------------------------------------------------------------------------------------
        //step2
        //将board信息写入到inspectionData文档中的inspectionDataInfo节点下

        this->m_board.writeBoardDataToXml(inspectionData,inspectionDataInfo);

        //>>>---------------------------------------------------------------------------------------------
        //step3
        //设置文件路径,并将inspectionData中的数据写入到该路径下的xml文件中

        QFile file(path);

        if (!file.open(QFile::WriteOnly | QFile::Text))     //判断文件是否被打开
        {
            THROW_EXCEPTION("打开文件失败!!");
        }

        QTextStream out(&file);                             //定义文本输出流
        inspectionData.save(out,4);
        file.close();                                       //关闭文件
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("function writeInspectionDataToXml error!");
}

void InspectionData::inspect()
{
    try
    {
        this->m_board.inspect();
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("检测程式文件时出错");
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
