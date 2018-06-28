#include "spellmodel.h"
#include "spell.h"

SpellModel::SpellModel(QObject *parent)
    : QAbstractListModel(parent), m_spell(nullptr)
{

}

SpellList *SpellModel::spell() const
{
    return m_spell;
}

void SpellModel::setSpell(SpellList *spell){
    beginResetModel();

    if (m_spell)
        m_spell->disconnect(this);
    m_spell = spell;

    endResetModel();

}

QHash<int, QByteArray> SpellModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[SpellName] = "name";
    roles[Characters] = "characters";
    roles[School] = "school";
    roles[Target] = "target";
    roles[Range] = "range";
    roles[CastingTime] = "castingTime";
    roles[Summary] = "summary";
    roles[Spell] = "spell";

    return roles;
}

int SpellModel::rowCount(const QModelIndex &parent) const
{
    if ( parent.isValid())
        return 0;

    return m_spell->count();
}

QVariant SpellModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    auto spell = m_spell->at(index.row());

    switch (role) {
    case SpellName:
        return spell->name();
    case Characters:
    {
        QString res;
        foreach (QString c, spell->characters()) {
            res.append(c);
            res.append(", ");
        }
        return res;
    }
    case School:
        return spell->school();
    case Target:
        return spell->target();
    case Range:
        return spell->range();
    case CastingTime:
        return spell->castingTime();
    case Summary:
        return spell->summary();
    case Spell:
        return QVariant::fromValue(spell);
    default:
        break;
    }
    return QVariant();
}



