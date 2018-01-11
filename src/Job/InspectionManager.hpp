#ifndef INSPECTIONMANAGER_HPP
#define INSPECTIONMANAGER_HPP


#include "InspectionData.hpp"
#include "InspectionSetting.hpp"

namespace Job
{
    /**
     *  @brief InspectionManager
     *
     *  @author lynn
     *  @version 1.00 2018-01-05 lynn
     *                note:create it
     */
    class InspectionManager
    {
    public:

        //>>>-----------------------------------------------------------------------
        //constructor & destructor

        InspectionManager();

        virtual ~InspectionManager();

        //>>>-----------------------------------------------------------------------
        // set & get function

        InspectionData& inspectionData(){return this->m_inspectionData;}

        InspectionSetting& inspectionSetting(){return this->m_inspectionSetting;}

        //>>>-----------------------------------------------------------------------
        // member function

        void init();

        void loadInspectionSetting();

        void loadInspectionData(std::string& path);

        void inspect();


    private:

        //>>>-----------------------------------------------------------------------
        // member variant

        InspectionData m_inspectionData;
        InspectionSetting m_inspectionSetting;

        //<<<-----------------------------------------------------------------------
    };

}//End of namespace Job

#endif // INSPECTIONMANAGER_HPP
