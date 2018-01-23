#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "CustomException.hpp"
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Point.hpp"

namespace SSDK
{

    /**
     *  @brief  表示矩形框，存有矩形框的位置和长宽
     *          具有计算矩形面积的功能
     *  @author peter
     *  @version 1.00 2018-01-05 peter
     *                note:create it
     */
    class Rectangle:public Shape
    {
    public:

        //>>>-------------------------------------------------------------------
        // constructor & destructor

        /**
         *  @brief  Rectangle
         *      默认构造函数,将形状类型设置为矩形
         *  @param   N/A
         *  @return  N/A
         */
        Rectangle();

        /**
         *  @brief  Rectangle
         *      带参构造函数，设置相关成员变量并将形状类型设置为矩形
         *  @param
         *      xPos: 设置rectangle的x坐标
         *      yPos: 设置rectangle的y坐标
         *      width:设置rectangle的宽度
         *      height:设置rectangle的高度
         *      angle: 设置rectangle的angle角度
         *  @return  N/A
         */
        Rectangle( double xPos,
                   double yPos,
                   double width,
                   double height,
                   double angle );

        virtual ~Rectangle();

        //>>>-------------------------------------------------------------------
        // set & get function

        double width() { return this->m_width; }
        void setWidth(double width) { this->m_width = width; }

        double height() { return this->m_height; }
        void setHeight(double height) { this->m_height = height; }

        double angle() { return this->m_angle; }
        void setAngle(double angle) { this->m_angle = angle; }

        //>>>-------------------------------------------------------------------
        // member function

        /**
         *  @brief   判断一个点是否在矩形内（只支持角度为0的矩形）
         *  @param   point :要判断的点
         *  @return  true:在范围内
         *           false:不在范围内
         */
        virtual bool canContain(Shape *pShape) override;

        /**
         *  @brief   找出矩形的临界点（不支持带角度的rectangle）
         *  @param   N/A
         *  @return  N/A
         */
        virtual void findBoundaryPoints() override;


    private:

        //>>>-------------------------------------------------------------------
        // member variant

        double m_width{0};        //矩形的宽度
        double m_height{0};       //矩形的高度
        double m_angle{0};        //矩形的旋转角度

        //<<<-------------------------------------------------------------------
    };

}// End of namespace SSDk

#endif // RECTANGLE_H
