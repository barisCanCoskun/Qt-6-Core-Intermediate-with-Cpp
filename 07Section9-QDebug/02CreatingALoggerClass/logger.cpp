#include "logger.h"

QString Logger::filename = QDir::currentPath() + QDir::separator() + "log.txt";
bool Logger::logging = false;
static const QtMessageHandler QT_DEFAULT_MESSAGE_HANDLER = qInstallMessageHandler(nullptr);

Logger::Logger(QObject *parent)
    : QObject{parent}
{

}

void Logger::attach()
{
    // we're logging...
    logging = true;
    qInstallMessageHandler(handler);
}

void Logger::handler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    if(logging){
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

        QFile file(filename);
        if(file.open(QIODevice::Append)){
            QTextStream textStr(&file);
            textStr << QDateTime::currentDateTime().toString() << " - "
                    << txt << " file:" << context.file << " line: " << context.line << "\r\n";
            textStr.flush();
            file.close();
        }
    }

    (*QT_DEFAULT_MESSAGE_HANDLER)(type, context, msg);
}












