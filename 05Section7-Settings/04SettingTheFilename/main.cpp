/* Why
 * We want to control where the file is saved
 * How
 * Add it to our directory
 */
#include <QCoreApplication>
#include <QSettings>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename{a.applicationDirPath() + "/settings.ini"};
    qInfo() << filename;

    QSettings settings(filename, QSettings::Format::IniFormat);
    settings.beginGroup("people");
    settings.setValue("Baris", 32);

    settings.sync();

    qInfo() << "Tammy:" << settings.value("Tammy", QVariant("Person not found"));
    qInfo() << "Baris:" << settings.value("Baris", QVariant("Person not found"));

    settings.endGroup();

    return a.exec();
}









