#include "Component.hpp"

using namespace Job;

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constructor & destructor

Component::Component()
{
    try
    {
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("构造函数出错");
}

Component::Component(MeasuredObjType measuredObjType)
{
    try
    {
        this->m_measuredObjType = measuredObjType;
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("构造函数出错");
}

Component::~Component()
{

}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
