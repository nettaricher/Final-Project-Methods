#pragma once
#include "Control.h"
#include "border.h"

class TextBox : public Control
{
private:
    int width, height, cursor;
    bool isFocus;
    string value;

public:
    TextBox();
    TextBox(Border *border, short left, short top, int width, int height);
    ~TextBox();
    void setValue(string val);
    string getValue();
    void draw(Graphics &GUI, int x, int y, size_t z);
    void mousePressed(int x, int y, bool isLeft);
    void keyDown(int keyCode, char charecter, Graphics &GUI);
    void onFocus(bool flag);
    bool isInsideBoundaries(int posX, int posY);
    bool canGetFocus() { return TRUE; };
    int getWidth() { return width; };
};