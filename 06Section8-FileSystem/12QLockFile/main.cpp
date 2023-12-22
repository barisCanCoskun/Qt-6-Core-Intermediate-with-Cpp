/* Locking a file to once instance
 * Why
 * There can be only one
 * How
 * QLockFile
 */
#include <QCoreApplication>
#include <QDir>
#include<QFile>
#include<QLockFile>
// The QLockFile class provides locking between processes using a file.

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Attempting to lock a file...";

    QString path{QDir::currentPath() + QDir::separator() + "test.txt"};
    QFile file{path};
    qInfo() << QDir::separator();

    QLockFile lockFile{file.fileName() + "l"};
    lockFile.setStaleLockTime(15000);

    if(lockFile.tryLock()){
        qInfo() << "Putting into file...";
        if(file.open(QIODevice::WriteOnly)){
            QByteArray data{"Hello wow"};
            file.write(data);
            file.close();
            qInfo() << "Finished with file...";
            // Took over X seconds here, auto unlock
        }
//        qInfo() << "Unlocking file";
//        lockFile.unlock(); // Comment out to see it lock
    }
    else{
        qInfo() << "Could not lock the file!";
        qint64 pid;     // process ID
        QString host;
        QString application;

        if(lockFile.getLockInfo(&pid, &host, &application)){
            qInfo() << "The file is locked by:";
            qInfo() << "Pid:" << pid;
            qInfo() << "Host:" << host;
            qInfo() << "Application:" << application;
        }
        else{
            qInfo() << "File is locked, but we can't get the info!";
        }
    }

    return a.exec();
}








