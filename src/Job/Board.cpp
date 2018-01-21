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

void Board::writeToXml(std::string &path)
{

}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Board::inspect()
{
    try
    {
        int objCnt = this->m_pObjs.size();
        for(unsigned i = 0 ; i < objCnt ; ++ i)   //检测所有基准点
        {
            if(MeasuredObj::MeasuredObjType::FIDUCIALMARK == this->m_pObjs[i]->measuredObjType())
            {
                this->m_pObjs[i]->inspect();
            }
        }

        for(unsigned i = 0 ; i < objCnt ; ++ i)   //检测所有元件
        {
            if(MeasuredObj::MeasuredObjType::COMPONENT == this->m_pObjs[i]->measuredObjType())
            {
                this->m_pObjs[i]->inspect();
            }
        }
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("检测基板元件出错");
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
