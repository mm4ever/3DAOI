#ifndef LIBRARY_HPP
#define LIBRARY_HPP

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
    class Library
    {
        public:

            //>>>-----------------------------------------------------------------------
            // constructor & destructor

            Library();

            virtual ~Library();

            //>>>-----------------------------------------------------------------------
            // set & get function

            int id(){return this->m_id;}
            void setId(int id){this->m_id = id;}

            std::string& name(){return this->m_name;}

            MainItem& mainItem(){return this->m_mainItem;}

            std::vector<SubItem>& itemList(){return this->m_itemList;}

            //>>>-----------------------------------------------------------------------
            // member function

            bool inspect();


        private:

            //>>>-----------------------------------------------------------------------
            // member variant

            int m_id{0};
            std::string m_name;
            MainItem m_mainItem;
            std::vector<SubItem> m_itemList;

            //<<<-----------------------------------------------------------------------
    };

}//End of namespace Job

#endif // LIBRARY_HPP
