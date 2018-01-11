#include "Component.hpp"

using namespace Job;

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constructor & destructor

Component::Component()
{
    try
    {
        this->m_measuredObjType = MeasuredObjType::COMPONENT;
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("构造函数出错");
}

Component::~Component()
{

}

void Component::inspect()
{
    try
    {
        this->m_isResultOk = this->m_lib.inspect();
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("检测元件时出错");
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
