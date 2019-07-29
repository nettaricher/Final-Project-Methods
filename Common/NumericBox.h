#pragma once
#include "Control.h"
#include "Button.h"

class NumericBox : public Control
{
private:
    int max, min, value, width;
    bool focus;

public:
    NumericBox(Border *border, short left, short top);
    void draw(Graphics &GUI, int x, int y, size_t z);
    void mousePressed(int x, int y, bool isLeft);
    void keyDown(int keyCode, char charecter, Graphics &GUI);
    void onFocus(bool flag);
    int getWidth() { return width; };
    bool canGetFocus() { return FALSE; };
    ~NumericBox();
};