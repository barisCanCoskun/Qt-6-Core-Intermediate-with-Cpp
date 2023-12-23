/*
 * Assignment14
 * Run a function using Qt concurrent
 *
 */

#include <QCoreApplication>
#include <QtConcurrent>     // have to add concurrennt library to CMake
#include <QThread>
#include <QFuture>

void test(){
    qInfo() << "Hello world" << QThread::currentThread();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFuture<void> future = QtConcurrent::run(&test);


    return a.exec();
}
















