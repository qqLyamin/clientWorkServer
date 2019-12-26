#ifndef ENTRY_H
#define ENTRY_H

#include <QDialog>
#include "widget.h"
#include "login.h"

namespace Ui {
class entry;
}

class entry : public QDialog
{
    Q_OBJECT

    logIn * login;
    Widget * w;
    bool recontruction =  false;

public:
    explicit entry(QWidget *parent = nullptr);
    ~entry();

private:
    Ui::entry *ui;


signals:
    void registrate(const QString &, const QString &);
    // QDialog interface
public slots:
    void login_ok();
    void accept();
private slots:
    void returned();
    void reg_no();
    void reg_ok();
    void on_buttonLogIn_clicked();
    void wrongLogin();
};

#endif // ENTRY_H
