/*
 * Why serialize data?
 * To save it and load it back into the application.
 *
 */
#include <QCoreApplication>
#include <QFile>
#include <QDataStream>
#include <QList>

bool saveFile(QString, QList<int>);
QList<int> loadFile(QString);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString file{"assignment.txt"};
    QList<int> list;
    list << 1 << 2 << 3 << 5;
    if(saveFile(file, list)){
        qInfo() << "Saved";
        QList<int> data{loadFile(file)};
        qInfo() << data;
    }

    return a.exec();
}

bool saveFile(QString path, QList<int> list){
    QFile file{path};
    if(!file.open(QIODevice::WriteOnly)) return false;

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_6_0);

    out << list;

    file.close();
    return true;
}

QList<int> loadFile(QString path){
    QFile file{path};
    QList<int> list{};
    if(!file.open(QIODevice::ReadOnly)) return list;

    QDataStream in(&file);
    if(in.version() != QDataStream::Qt_6_0){
        qCritical() << "Versions do not match!";
        file.close();
        return list;
    }

    in >> list;

    file.close();
    return list;
}









