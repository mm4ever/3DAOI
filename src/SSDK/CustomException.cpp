#include "CustomException.hpp"

using namespace SSDK;

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constructor & destructor

CustomException::CustomException(std::string &message)
{
    try
    {
        this->m_originalMsg = message;
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Constructor error!")
}

CustomException::~CustomException()
{
    try
    {

    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Destructor error!")
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

