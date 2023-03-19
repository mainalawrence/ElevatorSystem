#ifndef HALL_BUTTON_H
#define HALL_BUTTON_H
#include<string>
using namespace std;

class Hall_button{
    private:
    int floor_number;
    string direction;
    public:
    int getFloorNo(){
        return this->floor_number;
    }
    string getDirection(){
        return this->direction;
    }
};
#endif // HALL_BUTTON_H
