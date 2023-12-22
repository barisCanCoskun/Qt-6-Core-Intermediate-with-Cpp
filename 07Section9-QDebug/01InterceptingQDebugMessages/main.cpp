/* Intercepting QDebug messages
 * Why
 * We want to catch any QDebug message
 * How
 * QtMessageHandler
 */
#include <QCoreApplication>
#include<QFile>
#include<QDateTime>
#include<QTextStream>

const QtMessageHandler QT_DEFAULT_MESSAGE_HANDLER = qInstallMessageHandler(nullptr);

void lhandler(QtMsgType type, const QMessageLogContext &context, const QString &msg){
    QString txt;
    switch (type){
        case QtInfoMsg:
            txt = QString("Info: %1").arg(msg);
            break;
        case QtDebugMsg:
            txt = QString("Debug: %1").arg(msg);
            break;
        case QtWarningMsg:
            txt = QString("Warning: %1").arg(msg);
            break;
        case QtCriticalMsg:
            txt = QString("Critical: %1").arg(msg);
            break;
        case QtFatalMsg:
            txt = QString("Fatal: %1").arg(msg);
            break;
    }

    QFile file("log.txt");
    if(file.open(QIODevice::Append)){
        QTextStream textStr(&file);
        textStr << QDateTime::currentDateTime().toString() << " - "
                << txt << " file:" << context.file << " line: " << context.line << "\r\n";
        textStr.flush();
        file.close();
    }

    (*QT_DEFAULT_MESSAGE_HANDLER)(type, context, msg);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInstallMessageHandler(lhandler);

    qInfo() << "This is an info message";
    qDebug() << "This is a debug message";
    qWarning() << "This is a warning message";
    qCritical() << "This is a critical message";
    qFatal() << "This is a fatal message: Sparta!";

    return a.exec();
}










