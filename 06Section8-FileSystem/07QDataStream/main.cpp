/* Reading streams of data
 * Why
 * Data Encoding!
 * How
 * QDataStream
 */

#include <QCoreApplication>
#include<QFile>
#include<QDataStream>
// The QDataStream class provides serialization of binary data to a QIODevice.

bool write(QString filename){
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly)){
        qInfo() << file.errorString();
        return false;
    }

    QDataStream stream{&file};
//    stream.setVersion(QDataStream::Qt_6_5);
    stream.setVersion(QDataStream::Qt_6_1);

    int age{32};
    QString name{"Baris"};
    float weight{72};

    stream << age << name << weight;    // notice, there is a specific order
//    we're defining the order
//    Remember the order you do an age, name, weight.
//    What Qt is doing here is it's taking stream,
//    put age int in there, it's encoding it, put it in,
//    taking a string, encoding it, putting it and so on

    qInfo() << "Writing to the file";

    if(!file.flush()){
        qInfo() << file.errorString();
        file.close();
        return false;
    }

    qInfo() << "Closing the file";

    file.close();
    return true;
}

bool read(QString filename){
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)){
        qInfo() << file.errorString();
        return false;
    }

    qInfo() << "Reading the file";
    QDataStream stream{&file};
    if(stream.version() != QDataStream::Qt_6_5){
        qInfo() << "Wrong file version";
        file.close();
        return false;
    }

    int age{};
    QString name;
    float weight{};
//    extract in that specific order!! age, name, weight
    stream >> age >> name >> weight;
//    stream >> name;
//    stream >> weight;

    file.close();   // this file is a resource,
//    I want to close it as soon as I no longer need it.

    qInfo() << "Name:" << name;
    qInfo() << "Age:" << age;
    qInfo() << "Weight:" << weight;

    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename{"test.txt"};

    if(write(filename))
        read(filename);

    return a.exec();
}







