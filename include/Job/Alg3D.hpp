#ifndef ALG3D_HPP
#define ALG3D_HPP

#include "CustomException.hpp"
#include "Alg.hpp"
#include "NumRandom.hpp"

namespace Job
{

    /**
     *  @brief Alg3D
     *          表示3D检测算法的类，能够模拟3D检测
     *  @author lynn
     *  @version 1.00 2018-01-05 lynn
     *                note:create it
     */
    class Alg3D:public Alg
    {
    public:

        //>>>-----------------------------------------------------------------------
        // constructor & destructor

        /**
        *  @brief   默认构造函数，将记录算法类型的变量设置为3D检测类型
        *  @param   N/A
        *  @return  N/A
        */
        Alg3D();

        virtual ~Alg3D();

        //>>>-----------------------------------------------------------------------
        // override function

        /**
        *  @brief   模拟3D检测返回结果
        *  @param   N/A
        *  @return  true    ：表示检测结果为好的
        *           false   ：表示检测结果不是好的
        */
        virtual bool inspect() override;

        //<<<-----------------------------------------------------------------------
    };

}//End of namespace Job

#endif // ALG3D_HPP
