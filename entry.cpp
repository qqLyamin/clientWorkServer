#include "entry.h"
#include "ui_entry.h"


entry::entry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::entry)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    show();

    login = new logIn;
    connect(login, &logIn::checkClient, w, &Widget::checkClient);
    connect(w, &Widget::login_ok, login, &logIn::login_ok);
    connect(w, &Widget::login_no, login, &logIn::login_no);
    connect(login, &logIn::login_ok_signal, this, &entry::login_ok);
    connect(login, &logIn::wrongLogin, this, &entry::on_buttonLogIn_clicked);
}

entry::~entry()
{
    delete ui;
}

void entry::accept()
{
    if (ui->lineEdit_name->text() != "" && ui->lineEdit_password->text() != "") {
        QString name = QString(ui->lineEdit_name->text());
        QString pw = QString(ui->lineEdit_password->text());
        emit registrate(name, pw);
        QDialog::accept();
    }
}

void entry::login_ok()
{
    w = new Widget;
    connect(this, &entry::registrate, w, &Widget::registrate);
    w->show();
    this->hide();
}

void entry::on_buttonLogIn_clicked()
{
    login->show();
    this->hide();
}
