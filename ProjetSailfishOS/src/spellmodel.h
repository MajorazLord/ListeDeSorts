#ifndef SPELLMODEL_H
#define SPELLMODEL_H

#include "spelllist.h"
#include <QAbstractListModel>

class SpellList;

class SpellModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(SpellList *spell READ spell WRITE setSpell)

    SpellList * m_spell;

public:
    explicit SpellModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    SpellList *spell() const;

    void setSpell(SpellList *spell);

    QHash<int, QByteArray> roleNames() const;
    enum {
        SpellName = Qt::UserRole,
        Characters,
        School,
        Target,
        Range,
        CastingTime,
        Summary,
        Spell
    };





};

#endif // SPELLMODEL_H
