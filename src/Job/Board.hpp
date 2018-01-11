#ifndef BOARD_HPP
#define BOARD_HPP

#include "Point.hpp"
#include "Rectangle.hpp"
#include "MeasuredObj.hpp"

namespace Job
{

    /**
     *  @brief Board
     *          表示基板的类，存有以下信息：
     *          1.名称
     *          2.基板上的所有元件列表
     *          3.基板上出错的元件列表
     *          4.原点位置
     *          5.基板的尺寸、位置信息
     *          具有以下功能：
     *          模拟检测并记录NG的元件
     *
     *  @author lynn
     *  @version 1.00 2018-01-05 lynn
     *                note:create it
     */
    class Board
    {
    public:

        //>>>-----------------------------------------------------------------------
        // constructor & destructor

        /**
        *  @brief   默认构造函数
        *  @param   N/A
        *  @return  N/A
        */
        Board();

        /**
        *  @brief   析构函数
        *  @param   N/A
        *  @return  N/A
        */
        virtual ~Board();

        //>>>-----------------------------------------------------------------------
        // set & get function

        std::string& name(){return this->m_name;}

        std::vector<MeasuredObj *>& pObjs(){return this->m_pObjs;}

        std::vector<MeasuredObj *>& pNgObjs(){return this->m_pNgObjs;}

        SSDK::Point& originPoint(){return this->m_originPoint;}

        SSDK::Rectangle& rectangle(){return this->m_recatangle;}

        //>>>-----------------------------------------------------------------------
        // member function

        void writeToXml(std::string& path);

        /**
        *  @brief   检测基板上的所有原件并记录出错的元件
        *  @param   N/A
        *  @return  N/A
        */
        void inspect();


    private:

        //>>>-----------------------------------------------------------------------
        // comment variant

        std::string m_name;
        std::vector<MeasuredObj*> m_pNgObjs;
        std::vector<MeasuredObj*> m_pObjs;
        SSDK::Point m_originPoint;
        SSDK::Rectangle m_recatangle;

        //<<<-----------------------------------------------------------------------
    };

}//End of namespace Job

#endif // BOARD_HPP
