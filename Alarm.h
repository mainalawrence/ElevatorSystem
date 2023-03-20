#ifndef ALARM_H
#define ALARM_H
#include<QObject>
#include<QTimer>
#include<iostream>

using namespace std;

class Alarm :public QObject{
    Q_OBJECT
    private:
    QTimer *timer;
    bool mhelp;
    bool mfire;
    bool moverload;
    bool mpwer_out;
    bool mobstacles;
    public slots:
    bool help(){
        cout<<"\ncalling for help....\n"<<endl;
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(call911()));
        timer->start(5000);

        return true;
    }
    //calling the fire function
    bool fire(){
    cout<<"********Warning Fire*******"<<endl;
   return true;
    }
    //when the lift is overloaded with people
    bool overload(){
        cout<<"\n*********warning Overloaded********\n"<<endl;
        return true;
    }
   // when the its stack
    bool obstacles(){
        cout<<"\n************Power is out***********\n"<<endl;
   return true;
    }
    //battary is low
    bool power_out(){
    cout<<"\n************Power is out**************\n"<<endl;
   return true;
    }
    //calling 911 after calling for help after 10 seconds
    void call911(){
      cout<<"\n*****************Calling 911***********\n"<<endl;
      disconnect(timer, SIGNAL(timeout()), this, SLOT(call911()));
    }

};
#endif // ALARM_H
