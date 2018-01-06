#ifndef INSPECTION_HPP
#define INSPECTION_HPP

namespace Job
{

    class Inspection
    {
    public:

        //>>>-----------------------------------------------------------------------
        // constructor & destructor

        Inspection();

        virtual ~Inspection();

        //>>>-----------------------------------------------------------------------
        // virtual function

        virtual bool inspect();

        //<<<-----------------------------------------------------------------------

    };

}//End of namespace Job

#endif // INSPECTION_HPP
