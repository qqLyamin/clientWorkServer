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
    void on_buttonLogIn_clicked();
};

#endif // ENTRY_H
