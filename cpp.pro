QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    andy.cpp \
    brick.cpp \
    bullet.cpp \
    castle.cpp \
    diamond.cpp \
    fire.cpp \
    flagsystem.cpp \
    flower.cpp \
    gamehelp.cpp \
    gamepause.cpp \
    global.cpp \
    level1.cpp \
    level2.cpp \
    level3.cpp \
    main.cpp \
    mainwindow.cpp \
    master.cpp \
    mushroom.cpp \
    musicplayer.cpp \
    mypushbutton.cpp \
    pipe.cpp \
    setting.cpp \
    unknown.cpp \
    weed.cpp

HEADERS += \
    andy.h \
    brick.h \
    bullet.h \
    castle.h \
    diamond.h \
    fire.h \
    flagsystem.h \
    flower.h \
    gamehelp.h \
    gamepause.h \
    global.h \
    level1.h \
    level2.h \
    level3.h \
    mainwindow.h \
    master.h \
    mushroom.h \
    musicplayer.h \
    mypushbutton.h \
    pipe.h \
    setting.h \
    unknown.h \
    weed.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
