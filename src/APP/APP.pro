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

INCLUDEPATH += $$PWD/../../include/sqlite
INCLUDEPATH += $$PWD/../../include

unix::LIBS += -L$$PWD/../lib/ -lsqlite3

unix::LIBS += -L/usr/lib/x86_64-linux-gnu\
-ldl

include(dependencies.pri)
