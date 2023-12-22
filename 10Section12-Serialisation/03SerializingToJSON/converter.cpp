#include "converter.h"

Converter::Converter(QObject *parent)
    : QObject{parent}
{

}

void Converter::writeJson(Test &obj, QString path)
{
    QVariantMap map;
    QVariantMap items;
    map["name"] = obj.getName();
    foreach (QString key, obj.getMap().keys()) {
        items.insert(key, QVariant(obj.getMap().value(key)));
    }

    map["items"] = QVariant(items);

    QJsonDocument document = QJsonDocument::fromVariant(map);

    QFile file{path};
    if(!file.open(QIODevice::WriteOnly)){
        qCritical() << "Could not write file!";
        qCritical() << file.errorString();
        return ;
    }

    file.write(document.toJson());
    file.close();
}


/* Major takeaway is you can simply read that document, unlike QDataStream,
 * it doesn't have to be a specific order.
 */
Test *Converter::readJson(QString path)
{
    QFile file{path};
    if(!file.open(QIODevice::ReadOnly)){
        qCritical() << "Could not read file!";
        qCritical() << file.errorString();
        return nullptr;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(data);

    Test *t = new Test();
    t->setName(document["name"].toString());

    QVariantMap vMap = qvariant_cast<QVariantMap>(document["items"]);

    QMap<QString, QString> map;
    foreach (QString key, vMap.keys()) {
        map.insert(key, vMap[key].toString());
    }

    t->setMap(map);

    return t;

/* Major takeaway is you can simply read that document, unlike QDataStream,
 * it doesn't have to be a specific order.
 */
}











