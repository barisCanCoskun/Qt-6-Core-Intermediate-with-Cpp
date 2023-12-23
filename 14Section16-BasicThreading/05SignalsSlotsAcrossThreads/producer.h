#ifndef PRODUCER_H
#define PRODUCER_H

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QRandomGenerator>
#include <QThread>

// the producer is going to produce a random value and
// emit a signal called produce() at a specific interval.
// when it's done producing, it's going to emit finished()
// to let the outside world know, hey, I'm done producing
// go ahead and shut down.
// when the thread it's running on start(), it will start this producer.
// and then we have a timer 'm_timer' internally we're going to use,
// which is why we have a private slot 'timeout()'.
// And this timer is going to call this 'timeout()',
// which is going to actually produce the value.

class Producer : public QObject
{
    Q_OBJECT
    QTimer *m_timer;
    int m_count;
    int m_max;

public:
    explicit Producer(QObject *parent = nullptr);
    ~Producer();

signals:
    void produce(int value);
    void finished();

public slots:
    void start();

private slots:
    void timeout();

};

#endif // PRODUCER_H












