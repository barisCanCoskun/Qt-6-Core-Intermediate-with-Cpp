#include <QCoreApplication>
#include<QFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    QString filename{"test.txt"};
    QFile file{"test.txt"};
    qInfo() << "Exists:" << file.exists();
    if(file.open(QIODevice::ReadOnly)){
        // small file only
        qInfo() << file.readAll();

        file.close();
    }
    else{
        qInfo() << file.errorString();
    }

    return a.exec();
}












