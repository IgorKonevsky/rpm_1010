/**
* @file mainwindow.h
* @author Kirpichenko Daniil <ko1lmain4@gmail.com>
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebSocket>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString ships [10] = {"", "", "", "", "", "", "", "", "", ""};
    int iter = 0;
    QString greatTmp;
    bool isAShip (QString str);
    QString getEnd(std::string);
    QString getFirst(std::string);
private slots:
private:
    Ui::MainWindow *ui;
    //Пользователь
    QWebSocket* user;
    //Ник пользователя и IP сервера
    QString nickName, enemy, hostIP;
    //Порт сервера
    bool queue;
    int hostPort;
};
#endif // MAINWINDOW_H
