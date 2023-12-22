/*
 * QByteArrayView
 *
 * Read only(fast access) to a QByteArray
 *
 */

#include <QCoreApplication>
#include<QByteArray>
#include<QByteArrayView>
#include<QList>

//Read only(fast access) to a QByteArray
//In Qt document:
//QByteArrayView should be passed by value, not by reference-to-const:
//void display(const QByteArrayView &view){
void display(QByteArrayView view){
    qInfo() << "\nQbytearrayview";
    qInfo() << view;
//    view.insert : no option

    qInfo() << "size:" << view.size();
    qInfo() << "constdata:" << view.constData();
    qInfo() << "sliced:" << view.sliced(1, 4);
    qInfo() << "contains:" << view.contains("ow");
    qInfo() << "at:" << view.at(6);
    qInfo() << "indexof:" << view.indexOf('w');
    qInfo() << "index:" << view[0];

}

void displayArray(QByteArray &arr){
    qInfo() << "\nQbytearray";
    qInfo() << arr;
    arr.append(" there");
    qInfo() << arr;

    auto it{arr.end()};
    std::advance(it, -6);
    qInfo() << *it;
    arr.erase(it, arr.end());

    arr.insert(11, ",");
    qInfo() << arr;

    arr.insert(arr.size() - 1, QByteArrayView(" there"));
    qInfo() << arr;
}

void test(QList<int> m){
    qInfo() << m;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray bytes{"Hello world how are you?"};
    QByteArrayView view{(QByteArrayView)bytes};

    display(view);

    displayArray(bytes);

//    display(view);
    qInfo() << "qbytearrayview:\n" << view;

    QByteArray testArray{bytes};
    qInfo() << "testArray:\n" << testArray;

    QList<int> myList{1, 2, 3};
    test(myList);
    return a.exec();
}















