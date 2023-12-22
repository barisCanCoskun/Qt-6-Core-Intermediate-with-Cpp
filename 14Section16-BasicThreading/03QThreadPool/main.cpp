/*
 * Thread Pools
 * Why
 * We want to run more than one thread
 * And we want it NOW
 * How
 * QThreadPool
 *
 */
#include <QCoreApplication>
#include <QThread>
#include <QThreadPool>
#include "task.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");
    qInfo() << "Starting work" << QThread::currentThread();

    qInfo() << "Max Threads" << QThreadPool::globalInstance()->maxThreadCount();

    for (int i = 0; i < 5; ++i) {
        Task *task = new Task();
        // in help:
        // QThreadPool takes ownership and deletes 'task' automatically
//        task->setAutoDelete(true);  // this is part of QRunnable
        // we're telling the thread pool go ahead and delete this when you're done it.

        QThreadPool::globalInstance()->start(task);
    }

    qInfo() << "Free to do other things..." << QThread::currentThread();

    return a.exec();
}
















