/* Why
 * The QIODevice class is the base interface class of all I/O devices
 * How
 * QBuffer which is a simple IO device
 */
#include <QCoreApplication>
#include<QIODevice>
#include<QBuffer>
// The QBuffer class provides a QIODevice interface for a QByteArray.

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QBuffer buffer;
    if(buffer.open(QIODevice::ReadWrite)){
        qInfo() << "Device is open";

        QByteArray data("Helllo world");
        for(size_t i{}; i < 5; ++i){
            buffer.write(data + "\r\n");
        }
//        buffer.flush();

        buffer.seek(0);
        qInfo() << buffer.readAll();
        qInfo() << "Closing the buffer...";

        buffer.close();
    }
    else{
        qInfo() << "Could not open the device";
    }
    qInfo() << "Finished";

    return a.exec();
}

















