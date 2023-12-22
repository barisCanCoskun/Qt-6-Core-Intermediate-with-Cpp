#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{
    qInfo() << this << "Constructed";
}

Test::~Test()
{
    qInfo() << this << "Destructed";
}

void Test::testing()
{
    QString n{"WAKE UP!!"};
    emit alarm(n);
}

void Test::wake(QString noise)
{
    qInfo() << "\nFrom" << sender() << noise << "\n";
}
//    sender is a special func in QObject
//    that says who is calling this slot









