#include <QApplication>
#include <QSqlQuery>
#include "mainwindow.h"
#include "envloader.h"
#include "remoteconnectiondb.h"
#include "localconnectiondb.h"
#include "dashboardwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString envPath =
        QCoreApplication::applicationDirPath() + "/.env";

    EnvLoader::load(envPath);

    RemoteConnectionDb::abrirConexaoBanco();
    LocalConnectionDb::abrirConexaoBanco();

    QSqlQuery query(LocalConnectionDb::database());

    query.exec("SELECT id FROM session LIMIT 1");

    if (query.next()) {
        DashboardWindow *dashboard = new DashboardWindow();
        dashboard->show();

        return a.exec();
    }

    MainWindow w;
    w.show();

    return a.exec();
}
