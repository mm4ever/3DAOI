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
    UiManager.cpp

HEADERS += \
    App.hpp \
    AppService.hpp \
    AppSetting.hpp \
    LoginWnd.hpp \
    MainWnd.hpp \
    PathSetting.hpp \
    Sequence.hpp \
    StartupWnd.hpp \
    UiManager.hpp

include(dependencies.pri)
