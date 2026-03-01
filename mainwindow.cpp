#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "registerwindow.h"
#include "./ui_registerwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include "passwordutil.h"
#include "dashboardwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("MyLoginApp.db");

    if (!db.open()) {
        qDebug() << "Erro ao abrir banco de dados";
    } else {
        qDebug() << "BANCO ABRIU COM SUCESSO!";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnLogin_clicked()
{
    QString email = ui->inputEmail->text();
    QString senha = ui->inputSenha->text();

    if (email == "") {
        ui->msgEmail->setText("Preencha a senha.");
        return;
    }

    if (senha == "") {
        ui->msgSenha->setText("Preencha a senha.");
        return;
    }

    QSqlQuery checkQuery;

    checkQuery.prepare(
        "SELECT * FROM users WHERE email = :email"
    );

    checkQuery.bindValue(":email", email);

    checkQuery.exec();

    if (checkQuery.next()) {
        // QString emailDb = checkQuery.value("email").toString();
        QString senhaDb = checkQuery.value("senha").toString();

        if (PasswordUtil::hashPassword(senha) != senhaDb) {
            QMessageBox::critical(
                this,
                "Usuário incorreto",
                "Usuário/Senha incorretos."
            );

            return;
        }

        DashboardWindow *dashboard = new DashboardWindow();

        dashboard->show();

        this->close();

    } else {
        QMessageBox::critical(
            this,
            "Usuário incorreto",
            "Usuário não encontrado."
        );
    }
}

void MainWindow::on_btnRegister_clicked()
{
    RegisterWindow *registerWindow = new RegisterWindow(this);
    registerWindow->show();
}
