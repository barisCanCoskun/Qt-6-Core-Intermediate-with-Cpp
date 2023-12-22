/* File compression
 * How
 * Lots of custom code
 * make file
 * compress file
 * decompress file
 * NOT COMPATIBLE!
 */

#include <QCoreApplication>
#include <QFile>
#include <QDir>
#include <QBuffer>
#include <QTextStream>

bool makeFile(QString);
QByteArray getHeader();
bool compressFile(QString, QString);
bool decompressFile(QString, QString);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString originalFile{"original.txt"};
    QString compressedFile{"compressed.txt"};
    QString decompressedFile{"decompressed.txt"};

    if(makeFile(originalFile)){
        qInfo() << "Original created";
        if(compressFile(originalFile, compressedFile)){
            qInfo() << "File compressed";
            if(decompressFile(compressedFile, decompressedFile)){
                qInfo() << "File decompressed";
            }
            else{
                qInfo() << "File NOT decompressed";
            }
        }
        else{
            qInfo() << "File NOT compressed";
        }
    }
    else{
        qInfo() << "Original NOT created";
    }

    return a.exec();
}

bool makeFile(QString path){
    QFile file(path);
    if(file.open(QIODevice::WriteOnly)){
        QByteArray data;
        for (int i = 0; i < 1000; ++i) {
            data.append(QString::number(i).toUtf8() + "\r\n");
        }
        file.write(data);
        file.close();
        return true;
    }
    return false;
}

bool compressFile(QString originalFile, QString newFile){
    QFile oFile(originalFile);
    QFile nFile(newFile);
    QByteArray header = getHeader();

    if(!oFile.open(QIODevice::ReadOnly)) return false;
    if(!nFile.open(QIODevice::WriteOnly)) return false;
    int size = 1024;

    while (!oFile.atEnd()) {
        QByteArray buffer = oFile.read(size);
        QByteArray compressed = qCompress(buffer);
        nFile.write(header);
        nFile.write(compressed);
    }
    oFile.close();
    nFile.close();

    qInfo() << "Finished compressing";
    return true;
}

bool decompressFile(QString originalFile, QString newFile){
    QFile oFile(originalFile);
    QFile nFile(newFile);
    QByteArray header = getHeader();

    if(!oFile.open(QIODevice::ReadOnly)) return false;
    if(!nFile.open(QIODevice::WriteOnly)) return false;
    int size = 1024;

    // Make sure we created this file!
    QByteArray buffer = oFile.peek(size); // peek gives the data without moving cursor
    if(!buffer.startsWith(header)){
        qCritical() << "We did not create this file!";
        oFile.close();
        nFile.close();
        return false;
    }

    // Find the header positions
    oFile.seek(header.length());
    while (!oFile.atEnd()) {
        buffer = oFile.peek(size);
        qint64 index = buffer.indexOf(header);
        qDebug() << "Head found at:" << index;

        if(index > -1){
            // We found a header
            qint64 maxBytes = index;
            qInfo() << "Reading:" << maxBytes;
            buffer = oFile.read(maxBytes);
            oFile.read(header.length());
        }
        else{
            // Do not have a header
            qInfo() << "Read all no header";
            buffer = oFile.readAll();
        }

        QByteArray decompressed = qUncompress(buffer);
        nFile.write(decompressed);
        nFile.flush();
    }

    oFile.close();
    nFile.close();

    qInfo() << "Finished decompressing";
    return true;
}

QByteArray getHeader(){
    QByteArray header;
    header.append("@!~!@");
    return header;
}














