#include <QCoreApplication>
#include<QScopedPointer>
#include<QSharedPointer>
#include"test.h"

//scoped pointer
void test0(){
    QScopedPointer<Test> sp{new Test()};
//    sp.data()->setObjectName("My Test");
    sp->setObjectName("My Test");

    qInfo() << "Scoped pointer:" << &sp;
    qInfo() << "Pointer data:" << sp.data();    // actual pointer
    qInfo() << sp->objectName();    // to show we can interact with obj name directly

}

QSharedPointer<Test> getObject(QString name){
    QSharedPointer<Test> sp{new Test()};
    sp->setObjectName(name);

    return sp;
}

void someWork(QSharedPointer<Test> sp){
    qInfo() << "In someWork func:" << sp.data();
    qInfo() << "Shared pointer " << &sp;
}

//shared pointer
void test1(){
    qInfo() << "Getting the object";
    QSharedPointer<Test> ptr{getObject("My Object")};
    qInfo() << "Shared pointer " << &ptr;
    qInfo() << "Object" << ptr.data();

    someWork(ptr);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //scoped pointer
//    test0();

    //shared pointer
    test1();

    return a.exec();
}










