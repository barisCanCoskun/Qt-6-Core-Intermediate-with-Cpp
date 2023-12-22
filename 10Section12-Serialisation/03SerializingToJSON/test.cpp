#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{

}

void Test::fill()
{
    m_name = "test object";
    for (int i = 0; i < 10; ++i) {
        QString key = "Key: " + QString::number(i);
        QString value = "This is item number: " + QString::number(i);
        m_map.insert(key, value);
    }
}

QString Test::getName()
{
    return m_name;
}

void Test::setName(QString n)
{
    m_name = n;
}

QMap<QString, QString> Test::getMap()
{
    return m_map;
}

void Test::setMap(QMap<QString, QString> newMap)
{
    m_map = newMap;
}

QDataStream &operator<<(QDataStream &os, const Test &t)
{
    qInfo() << "Operator <<";
    os << t.m_name;
    os << t.m_map;
    return os;
}

QDataStream &operator>>(QDataStream &os, Test &t)
{
    qInfo() << "Operator >>";
    os >> t.m_name;
    os >> t.m_map;
    return os;
}








