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
    socketthread.cpp \
    mainmenu.cpp \
    mainview.cpp \
    socketwidget.cpp

HEADERS  += mainwindow.h \
    socketthread.h \
    mainmenu.h \
    mainview.h \
    socketwidget.h

FORMS    += mainwindow.ui \
    socketwidget.ui
