TEMPLATE = lib

CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Circle.cpp \
    CustomException.cpp \
    FormatConvertor.cpp \
    NumRandom.cpp \
    Rectangle.cpp \
    Shape.cpp \
    Point.cpp \
    DB/Blob.cpp \
    DB/SqlitedDb.cpp

HEADERS += \
    Circle.hpp \
    CustomException.hpp \
    FormatConvertor.hpp \
    NumRandom.hpp \
    Rectangle.hpp \
    Shape.hpp \
    Point.hpp \
    DB/Blob.hpp \
    DB/SqliteDb.hpp

INCLUDEPATH += $$PWD/../../include/sqlite
INCLUDEPATH += $$PWD/../../include

unix::LIBS += -L$$PWD/../lib/ -lsqlite3

unix::LIBS += -L/usr/lib/x86_64-linux-gnu\
-ldl
