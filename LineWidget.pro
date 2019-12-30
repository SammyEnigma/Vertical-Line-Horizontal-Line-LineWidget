QT += core gui widgets

TEMPLATE     = app
TARGET       = LineWidget

HEADERS += \
    HorizontalLine.h \
    LineWidget.h \
    VerticalLine.h \
    mainwindow.h

SOURCES += \
    LineWidget.cpp \
    main.cpp \
    mainwindow.cpp \
    HorizontalLine.cpp \
    VerticalLine.cpp

FORMS += \
    mainwindow.ui
