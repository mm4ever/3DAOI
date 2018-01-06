#ifndef ITEM_HPP
#define ITEM_HPP

#include "Alg.hpp"
#include "Rectangle.hpp"

namespace Job
{
    /**
     *  @brief Item
     *
     *  @author lynn
     *  @version 1.00 2018-01-05 lynn
     *                note:create it
     */
    class Item
    {
    public:

        //>>>-----------------------------------------------------------------------
        // constructor & destructor

        Item();

        virtual ~Item();

        //>>>-----------------------------------------------------------------------
        // set & get function

        int libId() {return this->m_libID;}
        void setLibId(int libId){this->m_libID = libId;}

        int id() {return this->m_id;}
        void setId(int id){this->m_id = id;}

        SSDK::Rectangle& rectangle(){return this->m_rectangle;}

        std::string name(){return this->m_name;}

        Alg* pAlg() {return this->m_pAlg;}

        //>>>-----------------------------------------------------------------------
        //member function

        bool inspect();


    private:

        //>>>-----------------------------------------------------------------------
        //member variant

        int m_libID{0};
        int m_id{0};
        SSDK::Rectangle m_rectangle;    //此处的位置表示中心点和元件中心点的相对位置
        std::string m_name;
        Alg* m_pAlg;

        //<<<-----------------------------------------------------------------------
    };

}//End of namespace Job

#endif // ITEM_HPP
