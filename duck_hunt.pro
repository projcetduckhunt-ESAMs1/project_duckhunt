TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

LIBS += `sdl-config --libs` -lSDLmain -lSDL -lSDL_image -lSDL_ttf
INCLUDEPATH += /usr/include/SDL

OTHER_FILES += \
    backGame.bmp
