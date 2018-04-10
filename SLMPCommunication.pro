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
    socketwidget.cpp \
    background.cpp

HEADERS  += mainwindow.h \
    socketthread.h \
    mainmenu.h \
    mainview.h \
    socketwidget.h \
    background.h

FORMS    += mainwindow.ui \
    socketwidget.ui \
    background.ui

#LIBS +="MyLib.dll"

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Source/build-MyLib-Desktop_Qt_5_4_0_MinGW_32bit-Debug/release/ -lMyLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Source/build-MyLib-Desktop_Qt_5_4_0_MinGW_32bit-Debug/debug/ -lMyLib
else:unix: LIBS += -L$$PWD/../../Source/build-MyLib-Desktop_Qt_5_4_0_MinGW_32bit-Debug/ -lMyLib

INCLUDEPATH += $$PWD/../../Source/build-MyLib-Desktop_Qt_5_4_0_MinGW_32bit-Debug/debug
DEPENDPATH += $$PWD/../../Source/build-MyLib-Desktop_Qt_5_4_0_MinGW_32bit-Debug/debug
