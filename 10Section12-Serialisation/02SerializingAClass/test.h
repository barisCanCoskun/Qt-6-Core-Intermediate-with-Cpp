#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>
#include <QMap>
#include <QDataStream>

class Test : public QObject
{
    Q_OBJECT
    QString m_name;
    QMap<QString, QString> m_map;
public:
    explicit Test(QObject *parent = nullptr);
    void fill();
    QString getName();
    void setName(QString n);
    QMap<QString, QString> getMap();
    friend QDataStream &operator<<(QDataStream &os, const Test &t);
    friend QDataStream &operator>>(QDataStream &os, Test &t);

signals:

};

#endif // TEST_H






