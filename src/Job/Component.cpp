#include "Component.hpp"

using namespace Job;
using namespace std;

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

Component::Component(int id,
                     string name,
                     double centralX,
                     double centralY,
                     double angle,
                     double width,
                     double height)
{
    try
    {
        this->m_measuredObjType = MeasuredObjType::COMPONENT;
        this->m_id = id;
        this->m_name = name;
        this->m_rectangle.centerPoint().setPosX(centralX);
        this->m_rectangle.centerPoint().setPosY(centralY);
        this->m_rectangle.setAngle(angle);
        this->m_rectangle.setWidth(width);
        this->m_rectangle.setHeight(height);
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
        if(nullptr != this->m_pLib)
        {
            this->m_isResultOk = this->m_pLib->inspect();
        }
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("检测元件时出错");
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
