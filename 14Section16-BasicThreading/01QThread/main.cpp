/*
 * Threads intro
 * Why
 * We need to understand threads
 * How
 * view our current thread
 */

// Q1-Why use threads ?
// Execute multiple instructions at the same time.

// Q2-Threads are non-blocking: True

// Q3-Async code can be single or multiple-threaded: True



#include <QCoreApplication>
#include <QThread>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread *thread = QThread::currentThread();
    thread->setObjectName("Main Thread");

    qInfo() << "Starting" << thread;

    for (int i = 0; i < 10; ++i) {
        qInfo() << i << "on" << thread;
    }
    qInfo() << "Finished" << thread;

    return a.exec();
}






