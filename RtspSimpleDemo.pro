#-------------------------------------------------
#
# Project created by QtCreator 2016-07-18T13:53:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RtspSimpleDemo
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    qffmpeg.cpp \
    rtspthread.cpp

HEADERS  += widget.h \
    qffmpeg.h \
    rtspthread.h

FORMS    += widget.ui

INCLUDEPATH +=  ffmpeg/include
LIBS += ffmpeg\lib\libavcodec.dll.a \
        ffmpeg/lib/libavfilter.dll.a \
        ffmpeg/lib/libavformat.dll.a \
        ffmpeg/lib/libswscale.dll.a \
        ffmpeg/lib/libavutil.dll.a \





DESTDIR=bin


