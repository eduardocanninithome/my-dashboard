#include "remoteconnectiondb.h"
#include "envloader.h"

#include <QSqlError>
#include <QDebug>

bool RemoteConnectionDb::abrirConexaoBanco()
{
    QSqlDatabase db;

    if (QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database();
    else
        db = QSqlDatabase::addDatabase(
            EnvLoader::get("DB_DRIVER")
        );

    db.setHostName(EnvLoader::get("DB_HOST"));
    db.setDatabaseName(EnvLoader::get("DB_NAME"));
    db.setUserName(EnvLoader::get("DB_USER"));
    db.setPassword(EnvLoader::get("DB_PASS"));
    db.setPort(EnvLoader::get("DB_PORT").toInt());

    if (!db.open()) {
        qDebug() << "❌ ERRO AO CONECTAR:";
        qDebug() << db.lastError().text();
        qDebug() << EnvLoader::get("DB_HOST");
        qDebug() << EnvLoader::get("DB_NAME");
        qDebug() << EnvLoader::get("DB_USER");

        return false;
    }

    qDebug() << "✅ Banco remoto conectado!";
    return true;
}

QSqlDatabase RemoteConnectionDb::database()
{
    return QSqlDatabase::database();
}
