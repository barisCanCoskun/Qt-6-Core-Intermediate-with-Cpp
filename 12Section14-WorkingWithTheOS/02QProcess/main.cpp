#include <QCoreApplication>
#include <QProcess>

/*
 * QProcess is basically like opening a command line,
 * typing a command and having the os run it,
 * if we overly simplify it.
 *
 */

bool test();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // gzip is a compression utility
    if(test())
        qInfo() << "Compressed with gzip";
    else
        qInfo() << "Failed to use gzip";

    return a.exec();
}

bool test(){
    QProcess gzip;
    gzip.start("gzip", QStringList() << "-c");

    if(!gzip.waitForStarted(3000)) return false;

    QByteArray data;
    for (int i = 0; i < 100; ++i) {
        QString item = "Item" + QString::number(i);
//        qInfo() << "sizeof(item.at(0)):" << sizeof(item.at(0));  // == sizeof(QChar)
//        qInfo() << "item.size():" << item.size();
        data.append(item.toUtf8());
    }

    qInfo() << "data:" << data;
//    qInfo() << "sizeof(data):" << sizeof(data);  // == sizeof(QByteArray)
    gzip.write(data);
    gzip.closeWriteChannel();  // we're no longer going to be writing this.
    if(!gzip.waitForFinished(3000)) return false;

    QByteArray result = gzip.readAll();
    // in description of readALL() : This function has no way of reporting errors

    qInfo() << "Before:" << data.size();
    qInfo() << "Result:" << result.size();
    qInfo() << "Compressed:" << result;

    return true;
}












