TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    x64/include/include.am

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/x64/lib/release/ -levent
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/x64/lib/debug/ -levent

INCLUDEPATH += $$PWD/''
DEPENDPATH += $$PWD/''

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/x64/lib/release/ -levent_core
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/x64/lib/debug/ -levent_core

INCLUDEPATH += $$PWD/''
DEPENDPATH += $$PWD/''

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/x64/lib/release/ -levent_extra
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/x64/lib/debug/ -levent_extra

INCLUDEPATH += $$PWD/''
DEPENDPATH += $$PWD/''
