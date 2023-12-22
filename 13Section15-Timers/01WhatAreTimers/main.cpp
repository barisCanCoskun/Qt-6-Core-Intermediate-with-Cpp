/*
 * Timers
 * Why
 * We want to wait without blocking execution
 * How
 * QTimer
 * Example of single shot
 *
 * Have you ever talked on the phone and cook dinner?
 * That's an example of multi-threading.
 *
 */

#include <QCoreApplication>
#include <QTimer>

void test(){
    qInfo() << "Thank you for waiting";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Please wait...";

    QTimer::singleShot(5000, &test);

    return a.exec();
}
// what we're doing here is we have an app(QCoreApp),
// we're going to start a timer, and then this is going to run
// in a seperate thread altogether for 5 secs, and then it's going to wake up
// and come back to this(singleShot) thread and call test func.
// even while we're sitting in an event loop, turning around,
// waiting on our app to do its thing.







