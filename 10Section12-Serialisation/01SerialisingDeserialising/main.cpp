/* Serialize and deserialize data
 * Why
 * We want to see how simple it can be
 * How
 * QDataStream and QFile
 * We have done this before!
 *
 * How is serialization different than encoding?
 * Serialization is how the data is stored**********
 */
#include <QCoreApplication>
#include <QDataStream>
#include <QFile>

bool saveFile(QString);
bool readFile(QString);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString file{"test.txt"};
    if(saveFile(file)){
        qInfo() << "Saved";
        readFile(file);
    }

    return a.exec();
}

bool saveFile(QString path){
    QFile file{path};
    if(!file.open(QIODevice::WriteOnly)) return false;

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_6_0);

    QString title{"The answer is 42!"};
    qint64 num{24};

    out << title;
    out << num;

    file.close();
    return true;
}

bool readFile(QString path){
    QFile file{path};
    if(!file.open(QIODevice::ReadOnly)) return false;

    QDataStream in(&file);
    if(in.version() != QDataStream::Qt_6_0){
        qCritical() << "Versions do not match!";
        file.close();
        return false;
    }

    QString title;
    qint64 number;

    in >> title;
    in >> number;

    qInfo() << "title:" << title;
    qInfo() << "number:" << number;

    file.close();
    return true;
}










