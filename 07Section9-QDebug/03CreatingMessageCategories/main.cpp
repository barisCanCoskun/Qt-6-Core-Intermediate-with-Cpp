/* Creating message categories
 * Why
 * We want custom categories with filtering
 * How
 * QLoggingCategory
 * Q_DECLARE_LOGGING_CATEGORY
 * Q_LOGGING_CATEGORY
 * setFilterRules
 */

#include <QCoreApplication>
//#include <QDebug>
#include <QLoggingCategory>

// Declare a logging category
Q_DECLARE_LOGGING_CATEGORY(network)
Q_LOGGING_CATEGORY(network, "network")

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "test";

    qInfo(network) << "test";
// we can define different categories
    qWarning(network) << "test";

// turn it off
    QLoggingCategory::setFilterRules("network.debug=false");

// will not log
    qDebug(network) << "cat";

    if(!network().isDebugEnabled()){
        QLoggingCategory::setFilterRules("network.debug=true");
    }
    qDebug(network) << "gray";

    return a.exec();
}











