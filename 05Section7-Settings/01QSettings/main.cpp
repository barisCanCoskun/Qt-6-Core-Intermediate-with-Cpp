#include <QCoreApplication>
//#include<QDebug>
#include<QSettings>

void info(QSettings &settings){
    settings.setFallbacksEnabled(false);
    qInfo() << "File:" << settings.fileName();
    qInfo() << "Keys:" << settings.allKeys();
}

void save(QSettings &settings){
//    setter
    settings.setValue("testing", 246); // key, value pair
    qInfo() << settings.status();   // returns a status code
//    indicating the first error that was met by QSettings,
//    or QSettings::NoError if no error occured which value is 0.
    qInfo() << "Saved";
}

void load(QSettings &settings){
    info(settings);
//    getter
    qInfo() << settings.value("testing").toString();
    bool ok;
    qInfo() << settings.value("testing").toInt(&ok);
    if(!ok){
//        something bad happened
        qInfo() << "Could not convert to int";
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setOrganizationName("BarisCan");
    QCoreApplication::setOrganizationDomain("BarisCan.com");
    QCoreApplication::setApplicationName("Tester");

//    QSettings settings;
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    qInfo() << "No settings yet...saving...";
    save(settings);
    if(settings.allKeys().length() == 0){   // in linux machine this works but not in macOS
        qInfo() << "No settings yet...saving...";
        save(settings);
    }
    else{
        qInfo() << "Loading the settings...";
        load(settings);
    }

    return a.exec();
}


















