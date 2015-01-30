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

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Qt-Color-Picker/build-color_widget_plugin-Desktop_Qt_5_4_0_clang_64bit-Release/release/ -lcolor_widgets
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Qt-Color-Picker/build-color_widget_plugin-Desktop_Qt_5_4_0_clang_64bit-Release/debug/ -lcolor_widgets
else:unix: LIBS += -L$$PWD/../../../Qt-Color-Picker/build-color_widget_plugin-Desktop_Qt_5_4_0_clang_64bit-Release/ -lcolor_widgets

INCLUDEPATH += $$PWD/../../../Qt-Color-Picker/build-color_widget_plugin-Desktop_Qt_5_4_0_clang_64bit-Release
DEPENDPATH += $$PWD/../../../Qt-Color-Picker/build-color_widget_plugin-Desktop_Qt_5_4_0_clang_64bit-Release
