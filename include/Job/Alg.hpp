#ifndef ALG_HPP
#define ALG_HPP

#include "CustomException.hpp"
#include "Inspection.hpp"

namespace Job
{

    enum class AlgType
    {
        ALG3D,
        ALG2D
    };
    /**
     *  @brief Alg
     *
     *  @author lynn
     *  @version 1.00 2018-01-05 lynn
     *                note:create it
     */
    class Alg:public Inspection
    {
    public:

        //>>>-----------------------------------------------------------------------
        // constructor & destructor

        Alg();

        virtual ~Alg();

        //<<<-----------------------------------------------------------------------
    };

}//End of namespace Job


#endif // ALG_HPP
