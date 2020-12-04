#-------------------------------------------------
#
# Project created by QtCreator 2018-06-24T21:19:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
RC_FILE = res.rc
TARGET = graph
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog1.cpp \
    dialog2.cpp \
    dialogaddedge.cpp \
    dialogdeleteedge.cpp \
    graph2.cpp \
    graph1.cpp \
    help.cpp

HEADERS  += mainwindow.h \
    dialog1.h \
    dialog2.h \
    dialogaddedge.h \
    dialogdeleteedge.h \
    graph2.h \
    graph1.h \
    help.h

FORMS    += mainwindow.ui \
    dialog1.ui \
    dialog2.ui \
    dialogaddedge.ui \
    dialogdeleteedge.ui \
    help.ui

RESOURCES += \
    res.qrc
CONFIG += C++11
