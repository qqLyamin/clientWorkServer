#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Widget)
{
	ui->setupUi(this);

	connect( &socket, &QTcpSocket::readyRead,
             this, &Widget::dataInSocket );

	socket.connectToHost( "192.168.2.44", 17888 );
}

Widget::~Widget()
{
	delete ui;
}

void Widget::dataInSocket()
{
    ui->textEdit->append( QString(socket.readAll()) );
}

void Widget::on_sendButton_clicked()
{
    if (!connected) {
        socket.close();
    }

    if (socket.isOpen()) {
        qDebug() << ui->lineEdit->text().toUtf8();
        messageToSend(ui->lineEdit->text().toUtf8());
    } else {
        socket.connectToHost( "192.168.2.44", 17888 );
        qDebug() << ui->lineEdit->text().toUtf8() << "2";
        messageToSend(ui->lineEdit->text().toUtf8());
    }
}

void Widget::messageToSend(const char * income)
{
    socket.write(income);
    if (QString(income) == "goodbye") {
        connected = false;
    }
}
