#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QTime>

class Test : public QObject
{
    Q_OBJECT
    QTimer timer;
    int number;

public:
    explicit Test(QObject *parent = nullptr);

signals:

public slots:
    void timeout();
    void doStuff();

};

#endif // TEST_H
