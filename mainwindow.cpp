#include "mainwindow.h"
#include "ui_mainwindow.h"
extern QString serverIP;
extern QString serverPort;
extern QString userName;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //
    //ui->m_serverIPLineEdit->setText("127.0.0.1");
    //ui->m_serverPortLineEdit_2->setText("5550");
    ////快捷键尝试
    //ui->pushButton_2->setShortcut(Qt::Key_Enter|Qt::Key_Return);
    //connect(ui->pushButton_2,SIGNAL(returnPressed(),this,SLOT(clicked())));
    //connect(ui->m_sendTextEdit, SIGNAL(returnPressed()), ui->pushButton_2, SLOT(on_pushButton_2_clicked()));
    //////////connet to the server
    mp_clientSocket = new QTcpSocket();
//    QString ip = ui->m_serverIPLineEdit->text();\
//    int port = ui->m_serverPortLineEdit_2->text().toInt();
    mp_clientSocket->connectToHost(serverIP, serverPort.toInt());
    if(!mp_clientSocket->waitForConnected(30000))
    {
        QMessageBox::information(this, "QT网络通信", "连接服务端失败！");
        return;
    }
     connect(mp_clientSocket, SIGNAL(readyRead()), this, SLOT(ClientRecvData()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked(){

    //获取TextEdit控件中的内容
    QString sendMsg = userName + ":" + ui->m_sendTextEdit->toPlainText();
    char sendMsgChar[1024] = {0};
    strcpy_s(sendMsgChar, sendMsg.toStdString().c_str());
    int sendRe = mp_clientSocket->write(sendMsgChar, strlen(sendMsgChar));
    if(sendRe == -1)
    {
         QMessageBox::information(this, "QT网络通信", "向服务端发送数据失败！");
         return;
    }
    else
        ui->m_sendTextEdit->setText("");
}
void MainWindow::ClientRecvData(){
    //将接收内容存储到字符串中
    char recvMsg[1024] = {0};
    int recvRe = mp_clientSocket->read(recvMsg, 1024);
    if(recvRe == -1)
    {
        QMessageBox::information(this, "QT网络通信", "接收服务端数据失败！");
        return;
    }
    QString showQstr = recvMsg;
    ui->m_recvTextEdit_2->setText(showQstr);
}
