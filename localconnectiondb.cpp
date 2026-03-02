#include "localconnectiondb.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

bool LocalConnectionDb::abrirConexaoBanco()
{
    QSqlDatabase db;

    if (QSqlDatabase::contains(CONNECTION_NAME))
        db = QSqlDatabase::database(CONNECTION_NAME);
    else
        db = QSqlDatabase::addDatabase("QSQLITE", CONNECTION_NAME);

    db.setDatabaseName("session.db");

    if (!db.open()) {
        qDebug() << "❌ Erro ao abrir SQLite:";
        qDebug() << db.lastError().text();
        return false;
    }

    qDebug() << "✅ SQLite local conectado!";

    // Criar tabela de sessão automaticamente
    QSqlQuery query(db);

    query.exec(
        "CREATE TABLE IF NOT EXISTS session ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "user_id INTEGER,"
        "nome TEXT,"
        "email TEXT,"
        "token TEXT,"
        "created_at DATETIME DEFAULT CURRENT_TIMESTAMP"
        ")"
        );

    if (query.lastError().isValid()) {
        qDebug() << "Erro ao criar tabela session:";
        qDebug() << query.lastError().text();
    }

    return true;
}

QSqlDatabase LocalConnectionDb::database()
{
    return QSqlDatabase::database(CONNECTION_NAME);
}
