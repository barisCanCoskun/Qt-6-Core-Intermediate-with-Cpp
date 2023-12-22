/* Get the mounted volumes
 * Why
 * We want to know what volumes are available
 * How
 * QStorageInfo
 */
#include <QCoreApplication>
#include <QDir>
#include<QFileInfo>
#include<QStorageInfo>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStorageInfo root{QStorageInfo::root()};
    qInfo() << "root:" << root.rootPath();
    QDir dir{root.rootPath()};

    foreach (QFileInfo fileInfo, dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot)) {
        qInfo() << fileInfo.filePath();
    }

    qInfo() << "------------";

    foreach (QStorageInfo storage, QStorageInfo::mountedVolumes()) {
        qInfo() << "Name:" << storage.displayName();
        qInfo() << "Type:" << storage.fileSystemType();
        qInfo() << "Total:" << storage.bytesTotal()/1000/1000 << "MB";
        qInfo() << "Available:" << storage.bytesAvailable()/1000/1000 << "MB";
        qInfo() << "Device:" << storage.device();
        qInfo() << "Root:" << storage.isRoot();
        qInfo() << "\n";
    }

    return a.exec();
}








