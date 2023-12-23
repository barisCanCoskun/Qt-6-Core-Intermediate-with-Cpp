/*
 * Signals and slots across threads
 * Why
 * It's not super obvious
 * How
 * Connection Type
 *
 */
#include <QCoreApplication>
#include <QThread>
#include "producer.h"
#include "consumer.h"

void cleanup(){
    // This func is right here, just in case you had some other pointer
    // that was not a QObject that you wanted to clean up.
    // You would actually delete it rigth here in cleanup func...
    qInfo() << "Cleanup";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QThread::currentThread()->setObjectName("Main Thread");

    QThread proThread;  // producer thread
    proThread.setObjectName("Producer Thread");
    Producer *producerPtr = new Producer();
    producerPtr->moveToThread(&proThread);
    // producer obj living on the producer thread
    QObject::connect(&proThread, &QThread::started, producerPtr, &Producer::start);

    QThread conThread;  // consumer thread
    conThread.setObjectName("Consumer Thread");
    Consumer *consumerPtr = new Consumer();
    consumerPtr->moveToThread(&conThread);
    // consumer obj living on the consumer thread

    QObject::connect(producerPtr, &Producer::produce, consumerPtr, &Consumer::consume);
    // Notice producerPtr and consumerPtr are on two different threads.
    // Two seperate threads talking to each other...
    QObject::connect(producerPtr, &Producer::finished, &proThread, &QThread::quit);
    QObject::connect(&proThread, &QThread::finished, &conThread, &QThread::quit);
    QObject::connect(&conThread, &QThread::finished, consumerPtr, &Consumer::deleteLater);
    QObject::connect(&proThread, &QThread::finished, producerPtr, &Producer::deleteLater);
    QObject::connect(&proThread, &QThread::finished, &a, &QCoreApplication::quit);
    QObject::connect(&a, &QCoreApplication::aboutToQuit, &cleanup);

    // Consumer::deleteLater, Producer::deleteLater
    // We have multiple levels of memory management here:
    // parent child relationship, smart pointers, deleteLater, the old C++ way of just calling 'delete'.

    // this is where the confusing bit comes in:
    conThread.start();
    // specific order!
    proThread.start();
    // Notice I'm doing that specific order,
    // we want that consumer ready to go before the producers even loaded
    // simply bec if we start producing values and the consumer's not listening,
    // we're going to start losing values!

    // In Qt5, if it's on a seperate thread,
    // you would have to add Qt::QueuedConnection to the end of each and every connect functions...
//    QObject::connect(producerPtr, &Producer::produce, consumerPtr, &Consumer::consume, Qt::QueuedConnection);

    return a.exec();
}















