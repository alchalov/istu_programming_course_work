QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialogabout.cpp \
    dialogstudentbyrecord.cpp \
    dialogstudentbytask.cpp \
    dialogstudentbyunassignedtask.cpp \
    dialogstudentbyvariantandsumscore.cpp \
    main.cpp \
    mainwindow.cpp \
    studenttasks.cpp

HEADERS += \
    dialogabout.h \
    dialogstudentbyrecord.h \
    dialogstudentbytask.h \
    dialogstudentbyunassignedtask.h \
    dialogstudentbyvariantandsumscore.h \
    mainwindow.h \
    studenttasks.h

FORMS += \
    dialogabout.ui \
    dialogstudentbyrecord.ui \
    dialogstudentbytask.ui \
    dialogstudentbyunassignedtask.ui \
    dialogstudentbyvariantandsumscore.ui \
    mainwindow.ui

TRANSLATIONS += \
    istu_programming_course_work_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
