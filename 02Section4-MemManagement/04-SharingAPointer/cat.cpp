#include "cat.h"

Cat::Cat(QObject *parent, QString name)
    : QObject{parent}
{
    setObjectName(name);
    qInfo() << this << "Constructed";
}

Cat::~Cat()
{
    qInfo() << this << "Destructed";
}

void Cat::play(QSharedPointer<Toy> toy)
{
//    we want to be able to maintain that reference count
    m_toy.swap(toy);
    qInfo() << this << "Playing with" << m_toy.data();
}








