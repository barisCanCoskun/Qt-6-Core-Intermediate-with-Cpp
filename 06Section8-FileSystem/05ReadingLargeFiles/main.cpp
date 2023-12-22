/* Why
 * ReadAll is not a great idea
 * Break it into smaller parts
 * How
 * QFile::readLine
 *
 */
#include <QCoreApplication>
#include<QFile>

//if you're going to use a plain text file, read line by line
void readLines(QFile &file){
    if(!file.isReadable()) return;
    file.seek(0);   // move to the beginning
    while (!file.atEnd()) {
        qInfo() << file.readLine(); // \n
    }
}

// if you need to read a certain number of bytes, use read func.
void readChunks(QFile &file){
    if(!file.isReadable()) return;
    file.seek(0);
    while (!file.atEnd()) {
        qInfo() << file.read(25); // \n
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename{"test.txt"};   // create this manually

    QFile file{filename};
    if(file.open(QIODevice::ReadOnly)){  // Reads the file can not modify it
        qInfo() << "***Reading line by line***";
        readLines(file);

        qInfo() << "\n----------------\n";

        qInfo() << "***Reading chunks***";
        readChunks(file);

        file.close();
    }
    else{
        qInfo() << file.errorString();
    }

    return a.exec();
}









