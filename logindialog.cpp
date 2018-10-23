#include "logindialog.h"
#include "ui_logindialog.h"
QString serverIP;
QString serverPort;
QString userName;
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    //
    ui->serverIP_lineEdit->setText("127.0.0.1");
    ui->serverPort_lineEdit->setText("5550");
    ui->userName_lineEdit->setText("余乔");
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_join_pushButton_clicked()
{
    serverIP = ui->serverIP_lineEdit->text();
    serverPort = ui->serverPort_lineEdit->text();
    userName = ui->userName_lineEdit->text();
}
