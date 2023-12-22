#include "task.h"

Task::Task(QObject *parent)
    : QObject{parent}
{
    qInfo() << "Constructed" << this << "on" << QThread::currentThread();
}

Task::~Task()
{
    qInfo() << "Destructed" << this << "on" << QThread::currentThread() << "\n";
}

void Task::run()
{
    QThread *thread = QThread::currentThread();
    qInfo() << "\nStarting" << thread;

    for (int i = 0; i < 3; ++i) {
        qInfo() << i << "on" << thread;
    }
    qInfo() << "Finished" << thread;
}












