TARGET = ProjetSailfishOS

CONFIG += sailfishapp

SOURCES += src/ProjetSailfishOS.cpp \
    src/spell.cpp \
    src/spelllist.cpp \
    src/spellmodel.cpp \
    src/manager.cpp

DISTFILES += qml/ProjetSailfishOS.qml \
    qml/cover/CoverPage.qml \
    qml/pages/FirstPage.qml \
    qml/pages/SecondPage.qml \
    rpm/ProjetSailfishOS.changes.in \
    rpm/ProjetSailfishOS.changes.run.in \
    rpm/ProjetSailfishOS.spec \
    rpm/ProjetSailfishOS.yaml \
    translations/*.ts \
    ProjetSailfishOS.desktop

SAILFISHAPP_ICONS = 86x86 108x108 128x128 172x172

CONFIG += sailfishapp_i18n

HEADERS += \
    src/spell.h \
    src/spelllist.h \
    src/spellmodel.h \
    src/manager.h

RESOURCES += \
    resources.qrc

QT += xml
