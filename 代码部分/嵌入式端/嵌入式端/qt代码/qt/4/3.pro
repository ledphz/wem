#-------------------------------------------------
#
# Project created by QtCreator 2019-01-06T16:34:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    all_file.cpp \
    look.cpp \
    feel.cpp \
    log_i.cpp \
    history.cpp \
    threadread.cpp \
    keyBoard.cpp \
    sendtoandriod.cpp

HEADERS  += mainwindow.h \
    all_file.h \
    look.h \
    feel.h \
    log_i.h \
    history.h \
    threadread.h \
    sqlite/sqlite3.h \
    keyBoard.h \
    sendtoandriod.h

FORMS    += mainwindow.ui \
    all_file.ui \
    look.ui \
    feel.ui \
    log_i.ui \
    history.ui

RESOURCES += \
    img.qrc

QT += sql

unix:!macx: LIBS += -L$$PWD/sqlite/ -lsqlite3

INCLUDEPATH += $$PWD/sqlite
DEPENDPATH += $$PWD/sqlite
