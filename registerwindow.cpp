#include "registerwindow.h"
#include "ui_registerwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include "passwordutil.h"

RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("MyLoginApp.db");

    if (!db.open()) {
        qDebug() << "Erro ao abrir banco de dados";
    } else {
        qDebug() << "BANCO ABRIU COM SUCESSO!";
    }

    QSqlQuery query;

    query.exec(
        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "nome TEXT,"
        "email TEXT UNIQUE,"
        "senha TEXT)"
    );
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_btnSave_clicked()
{
    QString nome = ui->inputNome->text();
    QString email = ui->inputEmail->text();
    QString senha = ui->inputSenha->text();
    QString confirmeSenha = ui->inputConfirmeSenha->text();

    ui->msgNome->setText("");
    ui->msgEmail->setText("");
    ui->msgSenha->setText("");
    ui->msgConfirmeSenha->setText("");

    if (nome == "") {
        ui->msgNome->setText("Preencha o nome.");
        return;
    }

    if (email == "") {
        ui->msgEmail->setText("Preencha o email.");
        return;
    }

    if (senha == "") {
        ui->msgSenha->setText("Preencha a senha.");
        return;
    }

    if (senha != confirmeSenha) {
        ui->msgConfirmeSenha->setText("As duas senhas devem ser iguais.");
        return;
    }

    QSqlQuery checkQuery;

    checkQuery.prepare(
        "SELECT id FROM users WHERE email = :email"
    );

    checkQuery.bindValue(":email", email);

    checkQuery.exec();

    if (checkQuery.next()) {
        QMessageBox::warning(
            this,
            "Email já cadastrado",
            "Já existe um usuário com esse email."
            );
        return;
    }

    QSqlQuery query;

    query.prepare(
        "INSERT INTO users (nome, email, senha) "
        "VALUES (:nome, :email, :senha)"
    );

    QString senhaHash = PasswordUtil::hashPassword(senha);

    query.bindValue(":nome", nome);
    query.bindValue(":email", email);
    query.bindValue(":senha", senhaHash);

    if (query.exec()) {
        QMessageBox::information(
            this,
            "Sucesso",
            "Usuário salvo com sucesso!"
        );

        accept();

    } else {
        QMessageBox::critical(
            this,
            "Erro",
            query.lastError().text()
        );
    }
}
