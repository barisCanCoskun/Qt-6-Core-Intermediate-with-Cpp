/*
 * Filling a container
 * Why
 * We want to populate a container
 * How
 * qFill is deprecated
 * use Qlist or std fill
 *
 */
#include <QCoreApplication>
#include <QList>
#include <QtAlgorithms>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list;
    list << 2 << 4 << 5 << 7;
    qInfo() << list;

//    qFill();    // do not use

    list.fill(3);
    qInfo() << "After fill method\n" << list;

    list.resize(6);
    qInfo() << "After resize\n" << list;
    std::fill(list.begin(), list.end(), 1);
    qInfo() << "After std::fill\n" << list;

    return a.exec();
}





