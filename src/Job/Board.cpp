#include "Board.hpp"

using namespace Job;

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
        for(unsigned i = 0;i < this->m_pObjs.size();++i)
        {
            if(nullptr != this->m_pObjs[i])
            {
                delete this->m_pObjs[i];
                this->m_pObjs[i] = nullptr;
            }
        }
    }
    catch(...)
    {
        for(unsigned i = 0;i < this->m_pObjs.size();++i)
        {
            if(nullptr != this->m_pObjs[i])
            {
                delete this->m_pObjs[i];
                this->m_pObjs[i] = nullptr;
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
        for(unsigned i = 0 ; i < this->m_pObjs.size() ; ++ i)   //检测所有基准点
        {
            if(MeasuredObj::MeasuredObjType::FIDUCIALMARK == this->m_pObjs[i]->measuredObjType())
            {
                this->m_pObjs[i]->inspect();
            }
        }

        for(unsigned i = 0 ; i < this->m_pObjs.size() ; ++ i)   //检测所有元件
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
