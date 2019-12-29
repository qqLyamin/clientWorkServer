#include "entry.h"
#include "ui_entry.h"

#include <QThread>
#include <QMessageBox>
#include <windows.h>

entry::entry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::entry)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    setFixedSize(this->width(), this->height());

    setWindowFlags(Qt::CustomizeWindowHint      /*|
                   Qt::WindowTitleHint          |
                   Qt::WindowMinimizeButtonHint |
                   Qt::WindowMaximizeButtonHint |
                   Qt::WindowCloseButtonHint    |
                   Qt::WindowSystemMenuHint     |
                   Qt::WindowContextHelpButtonHint */);
    this->setAttribute(Qt::WA_CustomWhatsThis);
    show();

    w = new Widget;
    connect(this, &entry::registrate, w, &Widget::registrate);
    connect(w, &Widget::reg_no, this, &entry::reg_no);
    connect(w, &Widget::reg_ok, this, &entry::reg_ok);
}

entry::~entry()
{
//    if (recontruction) {
//        entry * x = new entry;
//        x->show();
//    }
    delete ui;
}

void entry::accept()
{
    if (ui->lineEdit_name->text() != "" && ui->lineEdit_password->text() != "") {
        QString name = QString(ui->lineEdit_name->text());
        QString pw = QString(ui->lineEdit_password->text());
        emit registrate(name, pw);
    }
}

void entry::returned()
{
    this->show();
}

void entry::reg_no()
{
    QMessageBox msg;
    msg.setText("wrong name");
    msg.exec();
}

void entry::reg_ok()
{
    QMessageBox msg;
    msg.setText("you are registrated");
    ui->lineEdit_name->clear();
    ui->lineEdit_password->clear();
    msg.exec();
    this->hide();
    Sleep(1000);
    login_ok();
}

void entry::login_ok()
{
    //link:
    if (w->name != "") {
        w->show();
        this->hide();
    } else {
        login = new logIn;
        connect(login, &logIn::checkClient, w, &Widget::checkClient);
        connect(w, &Widget::login_ok, login, &logIn::login_ok);
        connect(w, &Widget::login_no, login, &logIn::login_no);
        connect(login, &logIn::login_ok_signal, this, &entry::login_ok);
        connect(login, &logIn::wrongLogin, this, &entry::wrongLogin);
        connect(login, &logIn::return_to_entry, this, &entry::returned);
        login->show();
        //goto link;
    }
}

void entry::on_buttonLogIn_clicked()
{
    login = new logIn;
    connect(login, &logIn::checkClient, w, &Widget::checkClient);
    connect(w, &Widget::login_ok, login, &logIn::login_ok);
    connect(w, &Widget::login_no, login, &logIn::login_no);
    connect(login, &logIn::login_ok_signal, this, &entry::login_ok);
    connect(login, &logIn::wrongLogin, this, &entry::wrongLogin);
    login->show();
    this->hide();
}

void entry::wrongLogin()
{
    this->show();
}
