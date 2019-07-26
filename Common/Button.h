#pragma once
#include "./Label.h"

class Button : public Control
{
private:
    string value;
    int width, height;
    bool isClicked;
    vector<Control *> events;

public:
    Button(Border *border, short left, short top, string value);
    void draw(Graphics &GUI, int x, int y, size_t z);
    void mousePressed(int x, int y, bool isLeft);
    bool canGetFocus() { return FALSE; };
    int getWidth();
    void setEvent(Control *c);
    ~Button();
};