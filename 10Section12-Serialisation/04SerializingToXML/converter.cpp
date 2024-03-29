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

void Converter::writeXml(Test &obj, QString path)
{
    QFile file{path};
    if(!file.open(QIODevice::WriteOnly)){
        qCritical() << "Could not write file!";
        qCritical() << file.errorString();
        return ;
    }

    QXmlStreamWriter stream(&file);
    stream.setAutoFormatting(true);

    stream.writeStartDocument();
    stream.writeStartElement("test");
    stream.writeAttribute("name", obj.getName());  // can think of them as parameters in func definition
    stream.writeStartElement("items");

    foreach (QString key, obj.getMap().keys()) {
        stream.writeStartElement("item");
        stream.writeAttribute("key", key);
        stream.writeAttribute("value", obj.getMap().value(key));
        stream.writeEndElement();
    }

    stream.writeEndElement();  // can think of as concept of scope
    stream.writeEndElement();  // can think of as concept of scope
    stream.writeEndDocument(); // can think of as concept of scope

    file.close();  // don't need to do that bec as it goes out of scope,
//    it should attempt to close it, but dont always trust that.
}

Test *Converter::readXml(QString path)
{
    QFile file{path};
    if(!file.open(QIODevice::ReadOnly)){
        qCritical() << "Could not read file!";
        qCritical() << file.errorString();
        return nullptr;
    }

    QByteArray data = file.readAll();
    file.close();

    QXmlStreamReader stream(data);
    Test *t = new Test();
    QMap<QString, QString> map;

    while (!stream.atEnd()) {
        QXmlStreamReader::TokenType token = stream.readNext();
        switch (token) {
        case QXmlStreamReader::Comment:
            break;
        case QXmlStreamReader::DTD:
            break;
        case QXmlStreamReader::Characters:
            break;
        case QXmlStreamReader::ProcessingInstruction:
            break;
        case QXmlStreamReader::EntityReference:
            break;
        case QXmlStreamReader::NoToken:
            break;
        case QXmlStreamReader::Invalid:
            break;
        case QXmlStreamReader::StartDocument:
            break;
        case QXmlStreamReader::EndDocument:
            t->setMap(map);
            break;
        case QXmlStreamReader::StartElement:
            if(stream.name().toString() == "test"){
                QString name = stream.attributes().value("name").toString();
                t->setName(name);
            }
            if(stream.name().toString() == "item"){
                QString key = stream.attributes().value("key").toString();
                QString value = stream.attributes().value("value").toString();
                map.insert(key, value);
            }
            break;
        case QXmlStreamReader::EndElement:
            break;
        }
    }

    return t;
}











