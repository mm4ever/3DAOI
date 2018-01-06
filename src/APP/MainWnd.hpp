#ifndef MAINWND_HPP
#define MAINWND_HPP

namespace APP
{
    class MainWnd
    {
    public:

        //>>>-------------------------------------------------------------------
        // constructor & destructor

        MainWnd();
        virtual~MainWnd();

        //>>>-------------------------------------------------------------------
        // member function

        void run();
        void inspect();
        void loadJob();
        void createDefaultJob();

        //<<<-------------------------------------------------------------------

    };
}// End of namespace APP

#endif // MAINWND_HPP
