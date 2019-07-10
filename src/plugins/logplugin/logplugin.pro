#-------------------------------------------------
#
# Project created by QtCreator 2019-05-09T22:06:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = logplugin
TEMPLATE = lib
CONFIG += plugin

DESTDIR = ../../../bin/plugins


SOURCES += \
        clogimpl.cpp \
    clogactivator.cpp \
    widget.cpp \
    clogconfigmanager.cpp

HEADERS += \
        clogimpl.h \
    clogactivator.h \
    widget.h \
    clogconfigmanager.h

include(../../include/include.pri)

CONFIG(debug, debug|release){
    LIBS += -L$$PWD/../../libs/debug  -lCTKCore -lCTKPluginFramework -lCTKWidgets
}else{
    LIBS += -L$$PWD/../../libs/release  -lCTKCore -lCTKPluginFramework -lCTKWidgets
}

RESOURCES += \
    resource.qrc

