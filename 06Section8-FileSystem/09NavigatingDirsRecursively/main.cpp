/* Navigate Dirs Recursively
 * Why
 * We need to know what are in all the dirs
 * How
 * QDir
 */
#include <QCoreApplication>
#include <QDir>
#include<QFileInfo>
#include<QFileInfoList>

void list(QDir &root){
    qInfo() << "---Listing---";
    foreach (QFileInfo fileInfo, root.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot, QDir::Type)) {
        if(fileInfo.isDir()){
            qInfo() << "Dir" << fileInfo.filePath();
            QDir child{fileInfo.filePath()};
            qInfo() << "Inspecting:" << child.absolutePath();
            list(child);
        }
        if(fileInfo.isFile())
            qInfo() << "File" << fileInfo.filePath();

    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDir dir{QCoreApplication::applicationDirPath()};
    qInfo() << dir.dirName();
    qInfo() << dir.absolutePath();

    dir.cdUp();
    qInfo() << dir.absolutePath();

    list(dir);

    return a.exec();
}








