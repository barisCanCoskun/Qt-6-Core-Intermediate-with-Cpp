#include <QCoreApplication>

//Custom macro
#define add(a,b) ((a)+(b))

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << add(2,3);

    qInfo() << add("test", 2);
    qInfo() << add("test", 22);
//    qInfo() << add("asd", "jkl");   // error
    QString str{"asd"};
    qInfo() << add(str, "jkl");
    qInfo() << add(true, false);
    qInfo() << add(false, false);
    qInfo() << add(true, true);
    qInfo() << add("test", '/n');
    qInfo() << add("test", '\n');

    return a.exec();
}
















