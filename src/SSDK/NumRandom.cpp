#include "NumRandom.hpp"

using namespace SSDK;

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constructor & destructor

NumRandom::NumRandom()
{
    try
    {

    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Costructor error!");
}

NumRandom::~NumRandom()
{
    try
    {

    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Destructor error!");
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
         THROW_EXCEPTION("Max smaller than min!")
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
         THROW_EXCEPTION("Max smaller than min!")
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

    THROW_EXCEPTION("Parameter error!");
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
