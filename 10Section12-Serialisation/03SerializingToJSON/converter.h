#ifndef CONVERTER_H
#define CONVERTER_H

/* The reason why we're doing this(serializing to JSON) in a SEPERATE class
 * is because as standards come and go, we don't want to continually
 * modify this(Test) object class. Instead, just simply want to use a converter.
 * This is going to be a specialized converter for this(Test) class in a
 * production environment, you would actually use templates...
 */

#include <QObject>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QVariant>     // wrapper around an unknown obj type
#include <QVariantMap>  // Synonym for QMap<QString, QVariant>.
#include <QJsonObject>  // like QObject
#include <QJsonArray>
#include <QJsonDocument>
#include <QMap>
#include "test.h"

class Converter : public QObject
{
    Q_OBJECT
public:
    explicit Converter(QObject *parent = nullptr);

//  as standards come and go, we could simply say,
//  write whatever standard, read whatever standard...
    static void writeJson(Test &obj, QString path);
    static Test* readJson(QString path);

signals:

};

#endif // CONVERTER_H










