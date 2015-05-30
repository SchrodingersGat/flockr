#-------------------------------------------------
#
# Project created by QtCreator 2015-05-26T12:10:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = flkr
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    animal.cpp \
    FlockWidget.cpp

HEADERS  += mainwindow.h \
    animal.h \
    FlockWidget.h

FORMS    += mainwindow.ui
