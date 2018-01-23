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

        /**
         *  @brief 基板上的检测对象类型
         */
        enum class MeasuredObjType
        {
            FIDUCIALMARK,       //基准点，每个基板上最少有两个，用于定位基板
            COMPONENT           //元件，有很多种类型，统一归类为元件
        };

        //>>>-------------------------------------------------------------------
        // constructor & destructor

        MeasuredObj();

        virtual ~MeasuredObj();

        //>>>-------------------------------------------------------------------
        // set & get function

        int id(){return this->m_id;}
        void setId(int id){this->m_id = id;}

        bool isResultOk(){return this->m_isResultOk;}

        std::string& name() {return this->m_name;}

        SSDK::Rectangle& rectangle(){return this->m_rectangle;}

        Library *pLib(){return this->m_pLib;}
        void setPLib(Library *pLib) {this->m_pLib = pLib;}

        MeasuredObjType measuredObjType() {return this->m_measuredObjType;}

        //>>>-------------------------------------------------------------------
        // member function

        /**
        *  @brief   模拟元件的检测并记录检测结果
        *  @param   N/A
        *  @return  N/A
        */
        virtual void inspect()=0;


    protected:

        //>>>-------------------------------------------------------------------
        // member variant

        int m_id{0};
        bool m_isResultOk{false};           //检测目标的检测结果是否为OK
        std::string m_name{""};
        SSDK::Rectangle m_rectangle;        //与检测目标位置、大小贴合的矩形
        Library* m_pLib{nullptr};           //检测时所用的库
        MeasuredObjType m_measuredObjType;  //类为检测目标基类，故需要记录检测目标类型

        //<<<-------------------------------------------------------------------
    };

}//End of namespace Job

#endif // MEASUREDOBJ_HPP
