#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"Alarm.h"
#include "Door.h"
#include "Display.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void ring();
    bool openDoors();
    bool closeDoors();
    bool floor1();
    bool floor2();
    bool floor3();
    bool floor4();
    bool floor5();
    bool floor6();
    bool ilTimer();
    void HandleBattary();
private slots:
    void on_startbtn_clicked();
    void on_resetbtn_clicked();


private:
    Ui::MainWindow *ui;
    Alarm *malarm=nullptr;
    Door *mdoor=nullptr;
    Display *messg=nullptr;
    int mfloorNumber=1;
    bool movingup=true;
    void Handleilluminiation();
    void reset();
    QTimer *timer;
     QTimer *battary;
    int mfloorpos=1;
    int mbattary=100;
    bool mOn=false;
};


#endif // MAINWINDOW_H
