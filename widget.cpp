#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Widget)
{
	ui->setupUi(this);    
    setAttribute(Qt::WA_DeleteOnClose);
	connect( &socket, &QTcpSocket::readyRead,
             this, &Widget::dataInSocket );

    socket.connectToHost( "192.168.2.44", 17888 );
    connected = true;
}

Widget::~Widget()
{
    socket.disconnectFromHost();
	delete ui;
}

void Widget::dataInSocket()
{
    QString tmp = QString(socket.readAll());
    qDebug() << tmp << endl;
    if ( tmp.startsWith("#%#%#") && tmp.endsWith("#%#%#") ) {
        if (tmp.contains("ok")) {
            emit login_ok();
            this->show();
            ui->lbl_nickname->setText(name);
        } else if (tmp.contains("no")) {
            emit login_no();
        }
    } else if ( tmp.startsWith("$#$#$") && tmp.endsWith("$#$#$") ){
        if (tmp.contains("no")) {
            emit reg_no();
        }
        if (tmp.contains("ok")) {
            emit reg_ok();
        }
    } else {
        ui->textEdit->append( tmp );
    }
}

void Widget::on_sendButton_clicked()
{
    if (!connected) {
        socket.connectToHost( "192.168.2.44", 17888 );
    }

    if (socket.isOpen()) {
        qDebug() << ui->lineEdit->text().toUtf8();
        connected = true;
        messageToSend(ui->lineEdit->text().toUtf8());
        ui->textEdit->append( name + ": " + ui->lineEdit->text() );
    }

    ui->lineEdit->clear();
}

void Widget::messageToSend(const char * income)
{
    QString tmp = name + ": " + income;
    socket.write(tmp.toUtf8());
}

void Widget::on_lineEdit_returnPressed()
{
    on_sendButton_clicked();
}

void Widget::on_pushButton_clicked()
{
    close();
}

void Widget::registrate(const QString & name, const QString & password)
{
    if (!connected) {
        socket.connectToHost( "192.168.2.44", 17888 );
    }

    if (socket.isOpen()) {
        qDebug() << name << " " << password;
        connected = true;
        socket.write("$#$#$" + name.toUtf8() + "$#$#$" + password.toUtf8() + "$#$#$");
    }
}

void Widget::checkClient(const QString & name, const QString & password)
{
    if (!connected) {
        socket.connectToHost( "192.168.2.44", 17888 );
    }

    if (socket.isOpen()) {
        qDebug() << name << " " << password;
        connected = true;
        this->name = name;
        socket.write("#%#%#" + name.toUtf8() + "#%#%#" + password.toUtf8() + "#%#%#");
    }
}

void Widget::on_logoutButton_clicked()
{
    close();
}
