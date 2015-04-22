#-------------------------------------------------
#
# Project created by QtCreator 2013-12-04T22:12:04
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = openGLApp
TEMPLATE = app


SOURCES += main.cpp\
        openglapp.cpp \
    mypanelopengl.cpp \
    MatrixMath.cpp

HEADERS  += openglapp.h \
    mypanelopengl.h \
    MatrixMath.h \

FORMS    += openglapp.ui

OTHER_FILES += \
    vertexShader.vsh \
    fragmentShader.fsh

RESOURCES += resources.qrc

