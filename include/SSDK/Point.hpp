#ifndef POSITION_HPP
#define POSITION_HPP

#include <cmath>

#include "CustomException.hpp"

namespace SSDK
{

    /**
     *  @brief 表示位置信息的类，含有的信息有
     *         1.在x坐标上的位置
     *         2.在y坐标上的位置
     *
     *  @author peter
     *  @version 1.00 2018-01-05 peter
     *                note:create it
     */
    class Point
    {
    public:

        //>>>-------------------------------------------------------------------
        // constructor & destructor

        /**
         *  @brief   默认构造函数
         *  @param   N/A
         *  @return  N/A
         */
        Point();

        /**
         *  @brief   将传入的x,y坐标存到成员变量中
         *  @param   N/A
         *  @return  N/A
         */
        Point(double posX,double posY);

        /**
         *  @brief   析构函数
         *  @param   N/A
         *  @return  N/A
         */
        virtual ~Point();

        //>>>-------------------------------------------------------------------
        // set & get function

        double posX() {return this->m_posX;}
        void setPosX(double posX) {this->m_posX = posX;}

        double& posY() {return this->m_posY;}
        void setPosY(double posY) {this->m_posY = posY;}

        //>>>-------------------------------------------------------------------
        // member function

        /**
         *  @brief   求到目标点的距离
         *  @param   point:要求距离的目标点
         *  @return  到目标点之间的距离
         */
        double calcDistanceTo(Point& point);


    protected:

        //>>>-------------------------------------------------------------------
        // member variant

        double m_posX{0};      //在x坐标上的位置
        double m_posY{0};      //在y坐标上的位置

        //<<<-------------------------------------------------------------------
    };

}//End of namespace SSDK

#endif // POSITION_HPP
