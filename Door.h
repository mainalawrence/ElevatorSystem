#ifndef DOOR_H
#define DOOR_H

class Door{
    bool mclosed=true;
    public:
   // check if the door is closed it opens the door
    bool open(){
        if(mclosed==false){
            return false;
        }
        else
        mclosed=false;
        return true;
    }
    //check if the door is open it closes the door
    bool close(){
        if(mclosed==true){
            return false;
        }
        mclosed=true;
        return true;
    }
};

#endif // DOOR_H
