#include "MainItem.hpp"

using namespace Job;

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constructor & destructor

MainItem::MainItem()
{
    try
    {
        this->m_pAlg = new Alg3D;
        this->m_itemType = ItemType::MAINITEM;
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("构造函数出错");
}

MainItem::~MainItem()
{
    try
    {
        if(nullptr != this->m_pAlg)
        {
            delete this->m_pAlg;
        }
    }
    catch(...)
    {
        if(nullptr != this->m_pAlg)
        {
            delete this->m_pAlg;
        }
    }
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
