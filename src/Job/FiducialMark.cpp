#include "FiducialMark.hpp"

using namespace Job;

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
