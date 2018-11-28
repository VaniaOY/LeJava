#-------------------------------------------------
#
# Project created by QtCreator 2018-11-14T20:13:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SignalsySlots
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
        mainwindow.cpp \
    administrador.cpp \
    productos.cpp \
    cuernitos.cpp \
    bisquets.cpp \
    pasteles.cpp \
    panfrances.cpp \
    mantecadas.cpp \
    teleras.cpp \
    orejas.cpp \
    bolillos.cpp \
    madalenas.cpp \
    conchas.cpp \
    donas.cpp \
    crepas.cpp \
    carrito.cpp \
    ventas.cpp

HEADERS += \
        mainwindow.h \
    administrador.h \
    productos.h \
    cuernitos.h \
    bisquets.h \
    pasteles.h \
    panfrances.h \
    mantecadas.h \
    teleras.h \
    orejas.h \
    bolillos.h \
    madalenas.h \
    conchas.h \
    donas.h \
    crepas.h \
    carrito.h \
    ventas.h

FORMS += \
        mainwindow.ui \
    administrador.ui \
    productos.ui \
    cuernitos.ui \
    bisquets.ui \
    pasteles.ui \
    panfrances.ui \
    mantecadas.ui \
    teleras.ui \
    orejas.ui \
    bolillos.ui \
    madalenas.ui \
    conchas.ui \
    donas.ui \
    crepas.ui \
    carrito.ui \
    ventas.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    portada.qrc \
    pastel.qrc
