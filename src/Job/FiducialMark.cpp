#include "FiducialMark.hpp"

using namespace Job;
using namespace std;

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constructor & destructor

FiducialMark::FiducialMark()
{
    try
    {
        this->m_measuredObjType = MeasuredObjType::FIDUCIALMARK;
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("构造函数出错");
}

Job::FiducialMark::FiducialMark(int id,
                                string name,
                                double centerX,
                                double centerY,
                                double width,
                                double height,
                                double angle)
{
    try
    {
        this->m_measuredObjType = MeasuredObjType::FIDUCIALMARK;
        this->m_id = id;
        this->m_name = name;
        this->rectangle().centerPoint().setPosX(centerX);
        this->rectangle().centerPoint().setPosY(centerY);
        this->m_rectangle.setWidth(width);
        this->m_rectangle.setHeight(height);
        this->m_rectangle.setAngle(angle);
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("构造函数出错");
}

FiducialMark::~FiducialMark()
{

}

void FiducialMark::inspect()
{
    try
    {
        this->m_isResultOk = true;
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("检测元件时出错");
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
