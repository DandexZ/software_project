QT       += core gui
# 加入SQL模块
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DatabaseManager.cpp \
    main.cpp \
    mainwindow.cpp \
    manager.cpp \
    new_user.cpp \
    show_money.cpp \
    show_user.cpp \
    usrwindow.cpp

HEADERS += \
    DatabaseManager.h \
    mainwindow.h \
    manager.h \
    new_user.h \
    show_money.h \
    show_user.h \
    usrwindow.h

FORMS += \
    mainwindow.ui \
    manager.ui \
    new_user.ui \
    show_money.ui \
    show_user.ui \
    usrwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=  resources.qrc
