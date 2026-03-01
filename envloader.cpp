#include "envloader.h"
#include <QFile>
#include <QTextStream>

QMap<QString, QString> EnvLoader::vars;

void EnvLoader::load(const QString &path)
{
    QFile file(path);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);

    while (!in.atEnd()) {
        QString line = in.readLine();

        if (line.startsWith("#") || !line.contains("="))
            continue;

        QStringList parts = line.split("=");
        vars[parts[0].trimmed()] = parts[1].trimmed();
    }
}

QString EnvLoader::get(const QString &key)
{
    return vars.value(key);
}
