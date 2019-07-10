#-------------------------------------------------
#
# Project created by QtCreator 2019-05-09T22:06:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mainwindowplugin
TEMPLATE = lib
CONFIG += plugin

DESTDIR = ../../../bin/plugins

TRANSLATIONS += mainwindowplugin.ts

SOURCES += \
        cmainwindowimpl.cpp \
    cmainwindowactivator.cpp \
    widget.cpp \
    cstatuswidget.cpp \
    ctitletoolbar.cpp

HEADERS += \
        cmainwindowimpl.h \
    cmainwindowactivator.h \
    widget.h \
    cstatuswidget.h \
    ctitletoolbar.h

include(../../include/include.pri)

CONFIG(debug, debug|release){
    LIBS += -L$$PWD/../../libs/debug  -lCTKCore -lCTKPluginFramework
}else{
    LIBS += -L$$PWD/../../libs/release  -lCTKCore -lCTKPluginFramework
}

RESOURCES += \
    resource.qrc

