#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <list>

#include "Inspection.hpp"
#include "CustomException.hpp"
#include "MainItem.hpp"
#include "SubItem.hpp"

namespace Job
{
    /**
     *  @brief Library
     *
     *  @author lynn
     *  @version 1.00 2018-01-05 lynn
     *                note:create it
     */
    class Library:private Inspection
    {
    public:

        //>>>-----------------------------------------------------------------------
        // constructor & destructor

        /**
        *  @brief   默认构造函数
        *  @param   N/A
        *  @return  N/A
        */
        Library();

        /**
        *  @brief   析构函数
        *  @param   N/A
        *  @return  N/A
        */
        virtual ~Library();

        //>>>-----------------------------------------------------------------------
        // set & get function

        int id(){return this->m_id;}
        void setId(int id){this->m_id = id;}

        std::string& name(){return this->m_name;}

        MainItem& mainItem(){return this->m_mainItem;}

        std::list<SubItem>& itemList(){return this->m_itemList;}

        //>>>-----------------------------------------------------------------------
        // override function

        /**
        *  @brief   模拟Library的检测返回结果
        *  @param   N/A
        *  @return  true    ：表示检测结果为好的
        *           false   ：表示检测结果不是好的
        */
        virtual bool inspect() override;


    private:

        //>>>-----------------------------------------------------------------------
        // member variant

        int m_id{0};
        std::string m_name;
        MainItem m_mainItem;
        std::list<SubItem> m_itemList;        //TBCL:改名

        //<<<-----------------------------------------------------------------------
    };

}//End of namespace Job

#endif // LIBRARY_HPP
