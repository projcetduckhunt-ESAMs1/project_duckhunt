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

OTHER_FILES += \
    backGame.bmp \
    sprites/viseur.bmp \
    sprites/duck.bmp \
    sprites/backGame.bmp \
    sprites/viseur.png \
    sprites/shot.png \
    sprites/points.png \
    sprites/menu.png \
    sprites/hit.png \
    sprites/duck.png \
    sprites/backGameBlit.png \
    sprites/backGame.png
