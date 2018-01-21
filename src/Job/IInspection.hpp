#ifndef INSPECTION_HPP
#define INSPECTION_HPP

#include "CustomException.hpp"

namespace Job
{

    /**
     *  @brief  IInspection
     *              底层返回bool类型的检测接口
     *  @author lynn
     *  @version 1.00 2018-01-21 lynn
     *                note:create it
     */
    class IInspection
    {
    public:

        //>>>-----------------------------------------------------------------------
        // constructor & destructor

        IInspection();

        virtual ~IInspection();

        //>>>-----------------------------------------------------------------------
        // virtual function

        /**
        *  @brief  inspect
        *           检测检测对象的虚函数
        *  @param  N/A
        *  @return bool:返回一个bool类型的值
        */
        virtual bool inspect()=0;

        //<<<-----------------------------------------------------------------------

    };

}//End of namespace Job

#endif // INSPECTION_HPP
