#ifndef BELL_H
#define BELL_H

#include<QSound>
class Bell{
    private:
    bool mbell=true;
    public:
    bool bell_val(){
        if(mbell){
            QSound bells("mysounds/bells.wav");
            bells.play();
        }
        return true;
    }
};
#endif // BELL_H
