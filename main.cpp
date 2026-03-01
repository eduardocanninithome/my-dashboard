#include <QApplication>
#include "mainwindow.h"
#include "envloader.h"
#include "appdbcontext.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString envPath =
        QCoreApplication::applicationDirPath() + "/.env";

    EnvLoader::load(envPath);

    AppDbContext::abrirConexaoBanco();

    MainWindow w;
    w.show();
    return a.exec();
}
