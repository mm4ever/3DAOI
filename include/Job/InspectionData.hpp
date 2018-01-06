#ifndef INSPECTIONDATA_HPP
#define INSPECTIONDATA_HPP

#include "Board.hpp"

namespace Job
{
    /**
     *  @brief InspectionData
     *
     *  @author lynn
     *  @version 1.00 2018-01-05 lynn
     *                note:create it
     */
    class InspectionData
    {
    public:

        //>>>-----------------------------------------------------------------------
        // constructor & destructor

        InspectionData();

        virtual ~InspectionData();

        //>>>-----------------------------------------------------------------------
        // set & get function

        Board& board(){return this->m_board;}

        std::string& version(){return this->m_version;}

        std::string& lastEditingTime(){return this->m_lastEditingTime;}

        //>>>-----------------------------------------------------------------------
        //member function

        void writeToXml(std::string& path);

        void inspect();


    private:

        //>>>-----------------------------------------------------------------------
        //member variant

        Board m_board;
        std::string m_version;
        std::string m_lastEditingTime;
    };

}//End of namespace Job

#endif // INSPECTIONDATA_HPP
