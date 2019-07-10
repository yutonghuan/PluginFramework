QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = main
CONFIG -= app_bundle

TEMPLATE = app

TRANSLATIONS += main.ts

DESTDIR += ../../bin
include(../include/include.pri)

CONFIG(debug, debug|release){
    LIBS += -L$$PWD/../libs/debug  -lCTKCore -lCTKPluginFramework
}else{
    LIBS += -L$$PWD/../libs/release  -lCTKCore -lCTKPluginFramework
}

HEADERS += \
    cstatuswidget.h \
    ctitletoolbar.h \
    widget.h \
    ccentralwidget.h

SOURCES += main.cpp \
    cstatuswidget.cpp \
    ctitletoolbar.cpp \
    widget.cpp \
    ccentralwidget.cpp


RESOURCES += \
    resource.qrc


