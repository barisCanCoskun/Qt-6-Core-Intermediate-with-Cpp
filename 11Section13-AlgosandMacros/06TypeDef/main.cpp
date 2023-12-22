#include <QCoreApplication>
#include <QMap>

typedef QMap<QString, int> People;      // alias

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    People m;
    m.insert("john", 30);
    m.insert("simon", 25);
    m.insert("huan", 20);

    foreach (QString key, m.keys()) {
        qInfo() << key << m.value(key);
    }

    return a.exec();
}











