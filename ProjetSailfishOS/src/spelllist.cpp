#include "spelllist.h"
#include "spell.h"
#include "manager.h"

SpellList::SpellList(QString nameOfFile, QObject *parent) : QObject(parent)
{
    //utiliser le parseur et remplir m_spells
    QDomDocument dom(nameOfFile);
    if(checkXML(dom) == true){
        m_spells = parserXML(dom);
    }
}

Spell *SpellList::at(int place) const
{
    return m_spells.at(place);
}

int SpellList::count() const
{
    return m_spells.count();
}
