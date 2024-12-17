QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clothingitemswindow.cpp \
    closetwindow.cpp \
    croppingwindow.cpp \
    main.cpp \
    mainmenuwindow.cpp \
    loginwindow.cpp \
    outfitswindow.cpp \
    popup1.cpp \
    closetmanager.cpp \
    clothingitem.cpp \
    Top.cpp \
    Bottom.cpp \
    Shoes.cpp \
    Coat.cpp \
    outfit.cpp \
    JSONManager.cpp \
    ClickableLabel.cpp

HEADERS += \
    clothingitemswindow.h \
    closetwindow.h \
    croppingwindow.h \
    global.h \
    loginwindow.h \
    mainmenuwindow.h \
    outfitswindow.h \
    popup1.h \
    closetmanager.h \
    clothingitem.h \
    top.h \
    bottom.h \
    shoes.h \
    coat.h \
    outfit.h \
    jsonmanager.h \
    clickablelabel.h

FORMS += \
    clothingitemswindow.ui \
    closetwindow.ui \
    croppingwindow.ui \
    loginwindow.ui \
    mainmenuwindow.ui \
    outfitswindow.ui \
    popup1.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
