#ifndef INSPECTIONMANAGER_HPP
#define INSPECTIONMANAGER_HPP

#include <QDir>

#include "DB/SqliteDb.hpp"

#include "InspectionData.hpp"
#include "InspectionSetting.hpp"
#include "Component.hpp"
#include "FiducialMark.hpp"

namespace Job
{
    /**
     *  @brief InspectionManager
     *          管理设备检测运行的流程
     *  @author lynn
     *  @version 1.00 2018-01-05 lynn
     *                note:create it
     */
    class InspectionManager
    {
    public:

        //>>>-----------------------------------------------------------------------
        //constructor & destructor

        /**
        *  @brief  构造函数
        *  @param  N/A
        *  @return N/A
        */
        InspectionManager();

        /**
        *  @brief  析构函数
        *  @param  N/A
        *  @return N/A
        */
        virtual ~InspectionManager();

        //>>>-----------------------------------------------------------------------
        // set & get function

        InspectionData& inspectionData(){return this->m_inspectionData;}

        InspectionSetting& inspectionSetting(){return this->m_inspectionSetting;}

        QString& inspectionSettingPath(){return this->m_inspectionSettingPath;}

        //>>>-----------------------------------------------------------------------
        // member function

        /**
        *  @brief init
        *           初始化设备检测参数,如初始化相机长,宽等
        *  @param N/A
        *  @return N/A
        */
        void init();

        /**
        *  @brief  loadInspectionSetting
        *            加载相机设置配置文件,设置设备检测时相机参数
        *  @param  path: 相机配置文件的路径
        *  @return N/A
        */
        void loadInspectionSetting(QString &path);

        /**
        *  @brief  loadInspectionData
        *            加载检测程式的数据
        *  @param  jobPath: 存放检测程式文件的路径
        *  @return N/A
        */
        void loadInspectionData(QString &jobPath);

        /**
        *  @brief inspect
        *           检测基板中所有检测对象
        *  @param  N/A
        *  @return N/A
        */
        void inspect();


    private:

        //>>>-----------------------------------------------------------------------
        // member variant

        InspectionData m_inspectionData;       //检测程式数据
        InspectionSetting m_inspectionSetting; //设备检测时设置,如(设置相机的配置文件)
        QString m_inspectionSettingPath{""};   //设备检测时设置配置文件的路径

        //<<<-----------------------------------------------------------------------
    };

}//End of namespace Job

#endif // INSPECTIONMANAGER_HPP
