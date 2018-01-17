#ifndef MEASUREDOBJ_HPP
#define MEASUREDOBJ_HPP

#include "CustomException.hpp"
#include "IInspection.hpp"
#include "Rectangle.hpp"
#include "Library.hpp"

namespace Job
{
    /**
     *  @brief MeasuredObj
     *          表示一个检测过的目标的类，存有以下信息：
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
    class MeasuredObj
    {
    public:

        enum class MeasuredObjType
        {
            FIDUCIALMARK,
            COMPONENT
        };

        //>>>-----------------------------------------------------------------------
        // constructor & destructor

        /**
        *  @brief   默认构造函数
        *  @param   N/A
        *  @return  N/A
        */
        MeasuredObj();

        /**
        *  @brief   析构函数
        *  @param   N/A
        *  @return  N/A
        */
        virtual ~MeasuredObj();

        //>>>-----------------------------------------------------------------------
        // set & get function

        int id(){return this->m_id;}
        void setId(int id){this->m_id = id;}

        bool isResultOk(){return this->m_isResultOk;}

        std::string& name() {return this->m_name;}

        SSDK::Rectangle& rectangle(){return this->m_rectangle;}

        Library& lib(){return this->m_lib;}

        MeasuredObjType measuredObjType() {return this->m_measuredObjType;}

        //>>>-----------------------------------------------------------------------
        // member function

        /**
        *  @brief   模拟元件的检测并记录检测结果
        *  @param   N/A
        *  @return  N/A
        */
        virtual void inspect();


    protected:

        //>>>-----------------------------------------------------------------------
        // member variant

        int m_id{0};
        bool m_isResultOk{false};           //检测元件的检测结果是否为OK
        std::string m_name{"\0"};
        SSDK::Rectangle m_rectangle;
        Library m_lib;
        MeasuredObjType m_measuredObjType;  //类为检测目标基类，故需要记录检测目标类型

        //<<<-----------------------------------------------------------------------
    };

}//End of namespace Job

#endif // MEASUREDOBJ_HPP
