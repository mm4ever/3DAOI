#include "Board.hpp"

using namespace Job;
using namespace std;

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constructor & destructor

Board::Board()
{
    try
    {

    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("构造函数出错");
}

Board::~Board()
{
    try
    {
        int measuredObjCnt = this->m_pObjs.size();
        for (int i = 0; i < measuredObjCnt ; ++i)//遍历释放所有存放元件的空间
        {
            if (nullptr != this->m_pObjs[i])
            {
                delete this->m_pObjs[i];
                this->m_pObjs[i] = nullptr;
            }
        }

        int libraryCnt = this->m_pLibs.size();
        for (int i = 0 ; i < libraryCnt ; ++i)  //遍历释放所有存放库的空间
        {
            if (nullptr != this->m_pLibs[i])
            {
                delete this->m_pLibs[i];
                this->m_pLibs[i] = nullptr;
            }
        }
    }
    catch(...)
    {
        int measuredObjCnt = this->m_pObjs.size();
        for (int i = 0; i < measuredObjCnt ; ++i)//遍历释放所有存放元件的空间
        {
            if (nullptr != this->m_pObjs[i])
            {
                delete this->m_pObjs[i];
                this->m_pObjs[i] = nullptr;
            }
        }

        int libraryCnt = this->m_pLibs.size();
        for (int i = 0 ; i < libraryCnt ; ++i)  //遍历释放所有存放库的空间
        {
            if (nullptr != this->m_pLibs[i])
            {
                delete this->m_pLibs[i];
                this->m_pLibs[i] = nullptr;
            }
        }
    }
}
//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// member function

void Board::writeBoardDataToXml(QDomDocument &inspectionData,
                                QDomElement &inspectionDataInfo)
{
    try
    {
        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //step1
        //在xml文档中添加一个board节点,设置board的属性(基板名称,基板长度等)

        QDomElement board = inspectionData.createElement("Board");
        //设置board元素的属性
        board.setAttribute("基板名称",QString::fromStdString( this->name()));
        board.setAttribute("基板长度",this->m_recatangle.width());
        board.setAttribute("基板宽度",this->m_recatangle.height());
        board.setAttribute("X轴坐标",this->m_originPoint.posX());
        board.setAttribute("Y轴坐标",this->m_originPoint.posY());

        inspectionDataInfo.appendChild(board);   //将board元素添加至jobInfo节点下

        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //step2
        //将检测出所有错误的元件信息,写入到xml文件

        QDomElement errorObj;                     //board的子节点errorObj
        int objCnt = this->m_pObjs.size();

        for (int i = 0; i < objCnt; ++i)
        {
            if(false == this->m_pObjs[i]->isResultOk() )
            {
                errorObj = inspectionData.createElement(QString::fromStdString(
                                          this->m_pObjs[i]->name()));
                errorObj.setAttribute("高度",QString::number(
                         this->m_pObjs[i]->rectangle().height()));
                errorObj.setAttribute("宽度",QString::number(
                         this->m_pObjs[i]->rectangle().width()));
                errorObj.setAttribute("x坐标",QString::number(
                         this->m_pObjs[i]->rectangle().centerPoint().posX()));
                errorObj.setAttribute("y坐标",QString::number(
                         this->m_pObjs[i]->rectangle().centerPoint().posY()));
            }
            board.appendChild(errorObj);
        }
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Function writeBoardDataToXml error!");
}

void Board::inspect()
{
    try
    {
        int objCnt = this->m_pObjs.size();
        for(int i = 0 ; i < objCnt ; ++ i)   //检测所有基准点
        {
            this->m_pObjs[i]->inspect();
        }
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("检测基板元件出错");
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
