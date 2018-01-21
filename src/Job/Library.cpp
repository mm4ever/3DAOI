#include "Library.hpp"

using namespace Job;

using namespace std;

//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// constructor & destructor

Library::Library()
{
    try
    {

    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Constructor error!");
}

Library::~Library()
{
    try
    {

    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Destructor error!");
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// member function

bool Library::inspect()
{
    try
    {
        if(false == this->mainItem().inspect())
        {
            return false;
        }

        std::list<SubItem>::iterator iterator = this->m_subItems.begin();

        while (iterator != this->m_subItems.end())  //调用每个检测item的检测函数
        {
            if( false == (*iterator).inspect() )
            {
                return false;
            }
            ++iterator;
        }

        return true;
    }
    CATCH_AND_RETHROW_EXCEPTION_WITH_OBJ("Inspect error!");
}

//<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
