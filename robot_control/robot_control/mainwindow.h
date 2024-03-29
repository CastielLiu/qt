#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QCloseEvent>
#include <string>
#include <thread>
#include <chrono>
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void sendCmdThread();
    virtual void closeEvent(QCloseEvent *event);

private slots:
    void on_pushButton_connect_clicked(bool checked);

    void on_pushButton_up_released();

    void on_pushButton_up_pressed();

    void on_pushButton_down_pressed();

    void on_pushButton_down_released();

    void on_pushButton_left_pressed();

    void on_pushButton_left_released();

    void on_pushButton_right_pressed();

    void on_pushButton_right_released();

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;

    std::shared_ptr<std::thread> send_cmd_thread;
    std::string cmd_header;
    bool send_cmd_thread_flag;
    std::vector<bool> keys_state;
};

#endif // MAINWINDOW_H
