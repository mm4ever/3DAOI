#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <vector>

#include "Point.hpp"

namespace SSDK
{
    /**
     *  @brief 表示形状的类，存有形状的坐标位置
     *
     *  @author peter
     *  @version 1.00 2018-01-05 peter
     *                note:create it
     */
    class Shape
    {
    public:

        enum class ShapeType
        {
            CIRCLE,
            RECTANGLE
        };

        //>>>-------------------------------------------------------------------
        // constructor & destructor

        /**
         *  @brief   默认构造函数
         *  @param   N/A
         *  @return  N/A
         */
        Shape();

        /**
         *  @brief   析构函数
         *  @param   N/A
         *  @return  N/A
         */
        virtual ~Shape();

        //>>>-------------------------------------------------------------------
        // set & get function

        Point& centerPoint() { return this->m_centerPoint; }

        std::vector<Point>& limitPoints(){ return this->m_limitPoints; }

        ShapeType shapeType() {return this->m_shapeType;}

        //>>>-------------------------------------------------------------------
        // member function

        virtual void findBoundaryPoints() = 0;

        virtual bool canContain(SSDK::Shape *pShape) = 0;


    protected:

        //>>>-------------------------------------------------------------------
        // member variant

        std::vector<Point> m_limitPoints; //形状的临界点
        ShapeType m_shapeType;//形状类型
        Point m_centerPoint;  //形状的中心点

        //<<<-------------------------------------------------------------------
    };

}//End of namespace SSDK

#endif // SHAPE_HPP
