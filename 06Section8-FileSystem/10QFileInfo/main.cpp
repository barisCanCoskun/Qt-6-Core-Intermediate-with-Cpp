/* Get File Info
 * Why
 * We want to know details about a file or folder
 * How
 * QFileInfo
 */
#include <QCoreApplication>
#include <QDir>
#include<QFileInfo>
#include<QFileInfoList>
#include<QDateTime>

void list(QString path){
    qInfo() << "List:" << path;

    QDir dir{path};
    QFileInfoList dirs{dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot)};
    QFileInfoList files{dir.entryInfoList(QDir::Files)};

    foreach (QFileInfo fileInfo, dirs){
        qInfo() << fileInfo.fileName();
    }

    foreach (QFileInfo fileInfo, files) {
        qInfo() << "...Name:" << fileInfo.fileName();
        qInfo() << "...Size:" << fileInfo.size();
        qInfo() << "...Created:" << fileInfo.birthTime();
        qInfo() << "...Modified:" << fileInfo.lastModified();
    }
    foreach (QFileInfo fileInfo, dirs) {
        list(fileInfo.filePath());
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    list(QDir::tempPath());

    return a.exec();
}








