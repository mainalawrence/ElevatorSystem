#ifndef DISPLAY_H
#define DISPLAY_H

#include<string>
using namespace std;

class Display{
    private:
    string message;
    string warning;
    public:
    //message getter
    string getMessage(){
        return this->message;
    }
    //waring getter
    string getWarning(){
        return this->warning;
    }
    // message setter
    void setMessage(string sms){
        if(!sms.compare(this->message)){
            this->message=sms;
        }
    }
   // warning setter
    void setwarning(string warn){
        if(!warning.compare(this->message)){
            this->warning=warn;
        }
    }
};
#endif // DISPLAY_H
