/*
 * Better than QList<QString>
 * inherits from QList<QString>
 */
#include <QCoreApplication>
#include<QStringList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    It provides fast index-based access
//    as well as fast insertions and removals
    QStringList names{"Baris"};
    names << "Pablo" << "Coskun";

    names.append("Can");
    qInfo() << names;

    names.replaceInStrings("a", "@");
    qInfo() << names;

    names.replaceInStrings("@", "a");
    names.sort();
    qInfo() << names;

    QString people{names.join(",")};
    qInfo() << people;

    QStringList myList{names.filter("r")};
    qInfo() << myList;

    QString b{"Baris"};
    qInfo() << "Contains: " << names.contains(b);
    qInfo() << "IndexOf: " << names.indexOf(b);
    qInfo() << "Value: " << names.at(names.indexOf(b));

    return a.exec();
}













