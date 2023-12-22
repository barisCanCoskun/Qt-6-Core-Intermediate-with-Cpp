/* Serialize a class
 * Why
 * Classes that can save and load
 * How
 * Operators!
 */
#include <QCoreApplication>
#include <QDataStream>
#include <QDir>
#include <QFile>
#include "test.h"

bool saveFile(Test &t, QString path);
bool loadFile(QString path);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path{"test.txt"};

    Test t;
    t.fill();
    if(saveFile(t, path))
        loadFile(path);

    return a.exec();
}

bool saveFile(Test &t, QString path){
    QFile file{path};
    if(!file.open(QIODevice::WriteOnly)) return false;

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_6_0);

//    QString title{"The answer is 42!"};
//    qint64 num{24};

//    out << title;
//    out << num;

    out << t;    // SERIALIZING

    file.close();
    return true;
}

bool loadFile(QString path){
    QFile file{path};
    if(!file.open(QIODevice::ReadOnly)) return false;

    QDataStream in(&file);
    if(in.version() != QDataStream::Qt_6_0){
        qCritical() << "Versions do not match!";
        file.close();
        return true;
    }

//    QString title;
//    qint64 number;

//    in >> title;
//    in >> number;

//    qInfo() << "title:" << title;
//    qInfo() << "number:" << number;

    Test t;
    in >> t;    // DESERIALIZING

    file.close();

    qInfo() << "Name:" << t.getName();
//    qInfo() << "Map:" << t.getMap();
//    all the information deserialized from the disk:
    foreach (QString k, t.getMap().keys()) {
        qInfo() << k << " : " << t.getMap().value(k);
    }

    return true;
}











