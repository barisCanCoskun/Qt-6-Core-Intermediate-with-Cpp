/* Serialize to JSON
 * Why
 * Sharing with other apps or a human readable format
 * How
 * QJsonDocument
 */
#include <QCoreApplication>
#include "test.h"
#include "converter.h"

void writeJson(QString path);
void readJson(QString path);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path{"test.txt"};

    writeJson(path);
    readJson(path);

    return a.exec();
}

void writeJson(QString path){
    Test t;
    t.fill();
    Converter::writeJson(t, path);
}

/* This isn't really true serialisation and deserialization,
 * really what we're doing here is just making an instance of a class
 * and then persisting those properties back to the disk
 * and then loading them back.
 * This is actually very much industry standard.
 * What would you really use this for ?
 * What's the main reason for this ?
 * It's data interchange!!!**************************
 * For example, you have a program and your friend has a program
 * and you want to exchange information btw the programs.
 * Essentially, their program is going to make their own version of
 * this test class. It could be in a different language alltogether,
 * like Python, Java, .Net, and it doesn't matter. You're going to send
 * them that JSON file and they're going to load it up into their own object.
 * That's exactly what JSON for.
 * Actually, pretty much used in mobile programming
 * and things of that nature where you're sending data
 * btw a mobile device and a server, and you just need to make sure it gets
 * there in one piece and that it's easy to work with.
 * Hence it's human readable.
 */
void readJson(QString path){
    Test *t;
    t = Converter::readJson(path);

    if(!t){
        qInfo() << "Object not loaded";
        return ;
    }

    qInfo() << "Name:" << t->getName();
    foreach (QString key, t->getMap().keys()) {
        qInfo() << key << " : " << t->getMap().value(key);
    }

//    delete t;
    t->deleteLater();
}











