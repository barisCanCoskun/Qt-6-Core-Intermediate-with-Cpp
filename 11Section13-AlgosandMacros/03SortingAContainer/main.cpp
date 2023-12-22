/*
 * Sorting a container
 * Why
 * We want things in order
 * How
 * qSort is deprecated
 * use std sort
 *
 */
#include <QCoreApplication>
#include <QList>
#include <QtAlgorithms>
#include <QRandomGenerator>

void randoms(QList<int> &list, int max){
    list.reserve(max);
    for (int i = 0; i < max; ++i) {
        int value = QRandomGenerator::global()->bounded(1000);
        list.append(value);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list;
    randoms(list, 10);

    qInfo() << "Unsorted:" << list;

//    qSort()   // do not use, it s not supported anymore

    std::sort(list.begin(), std::end(list));
    qInfo() << "Sorted:" << list;

    QList<int> list2{list};

    std::reverse(list.begin(), std::end(list));
    qInfo() << "Reversed:" << list;

    qInfo() << "\nlist2:" << list2;
    qInfo() << "Equal:" << std::equal(list.begin(), std::end(list), list2.begin());

    std::reverse(list2.begin(), std::end(list2));
    qInfo() << "Reversed list2:" << list2;

    qInfo() << "Equal:" << std::equal(list.begin(), std::end(list), list2.begin());

    return a.exec();
}












