/* Base 64
 * Why
 * We want to transmit special chars
 * Some protocols use special chars that can cause issues
 * How
 * Base64 is a group of similar binary-to-text encoding schemes that represent
 * binary data in an ASCII string
 * The term Base64 digit represents exactly 6 bits of data.
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
    QByteArray encoded{bytes.toBase64()};
    QByteArray decoded{QByteArray::fromBase64(encoded)};

    qInfo() << "Encoded:" << encoded;
    qInfo() << "-----------------------------";
    qInfo() << "Decoded:" << decoded;

    return a.exec();
}








