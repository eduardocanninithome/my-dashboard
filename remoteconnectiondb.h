#ifndef REMOTECONNECTIONDB_H
#define REMOTECONNECTIONDB_H

#include <QSqlDatabase>

class RemoteConnectionDb
{
public:
    static bool abrirConexaoBanco();
    static QSqlDatabase database();
};

#endif
