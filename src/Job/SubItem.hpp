#ifndef SUBITEM_HPP
#define SUBITEM_HPP

#include "CustomException.hpp"
#include "Alg2D.hpp"
#include "Item.hpp"

namespace Job
{
    /**
     *  @brief SubItem
     *          表示一个SubItem的类，存有以下信息：
     *              1.所在lib的ID
     *              2.当前SubItem的ID
     *              3.与SubItem符合的矩形信息
     *              4.SubItem的名称
     *              5.SubItem使用的算法
     *          具有以下功能：
     *              模拟检测返回检测结果
     *  @author lynn
     *  @version 1.00 2018-01-05 lynn
     *                note:create it
     */
    class SubItem:public Item
    {
    public:

        //>>>-----------------------------------------------------------------------
        // constructor & destructor

        /**
        *  @brief   默认构造函数，加入2D检测算法
        *  @param   N/A
        *  @return  N/A
        */
        SubItem();

        /**
        *  @brief   析构函数,释放用于存放算法的空间
        *  @param   N/A
        *  @return  N/A
        */
        virtual ~SubItem();

        //>>>-----------------------------------------------------------------------
        // set & get function

        int order() {return this->m_order;}
        void setOrder(int order) {this->m_order = order;}


    private:

        //>>>-----------------------------------------------------------------------
        // member variant

        int m_order{0};     //记录检测顺序

        //<<<-----------------------------------------------------------------------
    };

}//End of namespace Job

#endif // SUBITEM_HPP
