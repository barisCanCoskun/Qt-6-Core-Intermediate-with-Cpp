#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QDebug>
#include <QThread>

class Task : public QObject
{
    Q_OBJECT
public:
    explicit Task(QObject *parent = nullptr);
    ~Task();

signals:

public slots:
    void work();

};

#endif // TASK_H
