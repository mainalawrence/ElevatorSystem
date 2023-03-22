#ifndef ELEVATOR_H
#define ELEVATOR_H

class Elevator{
    private:
    bool direction;
    int current_floor;
    public:
    bool move();
    bool stop();
    bool status();
};

#endif // ELEVATOR_H
