#ifndef CAT_H
#define CAT_H

#include <QObject>
#include<QDebug>
#include<QSharedPointer>
#include"toy.h"

class Cat : public QObject
{
    Q_OBJECT

    QSharedPointer<Toy> m_toy;

public:
    explicit Cat(QObject *parent = nullptr, QString name = "");
    ~Cat();

    void play(QSharedPointer<Toy> toy);

signals:

};

#endif // CAT_H







