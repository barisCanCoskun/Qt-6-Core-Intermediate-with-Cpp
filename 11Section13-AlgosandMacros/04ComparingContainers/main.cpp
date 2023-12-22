/*
 * Equal
 * Why
 * We want to ensure they are equal
 * How
 * qEqual is deprecated
 * use std equal
 *
 */
#include <QCoreApplication>
#include <QList>
#include <QtAlgorithms>
#include <QRandomGenerator>

void randoms(QList<int> &list, int max){
    list.reserve(max);
    for (int i = 0; i < max; ++i) {
        int value = QRandomGenerator::global()->bounded(100);
        list.append(value);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list1;
    randoms(list1, 10);
    qInfo() << "sizeof list1:" << list1.size();
    QList<int> list2;
    randoms(list2, 10);

    qInfo() << "list1:" << list1;
    qInfo() << "list2:" << list2;

//    qEqual(list1.begin(), std::end(list1), list2.begin());   // do not use, it s not supported anymore

    if(std::equal(list1.begin(), std::end(list1), list2.begin()))
        qInfo() << "list1 and list2 are equal.";
    else
        qInfo() << "list1 and list2 are not equal.";

    QList<int> list3;
    qInfo() << "Copying...";
    list3.resize(list1.size());
    std::copy(list1.begin(), std::end(list1), list3.begin());
    qInfo() << "list1 and list3 are equal:" <<
        std::equal(list1.begin(), std::end(list1), list3.begin());

    qInfo() << "list1:" << list1;
    qInfo() << "list3:" << list3;

    return a.exec();
}












