/* Why
 * Put data at the end of the file
 * How
 * QFile
 */
#include <QCoreApplication>
#include<QFile>
#include<QDateTime>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename{"test.txt"};   // this will put it in the current dir

    QFile file{filename};
    if(file.open(QIODevice::Append)){  // adds to the end of the file, run a few times and see
        QString now{QDateTime::currentDateTime().toString()};

        QByteArray data{now.toLocal8Bit()};
        data.append(" - ");
        data.append("Hello World\r\n");

        file.write(data);

        file.close();

        qInfo() << "Appended to the file";
    }
    else{
        qInfo() << file.errorString();
    }

    return a.exec();
}











