#-------------------------------------------------
#
# Project created by QtCreator 2018-01-02T19:13:15
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SLMPCommunication
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    socketthread.cpp

HEADERS  += mainwindow.h \
    socketthread.h

FORMS    += mainwindow.ui
