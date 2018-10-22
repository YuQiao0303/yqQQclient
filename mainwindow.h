#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QMessageBox>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void on_m_connectServerBtn_clicked();

    void on_pushButton_2_clicked();

    void ClientRecvData();

private:
    //Ui::SocketTCPClient *ui;
    QTcpSocket *mp_clientSocket;

};

#endif // MAINWINDOW_H
