/* Reading streams of text
 * Why
 * Encoding!
 * How
 * QTextStream
 */
#include <QCoreApplication>
#include<QFile>
#include<QTextStream>
// think of a stream, you're out in the woods and you come across a stream
// and it's just realy has no beginning and ending but there's water
// flowing through it and you can see the water in your visible area...
// that's really what a stream is, you are just going to get
// a continuous flow of data until sth happens.
// as the name implies, QTextStream is Qt's text version of a stream,
// meaning a human readable stream

void write(QFile &file){
    if(!file.isWritable()){
        qInfo() << "Unable to write to the file";
        return ;
    }

    QTextStream stream{&file};
    stream.setEncoding(QStringConverter::LastEncoding);
//    this is where we're going to say, I want to use this specific encoding
    for (int i{}; i < 5; ++i) {
        stream << QString::number(i) << "-Item\r\n";
    }
    stream.flush();
//    we've written some info, it's sitting in a buffer somewhere,
//    push that down to the actual IODevice, otherwise it'll do it
//    automatically at later time but we want to make sure
    qInfo() << "File written";
}

void read(QFile &file){
    if(!file.isReadable()){
        qInfo() << "Unable to read the file";
        return ;
    }
    QTextStream stream(&file);
    stream.seek(0);
    while (!stream.atEnd()) {
        qInfo() << stream.readLine();
    }

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename{"test.txt"};

    QFile file{filename};
    if(file.open(QIODevice::ReadWrite)){ // can read and write

        QTextStream stream{&file};
        qInfo() << "Encoding:" << stream.encoding();
//        Think of encoding this way, a file and has data
//        which is dependent on the encoding. Is it plain text?
//        Is is hex?, Is it some other thing?

        write(file);
        read(file);
        file.close();
    }
    else{
        qInfo() << file.errorString();
    }

    return a.exec();
}










