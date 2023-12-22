/*
 * Why does Qt deprecate funcs and macros ?
 * Because they upgrade the framework over time.
 * For example, when qFill() was first created,
 * fill method wasn't even in QList, and the standard library really
 * wasn't up to the task of what they wanted,
 * so they kind of built their own.
 *
 * Over time the standard library improves and
 * the functionality in Qt becomes redundant.
 *
 */
#include <QCoreApplication>
#include <QRandomGenerator>

#define randList(list, max){\
        for (int i = 0; i < list.size(); ++i) {\
                list[i] = QRandomGenerator::global()->bounded(max);\
        }\
    }

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list;
    list.reserve(10);
    list.resize(10);
    randList(list, 100)

    qInfo() << list;

    return a.exec();
}












