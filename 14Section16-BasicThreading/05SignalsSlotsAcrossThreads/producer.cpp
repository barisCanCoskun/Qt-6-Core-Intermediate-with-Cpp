#include "producer.h"

Producer::Producer(QObject *parent)
    : QObject{parent}
{
    m_count = 0;
    m_max = 5;
    qInfo() << "Constructed" << this << "on" << QThread::currentThread();
}

Producer::~Producer()
{
    qInfo() << "Destructed" << this << "on" << QThread::currentThread();
}

// called when the thread is started
void Producer::start()
{
    qInfo() << "Starting on" << QThread::currentThread();

    m_timer = new QTimer(this);
// make a new timer with the parent child relationship.
// I'm doing this here because
// I want this timer to live on the thread we're running on

    qInfo() << this; // debug purpose for myself

    connect(m_timer, &QTimer::timeout, this, &Producer::timeout);
    connect(this, &Producer::finished, m_timer, &QTimer::stop);
    m_timer->setInterval(500);
    m_timer->start();
}

void Producer::timeout()
{
    int value = QRandomGenerator::global()->bounded(1, 100);
    qInfo() << "Produced" << value << "on" << QThread::currentThread();
    emit produce(value);

    ++m_count;
    if(m_count >= m_max){
        qInfo() << "Finished" << value << "on" << QThread::currentThread();
        emit finished();
    }
}









