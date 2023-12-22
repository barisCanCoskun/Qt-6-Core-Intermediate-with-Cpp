/* Why
 * Sometimes we want to know what groups are there
 * How
 * childGroups
 */
#include <QCoreApplication>
#include<QSettings>
#include<QStringList>
#include<QRandomGenerator>

void saveAge(QSettings &settings, QString group, QString name, int age){
    settings.beginGroup(group);
    settings.setValue(name, age);
    settings.endGroup();
}

int getAge(QSettings &settings, QString group, QString name){
    settings.beginGroup(group);
    if(!settings.contains(name)){
        qWarning() << "Does not contain" << name << "in" << group;
        settings.endGroup();
        return 0;
    }

    bool ok;
    int value = settings.value(name).toInt(&ok);
    settings.endGroup();

    if(!&ok){
        qWarning() << "Could not convert to int";
        return 0;
    }

    return value;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setOrganizationName("BarisCan");
    QCoreApplication::setOrganizationDomain("BarisCan.com");
    QCoreApplication::setApplicationName("Tester");

    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());

    saveAge(settings, "people", "Baris", 32);
    saveAge(settings, "tea", "caykur", 2);
    saveAge(settings, "tea", "Baris", 5);

    QStringList people;
    people << "Baris" << "Ahmet" << "Kadir" << "Semih";
    int highestValue{100};
    foreach (QString person, people) {
        int value{QRandomGenerator::global()->bounded(highestValue)};
        saveAge(settings, "test", person, value);
    }

    settings.sync();    // Writes any unsaved changes to permanent storage,
//    and reloads any settings that have been changed
//    in the meantime by another application.

    qInfo() << "File:" << settings.fileName();

//    navigate through the entire setting hierarchy
    foreach (QString group, settings.childGroups()) {
        settings.beginGroup(group);
        qInfo() << "Group:" << group;

        foreach (QString key, settings.childKeys()) {
//            settings.childKeys(): Returns a list of all top-level keys
//            that can be read using the QSettings object.
//            If a group is set using beginGroup(),
//            the top-level keys in that group are returned
            qInfo() << "..." << key << ":" << settings.value(key).toString();
        }

        settings.endGroup();
    }

    return a.exec();
}










