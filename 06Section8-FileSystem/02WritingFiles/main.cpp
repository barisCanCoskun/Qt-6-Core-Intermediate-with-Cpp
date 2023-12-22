/* Why
 * Put data into a file
 * How
 * QFile
 */
#include <QCoreApplication>
#include<QFile>
#include<QDateTime>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename{"test.png"};   // this will put it in the current dir

    QFile file{filename};
    if(file.open(QIODevice::WriteOnly)){
        QString now{QDateTime::currentDateTime().toString()};

        QByteArray data{now.toLocal8Bit()};
        data.append(" - ");
        data.append("Hello World");

        file.write(data);

//        file.flush();   // not necessary
        file.close();

        qInfo() << "Written to the file";
    }
    else{
        qInfo() << file.errorString();
    }

    return a.exec();
}











