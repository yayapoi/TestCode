QT       += core gui axcontainer
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG(release, debug|release){
QMAKE_LFLAGS += /MANIFESTUAC:\"level=\'requireAdministrator\' uiAccess=\'false\'\"
}
QMAKE_CFLAGS += /utf-8
QMAKE_CXXFLAGS += /utf-8
SOURCES += \
    clickform.cpp \
    dm/dm.cpp \
    dmobject.cpp \
    encodeing/HexHelper.cpp \
    encodeing/XXTeaHelper.cpp \
    encodeing/encodeobject.cpp \
    globalobject.cpp \
    main.cpp \
    mainwindow.cpp \
    xingyunwin.cpp

HEADERS += \
    clickform.h \
    dm/dm.h \
    dm/dm.tlh \
    dmobject.h \
    encodeing/HexHelper.h \
    encodeing/XXTeaHelper.h \
    encodeing/encodeobject.h \
    globalobject.h \
    mainwindow.h \
    xingyunwin.h

FORMS += \
    clickform.ui \
    mainwindow.ui \
    xingyunwin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    dm/dm.tli
