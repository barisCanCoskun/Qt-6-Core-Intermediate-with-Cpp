/*
 * Run another thread
 * Why
 * We have a powerful computer, letss use it
 * How
 * QThread::moveToThread --> QObject::moveToThread
 *
 */
#include <QCoreApplication>
#include <QThread>
#include <QScopedPointer>
#include "task.h"

// The problem with pointers and threads is
// you cannot set a parent child relationship when you're using QScopedPointer

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");
    QThread worker;
    worker.setObjectName("Worker Thread");

    qInfo() << "Starting work" << QThread::currentThread();

//    Task *task = new Task(&a);
    QScopedPointer<Task> t(new Task());  // Auto delete
    Task *task = t.data();
    task->moveToThread(&worker);  // in help: The object cannot be moved if it has a parent.

    worker.connect(&worker, &QThread::started, task, &Task::work);
//    worker.connect(&worker, &QThread::finished, task, &Task::work);
//    Connect to QThread::finished if you need to know when the thread is done

    worker.start();  // starts on a different thread...
    qInfo() << "Free to do orher things..." << QThread::currentThread();

    return a.exec();
}
















