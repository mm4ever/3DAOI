TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

SOURCES += \
    main.cpp \
    AppService.cpp \
    AppSetting.cpp \
    LoginWnd.cpp \
    MainWnd.cpp \
    PathSetting.cpp \
    Sequence.cpp \
    StartupWnd.cpp \
    UIManager.cpp \
    GlobalVariable.cpp

HEADERS += \
    AppService.hpp \
    AppSetting.hpp \
    LoginWnd.hpp \
    MainWnd.hpp \
    PathSetting.hpp \
    Sequence.hpp \
    StartupWnd.hpp \
    UIManager.hpp \
    GlobalVariable.hpp

include(dependencies.pri)
