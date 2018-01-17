#ifndef INSPECTION_HPP
#define INSPECTION_HPP

#include "CustomException.hpp"

namespace Job
{

    class IInspection
    {
    public:

        //>>>-----------------------------------------------------------------------
        // constructor & destructor

        /**
        *  @brief   默认构造函数
        *  @param   N/A
        *  @return  N/A
        */
        IInspection();

        /**
        *  @brief   析构函数
        *  @param   N/A
        *  @return  N/A
        */
        virtual ~IInspection();

        //>>>-----------------------------------------------------------------------
        // virtual function

        virtual bool inspect()=0;

        //<<<-----------------------------------------------------------------------

    };

}//End of namespace Job

#endif // INSPECTION_HPP
