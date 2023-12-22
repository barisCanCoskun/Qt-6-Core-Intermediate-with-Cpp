#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>
#include <QThread>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);
    ~Test();

signals:

public slots:
    void work();

};

#endif // TEST_H
