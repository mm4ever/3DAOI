#include "NumRandom.hpp"

using namespace SSDK;

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constructor & destructor

NumRandom::NumRandom()
{
    try
    {

    }
    catch(...)
    {
        THROW_EXCEPTION("构造函数出错");
    }
}

NumRandom::~NumRandom()
{

}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// member function

double NumRandom::randomDouble(double min, double max)
{
    if(max >= min)
    {
        double randomNum = (rand() / (double)RAND_MAX) * (max - min);
        return randomNum;
    }
    else
    {
         THROW_EXCEPTION("生成随机数异常:最大值小于最小值!")
    }
}

int NumRandom::randomInt(int min, int max)
{
    if(max >= min)
    {
        return (rand() % (max - min) + min);
    }
    else
    {
         THROW_EXCEPTION("生成随机数异常:最大值小于最小值!")
    }
}

bool NumRandom::randomBool(double falseProbability)
{
    if(falseProbability >= 0 && falseProbability <= 1)
    {
        if( (rand() % 100) < falseProbability * 100 )
        {
            return false;
        }

        return true;
    }

    THROW_EXCEPTION("生成随机的bool值出错：传入参数异常");
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
