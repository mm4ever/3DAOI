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
        *  @brief   析构函数
        *  @param   N/A
        *  @return  N/A
        */
        virtual ~FiducialMark();

        //<<<-----------------------------------------------------------------------mm
    };

}//End of namespace Job

#endif // FIDUCIALMARK_HPP
