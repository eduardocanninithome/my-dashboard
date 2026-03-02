#ifndef LOCALCONNECTIONDB_H
#define LOCALCONNECTIONDB_H

#include <QSqlDatabase>

class LocalConnectionDb
{
public:
    static constexpr const char* CONNECTION_NAME = "session_connection";
    static bool abrirConexaoBanco();
    static QSqlDatabase database();
};

#endif // LOCALCONNECTIONDB_H
