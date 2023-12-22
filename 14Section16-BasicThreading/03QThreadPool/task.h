#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QRunnable>

class Task : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit Task(QObject *parent = nullptr);
    ~Task();

signals:

public slots:
    void run() override;
//    when we run our Runnable in the thread pool,
//    it's going to call the run function
};

#endif // TASK_H















