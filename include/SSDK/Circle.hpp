#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "CustomException.hpp"
#include "Shape.hpp"

namespace SSDK
{

    /**
     *  @brief  表示圆形框，存有圆形的坐标位置和长宽
     *          具有计算矩形面积的功能
     *  @author peter
     *  @version 1.00 2018-01-05 peter
     *                note:create it
     */
    class Circle:public Shape
    {
    public:

        //>>>-------------------------------------------------------------------
        // constructor & destructor

        /**
         *  @brief   默认构造函数，将形状类型设置为圆形
         *  @param   N/A
         *  @return  N/A
         */
        Circle();

        /**
        *  @brief   用给定位置信息、半径进行构造并将形状类型设置为圆形
        *  @param   radius:要设置的半径
        *           posX:要设置的x坐标
        *           posY:要设置的y坐标
        *  @return  N/A
        */
        Circle( double radius,double posX,double posY );

        virtual ~Circle();

        //>>>-------------------------------------------------------------------
        // set & get function

        double radius() {return this->m_radius;}
        void setRadius(double radius) {this->m_radius = radius;}

        //>>>-------------------------------------------------------------------
        // member function

        virtual double calcArea();

        /**
         *  @brief   判断圆形是否在目标矩形范围内
         *  @param   originX:目标矩形的起始点x坐标
         *           originY:目标矩形的起始点y坐标
         *           width  :目标矩形的宽
         *           height :目标矩形的长
         *  @return  true:在范围内
         *           false:不在范围内
         */
        virtual bool canContain(Shape *pShape) override;

        /**
        *  @brief   找出圆形的临界点
        *  @param   N/A
        *  @return  N/A
        */
        virtual void findBoundaryPoints() override;


    private:

        //>>>-------------------------------------------------------------------
        // member variant

        double m_radius{0};

        //<<<-------------------------------------------------------------------
    };

}//End of namespace SSDK

#endif // CIRCLE_HPP
