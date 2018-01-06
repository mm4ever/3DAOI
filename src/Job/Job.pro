TEMPLATE = lib
CONFIG += console c++11
CONFIG -= app_bundle
QT += core
QT += xml

HEADERS += \
    Alg.hpp \
    Alg2D.hpp \
    Alg3D.hpp \
    Board.hpp \
    Component.hpp \
    FiducialMark.hpp \
    InspectionData.hpp \
    InspectionManager.hpp \
    InspectionSetting.hpp \
    Item.hpp \
    Library.hpp \
    MainItem.hpp \
    MeasuredObj.hpp \
    SubItem.hpp

SOURCES += \
    Alg.cpp \
    Alg2D.cpp \
    Alg3D.cpp \
    Board.cpp \
    Component.cpp \
    FiducialMark.cpp \
    InspectionData.cpp \
    InspectionManager.cpp \
    InspectionSetting.cpp \
    Item.cpp \
    Library.cpp \
    MainItem.cpp \
    MeasuredObj.cpp \
    SubItem.cpp

INCLUDEPATH += $$PWD/../../include
DEPENDPATH += $$PWD/../../include

include(JobDependencies.pri)
