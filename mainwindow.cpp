#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QStyle>
#include<QSound>
#include<QDebug>
#include<QMediaPlayer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->powerlbl->setText(QString::number(this->mbattary));
     timer = new QTimer(this);
     battary=new QTimer(this);
     connect(battary, SIGNAL(timeout()), this, SLOT(HandleBattary()));
    //turn the doors to be gray in color to present closed door
    ui->leftDoor->setStyleSheet("background:gray");
    ui->rightDoor->setStyleSheet("background:gray");
    //set the display of the floor number
    ui->lcdNumber->setDigitCount(mfloorNumber);

    //decrelation
    //initialize the alarm class
    this->malarm=new Alarm();
     //initialize the Door class
    mdoor=new Door();
     //initialize the Display class
    messg=new Display();

    //connecting action buttons with necessary slots
   connect(ui->btnFire,SIGNAL(clicked()),malarm,SLOT(fire()));
   connect(ui->btnhelp,SIGNAL(clicked()),malarm,SLOT(help()));
   connect(ui->btnoverload,SIGNAL(clicked()),malarm,SLOT(overload()));
   connect(ui->btnpowerout,SIGNAL(clicked()),malarm,SLOT(power_out()));
   connect(ui->btnelvClose,SIGNAL(clicked()),this,SLOT(closeDoors()));
   connect(ui->btnelvOpen,SIGNAL(clicked()),this,SLOT(openDoors()));
    connect(ui->btnelvClose,SIGNAL(clicked()),this,SLOT(ring()));
    connect(ui->btnelvOpen,SIGNAL(clicked()),this,SLOT(ring()));
   // //connecting elevator buttons with necessary slots
   connect(ui->btnelv1,SIGNAL(clicked()),this,SLOT(floor1()));
   connect(ui->btnelv2,SIGNAL(clicked()),this,SLOT(floor2()));
   connect(ui->btnelv3,SIGNAL(clicked()),this,SLOT(floor3()));
   connect(ui->btnelv4,SIGNAL(clicked()),this,SLOT(floor4()));
   connect(ui->btnelv5,SIGNAL(clicked()),this,SLOT(floor5()));
   connect(ui->btnelv6,SIGNAL(clicked()),this,SLOT(floor6()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
//handle rign function
void MainWindow::ring()
{

    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sounds/bell.mp3"));
    player->setVolume(50);
    player->play();
}
//slots to open the doors
bool MainWindow::openDoors()
{
    if(!mOn){
         qDebug()<<"Battary low"<<endl;
        return false;
    }
if(mdoor->open()){

    ui->leftDoor->setStyleSheet("background:white");
    ui->rightDoor->setStyleSheet("background:white");
 ui->btnMessage->setText("Door Open");
 qDebug()<<"Door is open"<<endl;
}
return true;
}

bool MainWindow::closeDoors()
{
    if(!mOn){
         qDebug()<<"Battary low"<<endl;
        return false;
    }
    if(mdoor->close()){
       ui->leftDoor->setStyleSheet("background:gray");
       ui->rightDoor->setStyleSheet("background:gray");
       ui->btnMessage->setText("Door Close");
       qDebug()<<"Door is closed"<<endl;
    }
    return true;
}
//slot to handle floor 1 of the elevator
bool MainWindow::floor1()
{
    if(!mOn){
         qDebug()<<"Battary low"<<endl;
        return false;
    }
    if(mfloorNumber>1){
     movingup=false;
    }
    if(mfloorNumber<1){
     movingup=true;
    }
    connect(timer, SIGNAL(timeout()), this, SLOT(ilTimer()));
    timer->start(1000);
    mfloorpos=1;
    return true;
}
//slot to handle floor 2 of the elevator
bool MainWindow::floor2()
{
    if(!mOn){
         qDebug()<<"Battary low"<<endl;
        return false;
    }
    if(mfloorNumber>2){
     movingup=false;
    }
    if(mfloorNumber<2){
     movingup=true;
    }
    connect(timer, SIGNAL(timeout()), this, SLOT(ilTimer()));
    timer->start(1000);
    mfloorpos=2;
    return true;
}
//slot to handle floor 3 of the elevator
bool MainWindow::floor3()
{
    if(!mOn){
         qDebug()<<"Battary low"<<endl;
        return false;
    }
 qDebug()<<"@Door 3 floor Number"<<mfloorNumber<<endl;
if(mfloorNumber>3){
 movingup=false;
}
if(mfloorNumber<3){
 movingup=true;
}
connect(timer, SIGNAL(timeout()), this, SLOT(ilTimer()));
timer->start(1000);
mfloorpos=3;
return true;
}
//slot to handle floor 4 of the elevator
bool MainWindow::floor4()
{
    if(!mOn){
         qDebug()<<"Battary low"<<endl;
        return false;
    }
    if(mfloorNumber>4){
     movingup=false;
    }
    if(mfloorNumber<4){
     movingup=true;
    }
    connect(timer, SIGNAL(timeout()), this, SLOT(ilTimer()));
    timer->start(1000);
    mfloorpos=4;
    return true;
}
//slot to handle floor 5 of the elevator
bool MainWindow::floor5()
{
    if(!mOn){
         qDebug()<<"Battary low"<<endl;
        return false;
    }
    if(mfloorNumber>5){
     movingup=false;
    }
    if(mfloorNumber<5){
     movingup=true;
    }
    connect(timer, SIGNAL(timeout()), this, SLOT(ilTimer()));
    timer->start(1000);
    mfloorpos=5;
    return true;
}
//slot to handle floor 6 of the elevator
bool MainWindow::floor6()
{
    if(!mOn){
         qDebug()<<"Battary low"<<endl;
        return false;
    }
    if(mfloorNumber>6){
     movingup=false;
    }
    if(mfloorNumber<6){
     movingup=true;
    }
    connect(timer, SIGNAL(timeout()), this, SLOT(ilTimer()));
    timer->start(1000);
    mfloorpos=6;
    return true;
}
//check if button has reached its destination
bool MainWindow::ilTimer()
{
    if(!mOn){
         qDebug()<<"Battary low"<<endl;
        return false;
    }
    if(mfloorNumber==mfloorpos){
        disconnect(timer, SIGNAL(timeout()), this, SLOT(ilTimer()));
        QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl("qrc:/sounds/bell.mp3"));
        player->setVolume(50);
        player->play();
    }
qDebug()<<"@Door floor Number"<<mfloorNumber<<endl;
Handleilluminiation();
  if(movingup==true){
      mfloorNumber++;
  }
  if(movingup==false){
      mfloorNumber--;
  }
  return true;
}

void MainWindow::HandleBattary()
{
     this->mOn=true;

    if(this->mbattary==1){
    disconnect(battary, SIGNAL(timeout()), this, SLOT(HandleBattary()));
     this->mOn=false;
    }
    this->mbattary--;
    this->ui->powerlbl->setText(QString::number(this->mbattary));
    qDebug()<<"battary is "<<this->mbattary<<" %";

}
//handle and change the buttons colors
void MainWindow::Handleilluminiation()
{

     reset();
    if(movingup){
        if(mfloorNumber==1){
            ui->lcdNumber->display(mfloorNumber);
           ui->btn1u->setStyleSheet("background:Red");
        }
        if(mfloorNumber==2){
            ui->lcdNumber->display(mfloorNumber);
           ui->btn2u->setStyleSheet("background:Red");
        }
        if(mfloorNumber==3){
            ui->lcdNumber->display(mfloorNumber);
           ui->btn3u->setStyleSheet("background:Red");
        }
        if(mfloorNumber==4){
            ui->lcdNumber->display(mfloorNumber);
           ui->btn4u->setStyleSheet("background:Red");
        }
        if(mfloorNumber==5){
            ui->lcdNumber->display(mfloorNumber);
           ui->btn5u->setStyleSheet("background:Red");
        }
        if(mfloorNumber==6){
            ui->lcdNumber->display(mfloorNumber);
           ui->btn6d->setStyleSheet("background:Red");
        }
    }
    if(!movingup){
        if(mfloorNumber==1){
           ui->lcdNumber->display(mfloorNumber);
           ui->btn1u->setStyleSheet("background:Red");
        }
        if(mfloorNumber==2){
           ui->lcdNumber->display(mfloorNumber);
           ui->btn2d->setStyleSheet("background:Red");
        }
        if(mfloorNumber==3){
           ui->lcdNumber->display(mfloorNumber);
           ui->btn3d->setStyleSheet("background:Red");
        }
        if(mfloorNumber==4){
            ui->lcdNumber->display(mfloorNumber);
           ui->btn4d->setStyleSheet("background:Red");
        }
        if(mfloorNumber==5){
           ui->lcdNumber->display(mfloorNumber);
           ui->btn5d->setStyleSheet("background:Red");
        }
        if(mfloorNumber==6){
            ui->lcdNumber->display(mfloorNumber);
           ui->btn6d->setStyleSheet("background:Red");
        }
    }

}
//reset all up and down directional the buttons
void MainWindow::reset()
{
    ui->btn1u->setStyleSheet("background:white");
    ui->btn2u->setStyleSheet("background:white");
    ui->btn3u->setStyleSheet("background:white");
    ui->btn4u->setStyleSheet("background:white");
    ui->btn5u->setStyleSheet("background:white");
    ui->btn4u->setStyleSheet("background:white");
    ui->btn1u->setStyleSheet("background:white");
    ui->btn2d->setStyleSheet("background:white");
    ui->btn3d->setStyleSheet("background:white");
    ui->btn4d->setStyleSheet("background:white");
    ui->btn5d->setStyleSheet("background:white");
    ui->btn4d->setStyleSheet("background:white");
     ui->btn6d->setStyleSheet("background:white");
}

void MainWindow::on_startbtn_clicked()
{
    battary->start(3000);

}


void MainWindow::on_resetbtn_clicked()
{
this->mbattary=100;
 ui->powerlbl->setText(QString::number(this->mbattary));
 this->mOn=true;
}

