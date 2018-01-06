#ifndef ALG_HPP
#define ALG_HPP

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
    class Alg
    {
    public:

        //>>>-----------------------------------------------------------------------
        // constructor & destructor

        Alg();

        virtual ~Alg();

        //>>>-----------------------------------------------------------------------
        // member function

        virtual bool inspect() = 0;

        //<<<-----------------------------------------------------------------------
    };

}//End of namespace Job


#endif // ALG_HPP
