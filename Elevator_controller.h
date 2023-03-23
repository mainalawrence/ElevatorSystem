#ifndef ELEVATOR_CONTROLLER_H
#define ELEVATOR_CONTROLLER_H
#include<QObject>
#include"Door.h"

class Elevator_controller:public QObject{
    Q_OBJECT
    int floor_id;
    int position;
    bool direction;

    public slots:
    //handle evevator stops
    bool stopElevator(){
    return true;
    }

    //handle evevator starts
    bool startElevator()
    {
    return true;
    }
    bool reset(){
    return true;
    }



};

#endif // ELEVATOR_CONTROLLER_H
