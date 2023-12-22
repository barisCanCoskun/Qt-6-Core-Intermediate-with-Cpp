/* QLoggingCategory
 * Why
 * Make logging categories easier
 * How
 * QLoggingCategory
 */

#include <QCoreApplication>
#include <QLoggingCategory>
//#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QLoggingCategory logtest("testi");
    logtest.setEnabled(QtMsgType::QtDebugMsg, false);

    qDebug() << "Debug = " << logtest.isDebugEnabled();
    qInfo() << "Info = " << logtest.isInfoEnabled();
    qWarning() << "Warning = " << logtest.isWarningEnabled();
    qCritical() << "Critical = " << logtest.isCriticalEnabled();

    qDebug(logtest) << "This is a debug";
    qInfo(logtest) << "This is an info";
    qWarning(logtest) << "This is a warning";
    qCritical(logtest) << "This is a critical";

    return a.exec();
}










