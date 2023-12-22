#ifndef COMMANDER_H
#define COMMANDER_H

#include <QObject>
#include <QDebug>
#include <QProcess>
#include <QSysInfo>

class Commander : public QObject
{
    Q_OBJECT

    QProcess proc;
    QString app;
    QString endl;

public:
    explicit Commander(QObject *parent = nullptr);
    ~Commander();

signals:

public slots:
    void readyRead();
    void action(QByteArray data);

};

#endif // COMMANDER_H











