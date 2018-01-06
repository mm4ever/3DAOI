#ifndef MEASUREDOBJ_HPP
#define MEASUREDOBJ_HPP

#include "Rectangle.hpp"
#include "Library.hpp"

namespace Job
{

    enum class MeasuredObjType
    {
        FIDUCIALMARK,
        COMPONENT
    };
    /**
     *  @brief MeasuredObj
     *
     *  @author lynn
     *  @version 1.00 2018-01-05 lynn
     *                note:create it
     */
    class MeasuredObj
    {
    public:

        //>>>-----------------------------------------------------------------------
        // constructor & destructor

        MeasuredObj();

        virtual ~MeasuredObj();

        //>>>-----------------------------------------------------------------------
        // set & get function

        int id(){return this->m_id;}
        void setId(int id){this->m_id = id;}

        bool isResultOk(){return this->m_isResultOk;}

        std::string& name() {return this->m_name;}

        SSDK::Rectangle& rectangle(){return this->m_rectangle;}

        Library& lib(){return this->m_lib;}

        MeasuredObjType measuredObjType() {return this->m_measuredObjType;}

        //>>>-----------------------------------------------------------------------
        // member function

        void inspect();


    private:

        //>>>-----------------------------------------------------------------------
        // member variant

        int m_id{0};
        bool m_isResultOk{false};
        std::string m_name;
        SSDK::Rectangle m_rectangle;
        Library m_lib;
        MeasuredObjType m_measuredObjType;

        //<<<-----------------------------------------------------------------------
    };

}//End of namespace Job

#endif // MEASUREDOBJ_HPP
