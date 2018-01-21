#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "MeasuredObj.hpp"

namespace Job
{
    /**
     *  @brief Component
     *          表示一个检测的元件，存有：
     *          1.id号
     *          2.名字
     *          3.检测结果是否为OK
     *          4.位置和大小信息
     *          5.检测库
     *          6.检测元件类型信息
     *          具有以下功能：
     *          模拟检测并记录检测结果
     *
     *  @author lynn
     *  @version 1.00 2018-01-05 lynn
     *                note:create it
     */
    class Component:public MeasuredObj
    {
    public:

        //>>>-----------------------------------------------------------------------
        // constructor & destructor

        /**
        *  @brief   默认构造函数,将检测的目标类型设置为component
        *  @param   N/A
        *  @return  N/A
        */
        Component();

        /**
        *  @brief 带参构造函数，设置成员变量,并将检测的目标类型设置为component
        *  @param id：元件序号
        *         name：元件名
        *         centralX：元件中心点x坐标
        *       　centralY：元件中心点y坐标
        *       　angle：元件角度
        *         width：元件宽
        *         height：元件长
        *  @return N/A
        */
        Component(int id,
                  std::string name,
                  double centralX,
                  double centralY,
                  double angle,
                  double width,
                  double height);

        virtual~ Component();

        //>>>-----------------------------------------------------------------------
        //override function

        /**
        *  @brief   模拟元件的检测并记录检测结果
        *  @param   N/A
        *  @return  N/A
        */
        virtual void inspect() override;

        //<<<-----------------------------------------------------------------------
    };

}//End of namespace Job

#endif // COMPONENT_HPP
