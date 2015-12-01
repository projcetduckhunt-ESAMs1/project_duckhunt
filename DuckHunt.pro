TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    duck.cc \
    level.cc

include(deployment.pri)
qtcAddDeployment()

LIBS += `sdl-config --libs` -lSDLmain -lSDL -lSDL_image -lSDL_ttf
INCLUDEPATH += /usr/include/SDL

HEADERS += \
    duck.h \
    level.h
