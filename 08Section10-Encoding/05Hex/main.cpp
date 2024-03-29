/* Base 64
 * Why
 * Hexadecimal numeral system is a positional numeral system that represents
 * numbers using a radix of 16
 * How
 * QByteArray again...
 */

#include <QCoreApplication>

QString makeData(){
    QString data;
    for (u_int8_t i = 0; i < 5; ++i) {
        data.append("Hello\r\n");
    }
    return data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString data{makeData()};
    QByteArray bytes{data.toUtf8()};
    QByteArray encoded{bytes.toHex()};
    QByteArray decoded{QByteArray::fromHex(encoded)};

    qInfo() << "Encoded:" << encoded;
    qInfo() << "-----------------------------";
    qInfo() << "Decoded:" << decoded;

    return a.exec();
}








