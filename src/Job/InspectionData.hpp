#ifndef INSPECTIONDATA_HPP
#define INSPECTIONDATA_HPP

#include "Board.hpp"

namespace Job
{
    /**
     *  @brief InspectionData存有以下信息：
     *          1.基板及基板上的所有信息
     *          2.检测程式的版本号
     *          3.最后一次修改程式的时间
     *         具有以下功能：
     *          检测本次程式对应的基板
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

        /**
        *  @brief   默认构造函数
        *  @param   N/A
        *  @return  N/A
        */
        InspectionData();

        /**
        *  @brief   析构函数
        *  @param   N/A
        *  @return  N/A
        */
        virtual ~InspectionData();

        //>>>-----------------------------------------------------------------------
        // set & get function

        Board& board(){return this->m_board;}

        std::string& version(){return this->m_version;}

        std::string& lastEditingTime(){return this->m_lastEditingTime;}

        //>>>-----------------------------------------------------------------------
        //member function

        void writeToXml(std::string& path);

        /**
        *  @brief   检测本次程式对应的基板
        *  @param   N/A
        *  @return  N/A
        */
        void inspect();


    private:

        //>>>-----------------------------------------------------------------------
        //member variant

        Board m_board;
        std::string m_version{"\0"};        //检测程式的版本号
        std::string m_lastEditingTime{"\0"};//最后一次修改程式的时间
    };

}//End of namespace Job

#endif // INSPECTIONDATA_HPP
