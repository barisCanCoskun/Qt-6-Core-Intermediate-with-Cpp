/* UTF8
 * Why
 * We want one to four one-byte code units
 * How
 * UTF-8 is a variable width character encoding capable of encoding
 * all 1,112,064 valid code points in Unicode using one to four 8-bits bytes
 */

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

    qInfo() << "sizeof u_int8_t:" << sizeof(u_int8_t);
    qInfo() << "sizeof QChar:" << sizeof(QChar);

    QString data{makeData()};
    qInfo() << data;

    QFile file{"data.txt"};
    if(file.open(QIODevice::WriteOnly)){
        QTextStream stream(&file);
        stream.setEncoding(QStringConverter::Encoding::Utf8); // not necessary
//        QString is automatically Unicode, but we're forcing this text stream to use UTF8
        stream << data;
        stream.flush();
        file.close();
    }

    qInfo() << "Done";
    qInfo() << "UTF8" << data;
    qInfo() << "ASCII" << data.toLatin1();

    return a.exec();
}







