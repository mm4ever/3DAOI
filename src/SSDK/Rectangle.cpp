#include "Rectangle.hpp"

using namespace SSDK;

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constructor & destructor

Rectangle::Rectangle()
{
    try
    {
        this->m_shapeType = ShapeType::RECTANGLE;
    }
    catch(...)
    {
        THROW_EXCEPTION("构造函数出错");
    }
}

Rectangle::Rectangle( double xPos,
                      double yPos,
                      double width,
                      double height,
                      double angle )
{
    try
    {
        this->centerPoint().setPosX(xPos);
        this->centerPoint().setPosY(yPos);
        this->m_width = width;
        this->m_height = height;
        this->m_angle = angle;          //2017.12.02 bob 添加成员变量rectangle的角度
        this->m_shapeType = ShapeType::RECTANGLE;
    }
    catch(...)
    {
        THROW_EXCEPTION("构造函数出错");
    }
}


Rectangle::~Rectangle()
{

}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// member function

bool Rectangle::canContain(Shape *pShape)
{
    try
    {
        if(nullptr == pShape)
        {
            THROW_EXCEPTION("传入的图形错误");
        }

        if(ShapeType::CIRCLE == pShape->shapeType())            //若传入的为圆形
        {
            Point centerPoint = pShape->centerPoint();
            double radius = ((Circle*)pShape)->radius();

            if(this->centerPoint().posY()+this->height()/2 > centerPoint.posY()+radius &&
               this->centerPoint().posY()-this->height()/2 < centerPoint.posY()-radius &&
               this->centerPoint().posX()+this->width()/2 > centerPoint.posX()+radius &&
               this->centerPoint().posX()-this->width()/2 < centerPoint.posX()-radius)
            {
                return true;
            }
            return false;
        }
        else if (ShapeType::RECTANGLE == pShape->shapeType())   //若传入的为矩形
        {
            Point centerPoint = pShape->centerPoint();
            double height = ((Rectangle*)pShape)->height();
            double width = ((Rectangle*)pShape)->width();

            if(0 != ((Rectangle*)pShape)->angle() || 0!=this->m_angle)
            {
                THROW_EXCEPTION("不支持对角度不为0的矩形进行判断");
            }

            if(this->centerPoint().posY()+this->height()/2 > centerPoint.posY()+height/2 &&
               this->centerPoint().posY()-this->height()/2 < centerPoint.posY()-height/2 &&
               this->centerPoint().posX()+this->width()/2 > centerPoint.posX()+width/2 &&
               this->centerPoint().posX()-this->width()/2 < centerPoint.posX()-width/2)
            {
                return true;
            }
            return false;
        }
        return false;
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("判断图形是否包含在矩形时出错");
}

void Rectangle::findBoundaryPoints()
{
    if(0 != this->m_angle || this->m_limitPoints.size() != 0)
    {
        return;
    }

    this->m_limitPoints.push_back(
                Point(this->centerPoint().posX()-this->m_width/2,
                      this->centerPoint().posY()-this->m_height));

    this->m_limitPoints.push_back(
                Point(this->centerPoint().posX()+this->m_width/2,
                      this->centerPoint().posY()+this->m_height));

    this->m_limitPoints.push_back(
                Point(this->centerPoint().posX()-this->m_width/2,
                      this->centerPoint().posY()+this->m_height));

    this->m_limitPoints.push_back(
                Point(this->centerPoint().posX()+this->m_width/2,
                      this->centerPoint().posY()-this->m_height));
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


