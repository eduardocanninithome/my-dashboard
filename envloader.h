#ifndef ENV_H
#define ENV_H

#include <QString>
#include <QMap>

class EnvLoader {
public:
    static void load(const QString &path);
    static QString get(const QString &key);

private:
    static QMap<QString, QString> vars;
};

#endif
