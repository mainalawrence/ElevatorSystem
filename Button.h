#ifndef BUTTON_H
#define BUTTON_H

class Button{
    private:
    bool milluminate;
    bool mup;
    bool mdown;
    public:
    bool illuminate();
    bool cancel_illuminate();
    bool up();
    bool down();
};

#endif // BUTTON_H
