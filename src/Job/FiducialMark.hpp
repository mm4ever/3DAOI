#ifndef FIDUCIALMARK_HPP
#define FIDUCIALMARK_HPP

#include "MeasuredObj.hpp"

namespace Job
{
    /**
     *  @brief FiducialMark
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

        FiducialMark();

        virtual ~FiducialMark();

        //<<<-----------------------------------------------------------------------mm
    };

}//End of namespace Job

#endif // FIDUCIALMARK_HPP
