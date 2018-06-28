#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>

#include "spell.h"
#include "spelllist.h"
#include "spellmodel.h"


int main(int argc, char *argv[])
{
    QGuiApplication* app = SailfishApp::application(argc, argv);
    QQuickView *view  = SailfishApp::createView();

    qmlRegisterType<SpellModel>("SpellModel", 1, 0, "SpellModel" );

    SpellList listFromXML("qrc:/spell.xml");

    view->rootContext()->setContextProperty("spellListFromXml", &listFromXML);

    view->setSource(SailfishApp::pathTo("qml/ProjetSailfishOS.qml"));

    view->show();

    return app->exec();
}
