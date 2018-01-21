#ifndef FIDUCIALMARK_HPP
#define FIDUCIALMARK_HPP

#include "MeasuredObj.hpp"

namespace Job
{
    /**
     *  @brief FiducialMark
     *          表示一个基准点，存有：
     *          1.id号
     *          2.名字
     *          3.检测结果是否为OK
     *          4.位置和大小信息
     *          5.检测库
     *          6.检测元件类型信息
     *          具有以下功能：
     *          模拟检测并记录检测结果
     *
     *  @author lynn
     *  @version 1.00 2018-01-05 lynn
     *                note:create it
     */
    class FiducialMark:public MeasuredObj
    {
    public:

        //>>>-----------------------------------------------------------------------
        // constructor & destructor

        /**
        *  @brief   默认构造函数，将检测目标的类型设置为FiducialMark
        *  @param   N/A
        *  @return  N/A
        */
        FiducialMark();

        /**
        *  @brief 带参构造函数，设置成员变量，并将检测目标的类型设置为FiducialMark
        *  @param id:测量目标序号
        *         name：元件名
        *         centerX：基准点的中心点x坐标
        *       　centerY：基准点的中心点y坐标
        *         width：基准点宽
        *       　height：基准点高
        *         angle：基准点角度
        *  @return  N/A
        */
        FiducialMark(int id,
                     std::string name,
                     double centerX,
                     double centerY,
                     double width,
                     double height,
                     double angle);

        virtual ~FiducialMark();

        //>>>-----------------------------------------------------------------------
        //override function

        /**
        *  @brief   模拟元件的检测并记录检测结果
        *  @param   N/A
        *  @return  N/A
        */
        virtual void inspect() override;

        //<<<-----------------------------------------------------------------------
    };

}//End of namespace Job

#endif // FIDUCIALMARK_HPP
