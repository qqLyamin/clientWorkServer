#ifndef WIDGET_H
#define WIDGET_H

#include <QTimer>
#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
	Q_OBJECT

    QTcpSocket socket;
	QTimer tick;
	int number = 0;

    bool connected = false;

public:

    QString name;

	explicit Widget(QWidget *parent = nullptr);
	~Widget();

private:
	Ui::Widget *ui;
    void messageToSend(const char *);

private slots:

	void dataInSocket();
    void on_sendButton_clicked();

    void on_lineEdit_returnPressed();
    void on_pushButton_clicked();

    void on_logoutButton_clicked();

public slots:
    void registrate(const QString &, const QString &);
    void checkClient(const QString &, const QString &);

signals:
    void reg_no();
    void reg_ok();
    void login_ok();
    void login_no();
};

#endif // WIDGET_H
