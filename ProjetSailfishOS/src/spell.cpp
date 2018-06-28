#include "spell.h"

Spell::Spell(QString name, QList<QString> characters, QString school, QString target, QString range, QString castingTime, QString summary, QObject *parent)
    : QObject(parent),
      m_name(name),
      m_characters(characters),
      m_school(school),
      m_target(target),
      m_range(range),
      m_castingTime(castingTime),
      m_summary(summary)
{
    connect(this, &Spell::nameChanged, this, &Spell::spellChanged);
    connect(this, &Spell::charactersChanged, this, &Spell::spellChanged);
    connect(this, &Spell::schoolChanged, this, &Spell::spellChanged);
    connect(this, &Spell::targetChanged, this, &Spell::spellChanged);
    connect(this, &Spell::rangeChanged, this, &Spell::spellChanged);
    connect(this, &Spell::castingTimeChanged, this, &Spell::spellChanged);
    connect(this, &Spell::summaryChanged, this, &Spell::spellChanged);
}

void Spell::setName(QString name){
    if (m_name == name)
        return;

    m_name = name;
    emit nameChanged(m_name);
}

void Spell::setCharacters(QList<QString> characters){
    if (m_characters == characters)
        return;

    m_characters = characters;
    emit charactersChanged(m_characters);
}

void Spell::setSchool(QString school){
    if (m_school == school)
        return;

    m_school = school;
    emit schoolChanged(m_school);
}

void Spell::setTarget(QString target){
    if (m_target == target)
        return;

    m_target = target;
    emit targetChanged(m_target);
}

void Spell::setRange(QString range){
    if (m_range == range)
        return;

    m_range = range;
    emit rangeChanged(m_range);
}

void Spell::setCastingTime(QString castingTime){
    if (m_castingTime == castingTime)
        return;

    m_castingTime = castingTime;
    emit castingTimeChanged(m_castingTime);
}

void Spell::setSummary(QString summary){
    if (m_summary == summary)
        return;

    m_summary = summary;
    emit summaryChanged(m_summary);
}
