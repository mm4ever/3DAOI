#ifndef CAPTURESETTING_HPP
#define CAPTURESETTING_HPP

#include <QString>
#include <QSettings>
#include <QFile>

#include "CustomException.hpp"
#include "FormatConvertor.hpp"

namespace Job
{
    /**
     *  @brief  InspectionSetting
     *          存有以下信息：
     *          相机长宽(单位：像素),相机图像的位数等
     *          具有以下功能:
     *          读取inspectionSetting配置文件并保存信息
     *
     *  @author lynn
     *  @version 1.00 2018-01-05 lynn
     *                note:create it
     */
    class InspectionSetting
    {
    public:

        //图像的位数,表示将从黑到白的颜色映射到2的ImgBit次方个数字
        enum class ImgBit
        {
            BIT8,
            BIT16
        };

        //>>>-----------------------------------------------------------------------
        // constructor & deconstructor

        InspectionSetting();

        virtual ~InspectionSetting();

        //>>>-----------------------------------------------------------------------
        // set & get function

        int imgWidth() {return this->m_imgWidth;}

        int imgHeight() {return this->m_imgHeight;}

        ImgBit imgBit() {return this->m_imgBit;}

        //>>>-----------------------------------------------------------------------
        // member function

        /**
        *  @brief  load
        *          加载配置文件,如果文件不存在或文件数据不正确则抛出异常
        *
        *  @param  path:读取文件的路径,如(../config/CaptureSetting.ini)
        *  @return  N/A
        */
        void load(QString& path);


    private:

        //>>>-----------------------------------------------------------------------
        // member function

        int m_imgWidth{4096};           //图像的宽（单位：像素）
        int m_imgHeight{3072};          //图像的高（单位：像素)
        //图像的位数,表示将从黑到白的颜色映射到2的ImgBit次方个数字
        ImgBit m_imgBit{ImgBit::BIT8};

        //<<<-----------------------------------------------------------------------
    };
} //End of namespace App

#endif // CAPTURESETTING_HPP
