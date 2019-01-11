QT       += core gui

TARGET = 0_OpenGLWindow
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    window.cpp

HEADERS += \
    window.h \
    vertex.h \

RESOURCES += \
    resource.qrc
