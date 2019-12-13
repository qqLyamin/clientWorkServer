#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QDebug>

logIn::logIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logIn)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

logIn::~logIn()
{
    delete ui;
}

void logIn::accept()
{
    if (ui->lineEdit_name->text() != "" && ui->lineEdit_password->text() != "") {
        QString name = QString(ui->lineEdit_name->text());
        QString pw = QString(ui->lineEdit_password->text());

        emit checkClient(name, pw);
    }
}

void logIn::login_ok()
{
    this->close();
    emit login_ok_signal();
}

void logIn::login_no()
{
    QMessageBox msg;
    msg.setText("Wrong!");
    msg.exec();
    emit wrongLogin();
}
