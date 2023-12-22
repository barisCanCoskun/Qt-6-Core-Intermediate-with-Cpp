/*
 * QVector is an alias of QList
*/

#include <QCoreApplication>
#include<QDebug>
#include<QVector>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<int> vec;
    vec << 1 << 5;
//    QVector is an alias of QList
    qInfo() << vec;

    foreach (int i, vec) {
        qInfo() << i;
    }

    return a.exec();
}

