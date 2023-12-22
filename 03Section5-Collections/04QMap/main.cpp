#include <QCoreApplication>
#include<QDebug>
#include<QMap>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<QString, int> ages;
    ages.insert("Juan", 27);
    ages.insert("Pablo", 37);
    ages.insert("Gray", 20);

//    keys and values are QList
    qInfo() << "Keys: " << ages.keys();
    qInfo() << "Values: " << ages.values();

    qInfo() << "Pablo is: " << ages["Pablo"];
//    qInfo() << "Pablo is: " << ages.keys()[0];

    ages.remove("Pablo");
    qInfo() << "Contains" << ages.contains("Pablo");

    foreach (QString key, ages.keys()) {
        qInfo() << key << ": "<< ages[key];
    }

    qInfo() << "Test" << ages.value("Test", -1);

    ages["Test"] = 11;
    qInfo() << "Test" << ages.value("Test", -1);

    return a.exec();
}






