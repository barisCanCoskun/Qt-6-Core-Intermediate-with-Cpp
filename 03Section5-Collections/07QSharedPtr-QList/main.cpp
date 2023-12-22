#include <QCoreApplication>
#include<QSharedPointer>
#include"test.h"

void test(){
    QList<QSharedPointer<Test>> list;

    for (int i = 0; i < 4; ++i) {
        QSharedPointer<Test> item(new Test(
            nullptr, "Item" + QString::number(i)));
        list.append(item);
    }

    foreach (QSharedPointer<Test> test, list) {
//        qInfo() << test.data();
        qInfo() << test;
    }
    qInfo() << "Remove one item";
    list.removeAt(0);
    qInfo() << "Clearing";
    list.clear();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    test();

    return a.exec();
}







