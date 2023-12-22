/*
 * QStringView
 *
 * Read only(fast access) to a QByteArray
 */

#include <QCoreApplication>
#include<QString>
#include<QStringView>

void display(QStringView view){
    qInfo() << view;

    qInfo() << "size:" << view.size();
    qInfo() << "constdata:" << view.constData();
    qInfo() << "sliced:" << view.sliced(1, 4);
    qInfo() << "contains \"ow\":" << view.contains(QString("ow"));
    qInfo() << "at:" << view.at(6);
    qInfo() << "indexof:" << view.indexOf('w');
    qInfo() << "index:" << view[0];

    foreach (QChar var, view) {
        qInfo() << var;
    }

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString str{"Heyy how r u doing today?"};
    QStringView view{str};
    display(view);

    return a.exec();
}















