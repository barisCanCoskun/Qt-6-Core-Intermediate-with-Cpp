#include <QCoreApplication>
#include<QDebug>
#include<QList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list;

    //easy append
    list << 1 << 2 << 3;

    for (int i = 0; i < 5; ++i) {
        list.append(i);
    }
    qInfo() << list;

    qInfo() << "Length:" << list.length();
    qInfo() << "Size:" << list.size();
    qInfo() << "Count:" << list.count();
    qInfo() << "Count:" << list.count(2);

    list.replace(3, 55);
    qInfo() << list;

    list.remove(4);
    qInfo() << list;

    list.removeAll(2);
    qInfo() << list;

    QList<int> sliceList{list.sliced(2, 3)};

    qInfo() << "Slice:" << sliceList;
    qInfo() << "List:" << list;

    qInfo() << "Contains:" << list.contains(7);
    qInfo() << "Index of:" << list.indexOf(7);
    list.clear();
    qInfo() << "List:" << list;

    qInfo() << "Length:" << list.length();
    qInfo() << "Size:" << list.size();
    qInfo() << "Count:" << list.count();

    return a.exec();
}





