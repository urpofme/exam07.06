QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += $$PWD/../hallServer/include/

SUBDIRS += \
    ../hallServer/hallServer.pro

HEADERS += \
    include/ClientCore.h \

SOURCES += \
    src/tst_heapsorttest.cpp\
    src/HeapSortTest.cpp

