#include "Point.hpp"

using namespace SSDK;

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constructor & destructor

Point::Point()
{
    try
    {

    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Costructor error!");
}

Point::Point(double posX, double posY)
{
    try
    {
        this->m_posX = posX;
        this->m_posY = posY;
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Constructor error!");
}

Point::~Point()
{
    try
    {

    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Destructor error!");
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// member function

double Point::calcDistanceTo(Point &point)
{
    return sqrt( (point.posX() - this->posX()) * (point.posX() - this->posX()) +
                (point.posY() - this->posY()) * (point.posY() - this->posY()) );
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

