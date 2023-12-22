/* Deleting all pointers in a container
 * Why
 * C++ requires us to manage pointers
 * How
 * qDeleteAll
 */
#include <QCoreApplication>
#include <QList>
#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<Test *> list;

    for (int i = 0; i < 10; ++i) {
        Test *t{new Test()};    // no parent, no smart pointer
        t->setObjectName(QString::number(i));
        list.append(t);
    }

    qInfo() << list.at(2);

    qDeleteAll(list);
    qInfo() << "count:" << list.count();
    qInfo() << "size:" << list.size();

//    qInfo() << list.at(2); // will crash...

    list.clear();
    qInfo() << "Cleared.";
    qInfo() << "count:" << list.count();
    qInfo() << "size:" << list.size();

    return a.exec();
}












