
#include <QCoreApplication>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QRandomGenerator>

QString makeData(){
    QString data;
    data.append("Unicode test\r\n");

    for (u_int8_t i = 0; i < 10; ++i) {
        int number{QRandomGenerator::global()->bounded(65535)};
        data.append(QChar(number));
    }

    return data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString data{makeData()};
    qInfo() << data;

    QFile file{"data.txt"};
    if(file.open(QIODevice::WriteOnly)){
        QTextStream stream(&file);
        stream.setEncoding(QStringConverter::Encoding::Utf16); // not necessary
        //        QString is automatically Unicode, but we're forcing this text stream to use UTF8
        stream << data;
        stream.flush();
        file.close();
    }

    qInfo() << "Done";
    qInfo() << "UTF16" << data;
    qInfo() << "UTF8" << data.toUtf8();
    qInfo() << "ASCII" << data.toLatin1();

    return a.exec();
}







