#ifndef SPELLLIST_H
#define SPELLLIST_H

#include <QObject>
#include <QList>

class Spell;

class SpellList : public QObject
{
    Q_OBJECT
    QList<Spell*> m_spells;
public:
    explicit SpellList(QString nameOfFile, QObject *parent = nullptr);

    Spell *at(int place) const;
    int count() const;

signals:

public slots:
};

#endif // SPELLLIST_H
