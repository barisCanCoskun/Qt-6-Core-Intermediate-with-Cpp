/*
 * Exploring our process lifecycle
 * Why
 * To see how we interact with the world
 * How
 * main func
 * QCoreApplication
 *
 */

#include <QCoreApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Args:";
    for (int i = 0; i < argc; ++i) {
        qInfo() << argv[i];
    }

    // trigger once and only once
    QTimer::singleShot(3000, &a, SLOT(quit())); // This is signals and slots

    int code = a.exec();
    qInfo() << "Code:" << code;

    return code;
}















