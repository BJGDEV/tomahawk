TEMPLATE = app
TARGET = create_certificate_chain

QT += network

LIBS    += -Wl,-rpath,../../src/certificate -L../../src/certificate -lcertificate
INCLUDEPATH += ../../src/certificate

SOURCES = main.cpp
