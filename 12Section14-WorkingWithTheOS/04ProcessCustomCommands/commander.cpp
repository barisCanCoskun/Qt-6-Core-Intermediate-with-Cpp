#include "commander.h"

Commander::Commander(QObject *parent)
    : QObject{parent}
{
    QSysInfo info;

    app = "bash";
    endl = "\n";

#ifdef Q_OS_WIN
    app = "cmd";
    endl = "\r\n";
#elif defined(Q_OS_DARWIN)
    app = "zsh";
    endl = "\n";
#endif

    proc.setProgram(app);
    proc.start();

    connect(&proc, &QProcess::readyRead, this, &Commander::readyRead);
    connect(&proc, &QProcess::readyReadStandardOutput, this, &Commander::readyRead);
    connect(&proc, &QProcess::readyReadStandardError, this, &Commander::readyRead);
}

Commander::~Commander()
{
    if(proc.isOpen()) proc.close();
}

void Commander::readyRead()
{
    qint64 value = 0;
    do{
        QByteArray line = proc.readAll();
        qInfo() << line.trimmed();
        value = line.length();
    }while(value > 0);
}

void Commander::action(QByteArray data)
{
    if(!data.endsWith(endl.toLatin1())) data.append(endl.toUtf8());
    proc.write(data);
    proc.waitForBytesWritten(1000);
}







