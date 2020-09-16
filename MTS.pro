#-------------------------------------------------
#
# Project created by QtCreator 2020-08-31T15:47:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MTS
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        welcomescene.cpp \
    sysstru.cpp \
    mainscene.cpp \
    startchoose.cpp \
    maprefer.cpp \
    chiwan.cpp \
    qianhaiwan.cpp \
    qianwan.cpp \
    baoancenter.cpp \
    xili.cpp \
    univercity.cpp \
    shenzhennorth.cpp \
    huangbeilin.cpp \
    endchoose.cpp \
    tic.cpp \
    paytic.cpp

HEADERS += \
        welcomescene.h \
    sysstru.h \
    mainscene.h \
    startchoose.h \
    maprefer.h \
    chiwan.h \
    qianhaiwan.h \
    qianwan.h \
    baoancenter.h \
    xili.h \
    univercity.h \
    shenzhennorth.h \
    huangbeilin.h \
    endchoose.h \
    tic.h \
    paytic.h

FORMS += \
        welcomescene.ui \
    sysstru.ui \
    mainscene.ui \
    startchoose.ui \
    maprefer.ui \
    chiwan.ui \
    qianhaiwan.ui \
    qianwan.ui \
    baoancenter.ui \
    xili.ui \
    univercity.ui \
    shenzhennorth.ui \
    huangbeilin.ui \
    endchoose.ui \
    tic.ui \
    paytic.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
