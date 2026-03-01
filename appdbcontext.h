#ifndef APPDBCONTEXT_H
#define APPDBCONTEXT_H

#include <QSqlDatabase>

class AppDbContext
{
public:
    static bool abrirConexaoBanco();
    static QSqlDatabase database();
};

#endif
