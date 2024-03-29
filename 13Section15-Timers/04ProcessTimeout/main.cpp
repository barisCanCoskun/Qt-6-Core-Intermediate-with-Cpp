/*
 * Process timeout
 * Why
 * We want to kill a process if it takes too long
 *
 */

#include <QCoreApplication>
#include <QProcess>
#include <QTimer>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QProcess proc;
    proc.start("TextMate.app");

    QTimer::singleShot(3000, &proc, &QProcess::terminate);

    return a.exec();
}
















