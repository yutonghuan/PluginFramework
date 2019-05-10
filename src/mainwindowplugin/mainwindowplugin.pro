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

DESTDIR = ../../bin/plugins

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        cmainwindowimpl.cpp \
    cmainwindowactivator.cpp \
    widget.cpp

HEADERS += \
        cmainwindowimpl.h \
    cmainwindowactivator.h \
    widget.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

include(../include/include.pri)

CONFIG(debug, debug|release){
    LIBS += -L$$PWD/../libs/debug  -lCTKCore -lCTKPluginFramework
}else{
    LIBS += -L$$PWD/../libs/release  -lCTKCore -lCTKPluginFramework
}

RESOURCES += \
    resource.qrc

