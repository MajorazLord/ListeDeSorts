#ifndef MANAGER_H
#define MANAGER_H

#include <QList>
#include <QtXml/QDomDocument>
#include <QObject>
#include "spell.h"

using namespace std;

QList<Spell*> parserXML(QDomDocument dom);
bool checkXML(QDomDocument dom);


#endif // MANAGER_H
