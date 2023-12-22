/* Serialize to XML
 * Why
 * XML is widely used
 * How
 * QXmlStreamWriter
 * QXmlStreamReader
 */
#include <QCoreApplication>
#include "test.h"
#include "converter.h"

void writeJson(QString path);
void readJson(QString path);
void writeXml(QString path);
void readXml(QString path);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path{"test.txt"};

//    writeJson(path);
//    readJson(path);

    writeXml(path);
    readXml(path);

    return a.exec();
}

void writeJson(QString path){
    Test t;
    t.fill();
    Converter::writeJson(t, path);
}

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

void writeXml(QString path){
    Test t;
    t.fill();
    Converter::writeXml(t, path);
}

void readXml(QString path){
    Test *t;
    t = Converter::readXml(path);

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










