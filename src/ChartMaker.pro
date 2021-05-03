QT       += core gui
QT       += charts
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    barchart.cpp \
    barchartdisplay.cpp \
    donutchart.cpp \
    donutchartdisplay.cpp \
    linechart.cpp \
    linechartdisplay.cpp \
    main.cpp \
    mainwindow.cpp \
    piechart.cpp \
    piechartdisplay.cpp \
    stackedbarchart.cpp \
    stackedbarchartdisplay.cpp

HEADERS += \
    barchart.h \
    barchartdisplay.h \
    donutchart.h \
    donutchartdisplay.h \
    linechart.h \
    linechartdisplay.h \
    mainwindow.h \
    piechart.h \
    piechartdisplay.h \
    stackedbarchart.h \
    stackedbarchartdisplay.h

FORMS += \
    barchart.ui \
    barchartdisplay.ui \
    donutchart.ui \
    donutchartdisplay.ui \
    linechart.ui \
    linechartdisplay.ui \
    mainwindow.ui \
    piechart.ui \
    piechartdisplay.ui \
    stackedbarchart.ui \
    stackedbarchartdisplay.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    info.txt
