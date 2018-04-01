#-------------------------------------------------
#
# Project created by QtCreator 2017-10-04T18:23:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = reminder
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    activity.cpp \
    activitydialog.cpp \
    popup.cpp \
    activitylist.cpp

HEADERS  += mainwindow.h \
    activity.h \
    activitydialog.h \
    popup.h \
    activitylist.h

FORMS    += mainwindow.ui \
    activitydialog.ui \
    activitylist.ui

RESOURCES += \
    resources.qrc \
    ../qdarkstyle/style.qrc
