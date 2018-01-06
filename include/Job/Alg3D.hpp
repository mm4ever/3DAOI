#ifndef ALG3D_HPP
#define ALG3D_HPP

#include "CustomException.hpp"
#include "Alg.hpp"
#include "NumRandom.hpp"

namespace Job
{

    /**
     *  @brief Alg3D
     *
     *  @author lynn
     *  @version 1.00 2018-01-05 lynn
     *                note:create it
     */
    class Alg3D:public Alg
    {
    public:

        //>>>-----------------------------------------------------------------------
        // constructor & destructor

        Alg3D();

        virtual ~Alg3D();

        //>>>-----------------------------------------------------------------------
        // override function

        virtual bool inspect() override;

        //<<<-----------------------------------------------------------------------
    };

}//End of namespace Job

#endif // ALG3D_HPP
