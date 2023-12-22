/* Directories
 * Why
 * We need to navigate and manipulate them
 * We're changing the file system
 * How
 * QDir
 */

#include <QCoreApplication>
#include<QDir>
#include<QFileInfo>
#include<QFileInfoList>

void list(QDir &root){
    qInfo() << "----Listing----";
    foreach (QFileInfo fileInfo, root.entryInfoList(QDir::Filter::Dirs, QDir::Type)){
//    foreach (QFileInfo fileInfo, root.entryInfoList()){
        if(fileInfo.isDir()){
            qInfo() << fileInfo.absoluteFilePath();
        }
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
//    qInfo() << dir.absoluteFilePath();

    dir.mkdir("test");
    list(dir);

    dir.rmdir("test");  // Removes the directory specified by dirName.
// The directory must be empty for rmdir() to succeed.
    list(dir);

////    recursive exists but don't do it unless you KNOW it should be gone
//    dir.rmpath("test");  // Removes the directory path dirPath.
//// The function will remove all parent directories in dirPath,
//// provided that they are empty.
//    list(dir);

    return a.exec();
}











