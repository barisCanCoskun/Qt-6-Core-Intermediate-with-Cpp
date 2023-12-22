/*
 * The QVariant class acts like a union
 * for the most common Qt data types.
 */
#include <QCoreApplication>
#include<QVariant>

void test(QVariant var){
    int i{};
    bool ok{false};

    i = var.toInt(&ok);
    if(ok)
        qInfo() << "This is an integer:" << i;
    else
        qInfo() << "This is NOT an integer";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVariant value1{7};
    QVariant value2{"String"};

    test(value1);
    test(value2);

    return a.exec();
}





