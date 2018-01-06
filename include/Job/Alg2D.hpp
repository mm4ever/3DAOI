#ifndef ALG2D_HPP
#define ALG2D_HPP

#include "Alg.hpp"
#include "NumRandom.hpp"

namespace Job
{
    /**
     *  @brief Alg2D
     *
     *  @author lynn
     *  @version 1.00 2018-01-05 lynn
     *                note:create it
     */
    class Alg2D:public Alg
    {
    public:

        //>>>-----------------------------------------------------------------------
        // constructor & destructor

        Alg2D();

        virtual ~Alg2D();

        //>>>-----------------------------------------------------------------------
        // member function

        virtual bool inspect() override;

        //<<<-----------------------------------------------------------------------
    };

}//End of namespace Job

#endif // ALG2D_HPP
