#include <QCoreApplication>
#include <iostream>
#include <QFile>

QByteArray makeData(){
    QByteArray data;
    for (u_int8_t i = 0; i < 7; ++i) {
        data.append(72);
        data.append(101);
        data.append(108);
        data.append(108);
        data.append(111);
        data.append(33);
        data.append(13);    // \r
        data.append(10);    // \n
    }
    return data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qsizetype s = 123;
    qInfo() << "The size is:" << sizeof(s) << "\n";

    QByteArray ba{makeData()};
//    for (qsizetype i = 0; i < ba.size(); ++i) {
//        std::cout << ba.at(i);
//    }

    qInfo() << ba;

    QFile file("data.txt");
    if(file.open(QIODevice::WriteOnly)){
        file.write(ba);
        file.close();
    }
    qInfo() << "Done";

    return a.exec();
}







