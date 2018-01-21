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
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Constructor error!");
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
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Constructor error!");
}

Component::~Component()
{
    try
    {

    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Destructor error!");
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
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Inspect error!");
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
