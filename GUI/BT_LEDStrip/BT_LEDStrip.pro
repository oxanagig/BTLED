#-------------------------------------------------
#
# Project created by QtCreator 2015-01-29T16:39:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

greaterThan(QT_MAJOR_VERSION, 4) {
    QT       += widgets serialport
} else {
    include($$QTSERIALPORT_PROJECT_ROOT/src/serialport/qt4support/serialport.prf)
}

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BT_LEDStrip
TEMPLATE = app


SOURCES += main.cpp\
        mywidget.cpp

HEADERS  += mywidget.h

FORMS    += mywidget.ui

