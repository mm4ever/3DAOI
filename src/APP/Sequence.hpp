#ifndef SEQUENCER_HPP
#define SEQUENCER_HPP

#include "InspectionManager.hpp"
#include "UIManager.hpp"
#include "CustomException.hpp"

namespace APP
{
    /**
     *  @brief Sequence
     *          Sequence类组合了检测数据的类和界面管理的类
     *  通过init()函数进行类成员的初始化.
     *
     *  @author peter
     *  @version 1.00 2018-01-06 peter
     *                note:create it
     */
    class Sequence
    {
    public:

        //>>>-------------------------------------------------------------------
        // constructor & destructor

        Sequence();
        virtual~Sequence();

        //>>>------------------------------------------------------------------
        // get & set function

        Job::InspectionManager inspectionManager(){return this->m_inspectionManager;}

        UIManager uiManager(){return this->m_uiManager;}

        //>>>------------------------------------------------------------------
        // member function

        /**
         * @brief init
         *     初始化类成员变量
         *  1.初始化检测数据的类
         *  2.初始化界面管理的类
         * @param N/A
         * @return N/A
         */
        void init();
        void inspectCycle();


    private:
        //>>>-----------------------------------------------------------------------
        // member variant

        Job::InspectionManager m_inspectionManager;
        UIManager m_uiManager;

        //<<<-------------------------------------------------------------------
    };
}//End of namespace APP


#endif // SEQUENCER_HPP
