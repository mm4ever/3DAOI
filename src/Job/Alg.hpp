#ifndef ALG_HPP
#define ALG_HPP

#include "CustomException.hpp"
#include "IInspection.hpp"

namespace Job
{
    /**
     *  @brief Alg
     *          表示算法的基类，有以下成员变量：
     *          m_algType   :记录算法的类型
     *          有以下功能：
     *          模拟检测返回结果
     *  @author lynn
     *  @version 1.00 2018-01-05 lynn
     *                note:create it
     */
    class Alg:public IInspection
    {
    public:

        enum class AlgType
        {
            ALG3D,
            ALG2D
        };

        //>>>-----------------------------------------------------------------------
        // constructor & destructor

        Alg();

        virtual ~Alg();

        //>>>-----------------------------------------------------------------------
        // set & get function

        AlgType algType(){return this->m_algType;}

    protected:

        //>>>-----------------------------------------------------------------------
        // member variant

        AlgType m_algType;      //使用的算法的类型

        //<<<-----------------------------------------------------------------------
    };

}//End of namespace Job


#endif // ALG_HPP
