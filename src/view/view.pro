QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../controller/controller.cpp \
    ../model/model.cpp \
    credit_calc.cpp \
    deposit_calc.cpp \
    graph.cpp \
    main.cpp \
    qcustomplot.cpp \
    table.cpp \
    view.cpp

HEADERS += \
    ../controller/controller.h \
    ../model/model.h \
    credit_calc.h \
    deposit_calc.h \
    graph.h \
    qcustomplot.h \
    table.h \
    view.h

FORMS += \
    credit_calc.ui \
    deposit_calc.ui \
    graph.ui \
    table.ui \
    view.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
