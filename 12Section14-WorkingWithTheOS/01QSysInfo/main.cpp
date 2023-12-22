/*
 * Look at the OS details
 * Why
 * We want to know what we are running on
 * How
 * QSysInfo
 *
 */
#include <QCoreApplication>
#include <QSysInfo>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSysInfo sys;

    qInfo() << "System Info:";
    qInfo() << "Boot ID:" << sys.bootUniqueId();
    qInfo() << "Build:" << sys.buildAbi();
    qInfo() << "Cpu:" << sys.buildCpuArchitecture();
    qInfo() << "Kernel:" << sys.kernelType();
    qInfo() << "Version:" << sys.kernelVersion();

    qInfo() << "Host:" << sys.machineHostName();
    qInfo() << "Product:" << sys.prettyProductName();
    qInfo() << "Type:" << sys.productType();
    qInfo() << "Version:" << sys.productVersion();

#ifdef Q_OS_LINUX
    qInfo() << "Linux code here";
#elif defined(Q_OS_WIN32)
    qInfo() << "Windows code here";
#elif defined(Q_OS_MACX)
    qInfo() << "Mac code here";
#else
    qInfo() << "Unknown OS code here";
#endif

    return a.exec();
}







