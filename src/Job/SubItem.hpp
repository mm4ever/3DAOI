#ifndef SUBITEM_HPP
#define SUBITEM_HPP

#include "Item.hpp"

namespace Job
{
    /**
     *  @brief SubItem
     *
     *  @author lynn
     *  @version 1.00 2018-01-05 lynn
     *                note:create it
     */
    class SubItem:public Item
    {
    public:

        //>>>-----------------------------------------------------------------------
        // constructor & destructor

        SubItem();

        virtual ~SubItem();

        //>>>-----------------------------------------------------------------------
        // set & get function

        int order() {return this->m_order;}
        void setOrder(int order) {this->m_order = order;}


    private:

        //>>>-----------------------------------------------------------------------
        // member variant

        int m_order{0};

        //<<<-----------------------------------------------------------------------
    };

}//End of namespace Job

#endif // SUBITEM_HPP
