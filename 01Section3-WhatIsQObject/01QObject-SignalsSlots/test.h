#ifndef TEST_H
#define TEST_H

#include <QObject>
#include<QDebug>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);
    ~Test();

    void testing();

signals:
//    Always public
//    Always defined
//    Never implemented
    void alarm(QString noise);

public slots:
//    Can be private, protected, public
//    Always defined and implimented
//    Should match the signal
    void wake(QString noise);

};

#endif // TEST_H





