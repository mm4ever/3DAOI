#ifndef MAINITEM_HPP
#define MAINITEM_HPP

#include "Item.hpp"
#include "Alg3D.hpp"

namespace Job
{
    /**
     *  @brief MainItem
     *          表示一个检测MainItem的类，存有以下信息：
     *              1.所在检测lib的ID
     *              2.当前MainItem的ID
     *              3.与MainItem符合的矩形信息
     *              4.MainItem的名称
     *              5.MainItem使用的算法
     *          具有以下功能：
     *              模拟检测返回检测结果
     *  @author lynn
     *  @version 1.00 2018-01-05 lynn
     *                note:create it
     */
    class MainItem:public Item
    {
    public:

        //>>>-------------------------------------------------------------------
        // constructor & destructor

        /**
        *  @brief   默认构造函数，记录Item类型为MainItem
        *  @param   N/A
        *  @return  N/A
        */
        MainItem();

        virtual ~MainItem();

        //<<<-------------------------------------------------------------------
    };

}//End of namespace Job

#endif // MAINITEM_HPP
