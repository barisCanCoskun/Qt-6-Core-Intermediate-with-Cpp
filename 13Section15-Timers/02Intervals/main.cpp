/*
 * Timers
 * What
 * We want to wait without blocking execution
 * How
 * QTimer
 * Example of intervals
 *
 */

#include <QCoreApplication>
#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test t;
    t.doStuff();

    return a.exec();
}









