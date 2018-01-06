#ifndef BOARD_HPP
#define BOARD_HPP

#include "Point.hpp"
#include "Rectangle.hpp"
#include "MeasuredObj.hpp"

namespace Job
{

    /**
     *  @brief Board
     *
     *  @author lynn
     *  @version 1.00 2018-01-05 lynn
     *                note:create it
     */
    class Board
    {
    public:

        //>>>-----------------------------------------------------------------------
        // constructor & destructor

        Board();

        virtual ~Board();

        //>>>-----------------------------------------------------------------------
        // set & get function

        std::string& name(){return this->m_name;}

        std::vector<MeasuredObj *>& pObjs(){return this->m_pObjs;}

        SSDK::Point& originPoint(){return this->m_originPoint;}

        SSDK::Rectangle& rectangle(){return this->m_recatangle;}

        //>>>-----------------------------------------------------------------------
        // member function

        void writeToXml(std::string& path);

        void inspect();


    private:

        //>>>-----------------------------------------------------------------------
        // comment variant

        std::string m_name;
        std::vector<MeasuredObj*> m_pObjs;
        SSDK::Point m_originPoint;
        SSDK::Rectangle m_recatangle;

        //<<<-----------------------------------------------------------------------
    };

}//End of namespace Job

#endif // BOARD_HPP
