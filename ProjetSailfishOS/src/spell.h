#ifndef SPELL_H
#define SPELL_H

#include <QObject>

class Spell : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QList<QString> characters READ characters WRITE setCharacters NOTIFY charactersChanged)
    Q_PROPERTY(QString school READ school WRITE setSchool NOTIFY schoolChanged)
    Q_PROPERTY(QString target READ target WRITE setTarget NOTIFY targetChanged)
    Q_PROPERTY(QString range READ range WRITE setRange NOTIFY rangeChanged)
    Q_PROPERTY(QString castingTime READ castingTime WRITE setCastingTime NOTIFY castingTimeChanged)
    Q_PROPERTY(QString summary READ summary WRITE setSummary NOTIFY summaryChanged)

    QString m_name;
    QList<QString> m_characters;
    QString m_school;
    QString m_target;
    QString m_range;
    QString m_castingTime;
    QString m_summary;

public:
    explicit Spell(QString name, QList<QString> characters, QString school, QString target, QString range, QString castingTime, QString summary, QObject *parent = nullptr);


    QString name() const
    {
        return m_name;
    }

    QList<QString> characters() const
    {
        return m_characters;
    }

    QString school() const
    {
        return m_school;
    }

    QString target() const
    {
        return m_target;
    }

    QString range() const
    {
        return m_range;
    }

    QString castingTime() const
    {
        return m_castingTime;
    }

    QString summary() const
    {
        return m_summary;
    }

signals:

    void nameChanged(QString name);
    void charactersChanged(QList<QString> characters);
    void schoolChanged(QString school);
    void targetChanged(QString target);
    void rangeChanged(QString range);
    void castingTimeChanged(QString castingTime);
    void summaryChanged(QString summary);
    void spellChanged();


public slots:
    void setName(QString name);
    void setCharacters(QList<QString> characters);
    void setSchool(QString school);
    void setTarget(QString target);
    void setRange(QString range);
    void setCastingTime(QString castingTime);
    void setSummary(QString summary);

};

#endif // SPELL_H
