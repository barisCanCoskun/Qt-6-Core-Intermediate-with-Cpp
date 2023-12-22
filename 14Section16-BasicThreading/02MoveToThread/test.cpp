#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{
    qInfo() << "Constructed" << this << "on" << QThread::currentThread();
}

Test::~Test()
{
    qInfo() << "Destructed" << this << "on" << QThread::currentThread();
}

void Test::work()
{
    QThread *thread = QThread::currentThread();
    qInfo() << "Starting" << thread;

    for (int i = 0; i < 3; ++i) {
        qInfo() << i << "on" << thread;
    }
    qInfo() << "Finished" << thread;
}
















