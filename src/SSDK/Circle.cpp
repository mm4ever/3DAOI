#include "Circle.hpp"

using namespace SSDK;

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constructor & destructor

Circle::Circle()
{
    try
    {
        this->m_shapeType = ShapeType::CIRCLE;
    }
    catch(...)
    {
        THROW_EXCEPTION("Constructor error!");
    }
}

Circle::Circle(double radius, double posX, double posY)
{
    try
    {
        this->m_radius = radius;
        this->m_centerPoint.setPosX(posX);
        this->m_centerPoint.setPosY(posY);
        this->m_shapeType = ShapeType::CIRCLE;
    }
    catch(...)
    {
        THROW_EXCEPTION("Constructor error!");
    }
}

Circle::~Circle()
{

}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// member function

double Circle::calcArea()
{
    double pi = 3.14; //π的近似值
    return pi * this->m_radius * this->m_radius;
}

bool Circle::canContain(Shape *pShape)
{
    try
    {
        THROW_EXCEPTION("不支持图形是否包含在圆形内的判断");
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("判断形状是否包含在圆中时出错");
}

void Circle::findBoundaryPoints()
{
    if(this->m_radius <= 0 || this->m_limitPoints.size() != 0)
    {
        return;
    }

    this->m_limitPoints.push_back(
                Point(this->centerPoint().posX() + this->m_radius,
                      this->centerPoint().posY()));

    this->m_limitPoints.push_back(
                Point(this->centerPoint().posX() - this->m_radius,
                      this->centerPoint().posY()));

    this->m_limitPoints.push_back(
                Point(this->centerPoint().posX(),
                      this->centerPoint().posY() + this->m_radius));

    this->m_limitPoints.push_back(
                Point(this->centerPoint().posX(),
                      this->centerPoint().posY() - this->m_radius));

}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
