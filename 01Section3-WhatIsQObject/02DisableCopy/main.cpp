#include <QCoreApplication>
#include<QDebug>

void testPointer(QObject *obj);
void testAddress(QObject &obj);
void testCopy(QObject obj);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject programmer;
    programmer.setObjectName("Baris");

    testPointer(&programmer);
    testAddress(programmer);
//    testCopy(programmer);

    return a.exec();
}

void testPointer(QObject *obj){
    qInfo() << obj;
}

void testAddress(QObject &obj){
    qInfo() << &obj;
}

void testCopy(QObject obj){
    qInfo() << &obj;
}












