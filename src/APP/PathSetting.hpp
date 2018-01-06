#ifndef PATHSETTING_HPP
#define PATHSETTING_HPP

#include <iostream>

namespace APP
{
    class PathSetting
    {
    public:

        //>>>-------------------------------------------------------------------
        // constructor & destructor

        PathSetting();
        virtual~PathSetting();

        //>>>-------------------------------------------------------------------
        // set & get function

        std::string appSettingPath(){return this->m_appSettingPath;}
        std::string lotInfoPath(){return this->m_lotInfoPath;}
        std::string defaultJobRolderPath(){return this->m_defaultJobFolderPath;}
        std::string inspectionSettingPath(){return this->m_inspectionSettingPath;}


    private:

        //>>>-------------------------------------------------------------------
        // member variant

        std::string m_appSettingPath {""};
        std::string m_lotInfoPath {""};
        std::string m_defaultJobFolderPath {""};
        std::string m_inspectionSettingPath {""};

        //<<<-------------------------------------------------------------------

    };
}// End of namespace APP

#endif // PATHSETTING_HPP
