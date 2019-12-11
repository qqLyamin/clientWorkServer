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
	explicit Widget(QWidget *parent = nullptr);
	~Widget();

private:
	Ui::Widget *ui;
    void messageToSend(const char *);

private slots:
	void dataInSocket();
    void on_sendButton_clicked();

};

#endif // WIDGET_H
