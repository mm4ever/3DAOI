#ifndef RANDOMNUM_HPP
#define RANDOMNUM_HPP

#include <cstdlib>

#include "CustomException.hpp"

namespace SSDK
{
    /**
     *  @brief RandomNum
     *         用于随机生成一个数字的类，支持的类型有：
     *          1.double
     *          2.int
     *  @author peter
     *  @version 1.00 2018-01-05 peter
     *                note:create it
     */
    class NumRandom
    {
    public:

        //>>>-------------------------------------------------------------------
        // constructor & destructor

        NumRandom();

        virtual ~NumRandom();

        //>>>-------------------------------------------------------------------
        // member function

        /**
         *  @brief  randomDouble
         *          随机生成区间(min,max)区间的浮点数
         *  @param  max:随机数的最大值
         *          min:随机数的最小值
         *  @return 随机生成的double形浮点数
         */
        static double randomDouble(double min, double max );

        /**
         *  @brief  randomInt
         *          随机生成区间(min,max)区间的整形数
         *  @param  max:随机数的最大值
         *          min:随机数的最小值
         *  @return 随机生成整形数
         */
        static int randomInt(int min, int max );

        /**
         *  @brief  randomBool
         *          按照传入的概率生成boll值true/false
         *  @param  falseProbability:随机生成bool值中false的几率
         *  @return 随机生成的bool值
         */
        static bool randomBool(double falseProbability );

        //<<<-------------------------------------------------------------------
    };
}   //End of namespace SSDK

#endif // RANDOMNUM_HPP
