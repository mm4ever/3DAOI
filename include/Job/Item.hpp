#ifndef ITEM_HPP
#define ITEM_HPP

#include "CustomException.hpp"
#include "Alg.hpp"
#include "Rectangle.hpp"
#include "IInspection.hpp"

namespace Job
{
    /**
     *  @brief Item
     *          表示一个item的类，存有以下信息：
     *              1.所在lib的ID
     *              2.当前item的ID
     *              3.与item符合的矩形信息
     *              4.item的名称
     *              5.item使用的算法
     *          具有以下功能：
     *              模拟检测返回检测结果
     *  @author lynn
     *  @version 1.00 2018-01-05 lynn
     *                note:create it
     */
    class Item:public IInspection
    {
    public:

        /**
         *  @brief 库中检测框类型
         *
         */
        enum class ItemType
        {
            MAINITEM,       //主检测框,每个检测库最少包含一个主检测框来定位检测对象
            SUBITEM         //辅检测框,每个检测库可以有若干个
        };

        //>>>-------------------------------------------------------------------
        // constructor & destructor

        Item();

        /**
        *  @brief   析构函数,释放用于存放算法的空间
        *  @param   N/A
        *  @return  N/A
        */
        virtual ~Item();

        //>>>-------------------------------------------------------------------
        // set & get function

        int libId() {return this->m_libID;}
        void setLibId(int libId){this->m_libID = libId;}

        int id() {return this->m_id;}
        void setId(int id){this->m_id = id;}

        ItemType itemType(){return this->m_itemType;}

        SSDK::Rectangle& rectangle(){return this->m_rectangle;}

        std::string &name(){return this->m_name;}

        Alg* pAlg() {return this->m_pAlg;}
        void setPAlg(Alg *pAlg) {this->m_pAlg = pAlg;}

        //>>>-------------------------------------------------------------------
        //override function

        /**
        *  @brief   模拟item的检测返回结果
        *  @param   N/A
        *  @return  true    ：表示检测结果为好的
        *           false   ：表示检测结果不是好的
        */
        virtual bool inspect() override;


    protected:

        //>>>-------------------------------------------------------------------
        //member variant

        int m_libID{0};             //所在检测库的ID号
        int m_id{0};
        ItemType m_itemType;        //因Item为检测框基类，故需记录Item的类型
        SSDK::Rectangle m_rectangle;//与item位置、大小贴合的矩形
        std::string m_name{""};
        Alg* m_pAlg{nullptr};       //用于Item的算法

        //<<<-------------------------------------------------------------------
    };

}//End of namespace Job

#endif // ITEM_HPP
