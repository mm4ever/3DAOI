#ifndef SEQUENCER_HPP
#define SEQUENCER_HPP

#include "InspectionManager.hpp"
#include "UIManager.hpp"

namespace APP
{
    class Sequence
    {
    public:

        //>>>-------------------------------------------------------------------
        // constructor & destructor

        Sequence();
        virtual~Sequence();

        //>>>------------------------------------------------------------------
        // member function

        void init();
        void inspectCycle();


    private:
        //>>>-----------------------------------------------------------------------
        // member variant

        Job::InspectionManager m_inspectionManager;
        UiManager m_uiManager;

        //<<<-------------------------------------------------------------------
    };
}//End of namespace APP


#endif // SEQUENCER_HPP
