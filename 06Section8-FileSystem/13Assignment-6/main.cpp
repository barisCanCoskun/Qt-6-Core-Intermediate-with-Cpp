/* Why use the Qt file system classes?
 * Cross platform file system access using the Qt API.
 *
 */
#include <QCoreApplication>
#include<QTemporaryFile>
#include<QDir>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTemporaryFile file;
    if(file.open()){
        qInfo() << "File:" << file.fileName();
        QByteArray data{"Hello World"};

        file.write(data);
        // small file only, bec. for larger files not working properly
        file.seek(0);   // move to the beginning
        qInfo() << file.readAll();

//        while (!file.atEnd()) {
//            qInfo() << file.readLine(); // \n
//        }

        file.close();
    }
    else{
        qInfo() << file.errorString();
    }

    return a.exec();
}









