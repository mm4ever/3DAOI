#ifndef INSPECTION_HPP
#define INSPECTION_HPP

#include "CustomException.hpp"

namespace Job
{

    class Inspection
    {
    public:

        //>>>-----------------------------------------------------------------------
        // constructor & destructor

        /**
        *  @brief   默认构造函数
        *  @param   N/A
        *  @return  N/A
        */
        Inspection();

        /**
        *  @brief   析构函数
        *  @param   N/A
        *  @return  N/A
        */
        virtual ~Inspection();

        //>>>-----------------------------------------------------------------------
        // virtual function

        virtual bool inspect();

        //<<<-----------------------------------------------------------------------

    };

}//End of namespace Job

#endif // INSPECTION_HPP
