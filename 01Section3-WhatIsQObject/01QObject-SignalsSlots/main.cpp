#include <QCoreApplication>
#include"test.h"
#include<QDebug>

void notifications(){
    Test mom;
    Test child;

    mom.setObjectName("Mom");
    child.setObjectName("Child");

    qInfo() << &mom;
    qDebug() << &mom;
    qDebug() << &child;

//    You have to connect the two objects
//    Dont make multiple connections to the same signal and slot unless you want multiple calls
//    Notice the icons
//    Can have a connection type
    QObject::connect(&mom, &Test::alarm, &child, &Test::wake, Qt::ConnectionType::AutoConnection);

//    mom.wake();

    mom.testing();

    mom.wake("wake up");

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    notifications();

    return a.exec();
}






