QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    builder.cpp \
    builder_hut.cpp \
    bullet.cpp \
    castle.cpp \
    defence_unit.cpp \
    enemy.cpp \
    enemyspawner.cpp \
    entry.cpp \
    fence.cpp \
    healthbar.cpp \
    main.cpp \
    mainwindow.cpp \
    myscene.cpp \
    scenes.cpp

HEADERS += \
    Options.h \
    builder.h \
    builder_hut.h \
    bullet.h \
    castle.h \
    countdown.h \
    defence_unit.h \
    enemy.h \
    enemyspawner.h \
    entry.h \
    fence.h \
    healthbar.h \
    mainwindow.h \
    myscene.h \
    scenes.h

FORMS += \
    entry.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Sources.qrc
