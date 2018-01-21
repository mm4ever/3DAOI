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

        IInspection();

        virtual ~IInspection();

        //>>>-----------------------------------------------------------------------
        // virtual function

        virtual bool inspect()=0;

        //<<<-----------------------------------------------------------------------

    };

}//End of namespace Job

#endif // INSPECTION_HPP
