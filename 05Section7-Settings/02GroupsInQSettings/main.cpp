/*
 * Why
 * We want the settings in logical groups
 *
 * How
 * beginGroup / endGroup
 */
#include <QCoreApplication>
#include<QSettings>

void saveAge(QSettings &settings, QString group, QString name, int age){
//    key: name, value: age
    settings.beginGroup(group);
//    think of this like dealing with groups of people like
//    human resources, accounting, developers, you want to
//    begin addressing a specific GROUP
    settings.setValue(name, age);
    settings.endGroup();
//    meaning I'm now done talking to you
//    When you begin a conversation, you should end a conversation
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
//    we have 2 same keys, Baris and Baris, and we're not
//    overwriting those values. We have 2 different groups

    qInfo() << "Caykur" << getAge(settings, "tea", "caykur");
    qInfo() << "Baris (people)" << getAge(settings, "people", "Baris");
    qInfo() << "Baris (tea)" << getAge(settings, "tea", "Baris");

    return a.exec();
}










