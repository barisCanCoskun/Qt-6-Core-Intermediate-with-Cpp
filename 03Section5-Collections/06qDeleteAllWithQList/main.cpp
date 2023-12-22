#include <QCoreApplication>
#include<QList>
#include"test.h"

void testListDelete(){
    QList<Test *> list;
    for (int i = 0; i < 5; ++i) {
        list.append(new Test(nullptr,
             "Item" + QString::number(i)));
    }

    foreach (Test *test, list) {
        qInfo() << test;
    }

    qDeleteAll(list);

    list.clear();
    qInfo() << "Count: " << list.count();
//    qInfo() << list.at(0);  // Dangling pointer

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testListDelete();

    return a.exec();
}











