#ifndef BOARD_HPP
#define BOARD_HPP

#include <QDomDocument>
#include <QFile>
#include <QTextStream>

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

        Board();

        /**
        *  @brief   析构函数,释放所有存放元件用的空间
        *  @param   N/A
        *  @return  N/A
        */
        virtual ~Board();

        //>>>-----------------------------------------------------------------------
        // set & get function

        std::string& name(){return this->m_name;}

        std::vector<MeasuredObj *>& pObjs(){return this->m_pObjs;}

        SSDK::Point& originPoint(){return this->m_originPoint;}

        SSDK::Rectangle& rectangle(){return this->m_recatangle;}

        std::vector<Library*> &pLibs() {return this->m_pLibs;}

        //>>>-----------------------------------------------------------------------
        // member function

        /**
        *  @brief  writeBoardDataToXml
        *           将Board相关数据写入到xml文件,具体信息如下:
        *               1.Board的名字,长,宽,及原点坐标
        *               2.检测出所有错误元件的信息(如元件名称,x,y轴坐标等)
        *  @param  inspectionData : 在insepctionData根节点下创建board信息节点
        *          inspectionDataInfo:将board信息节点添加到inspectionDataInfo节点下
        *  @return N/ A
        */
        void writeBoardDataToXml(QDomDocument& inspectionData,
                                 QDomElement& inspectionDataInfo);

        /**
        *  @brief   检测基板上的所有原件
        *  @param   N/A
        *  @return  N/A
        */
        void inspect();


    private:

        //>>>-----------------------------------------------------------------------
        // comment variant

        std::string m_name{""};
        std::vector<MeasuredObj*> m_pObjs;  //board上的检测对象列表
        SSDK::Point m_originPoint;          //机器原点坐标，检测时以这一点作为board的原点
        SSDK::Rectangle m_recatangle;       //和board大小、位置信息贴合的矩形
        std::vector<Library *> m_pLibs;     //board上所有检测目标用到的库

        //<<<-----------------------------------------------------------------------
    };

}//End of namespace Job

#endif // BOARD_HPP
