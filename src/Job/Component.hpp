#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "MeasuredObj.hpp"

namespace Job
{
    /**
     *  @brief Component
     *
     *  @author lynn
     *  @version 1.00 2018-01-05 lynn
     *                note:create it
     */
    class Component:public MeasuredObj
    {
    public:

        //>>>-----------------------------------------------------------------------
        // constructor & destructor

        Component();

        virtual~ Component();

        //<<<-----------------------------------------------------------------------
    };

}//End of namespace Job

#endif // COMPONENT_HPP
