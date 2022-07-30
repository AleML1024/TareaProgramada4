QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    formagregarproducto.cpp \
    formeliminarproducto.cpp \
    formmodificarproducto.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    formagregarproducto.h \
    formeliminarproducto.h \
    formmodificarproducto.h \
    mainwindow.h

FORMS += \
    formagregarproducto.ui \
    formeliminarproducto.ui \
    formmodificarproducto.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../libTienda/release/ -llibTienda
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../libTienda/debug/ -llibTienda
else:unix: LIBS += -L$$OUT_PWD/../libTienda/ -llibTienda

INCLUDEPATH += $$PWD/../libTienda
DEPENDPATH += $$PWD/../libTienda

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libTienda/release/liblibTienda.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libTienda/debug/liblibTienda.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libTienda/release/libTienda.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libTienda/debug/libTienda.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../libTienda/liblibTienda.a
