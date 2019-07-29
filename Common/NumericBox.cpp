#include "NumericBox.h"
#include <iostream>

using namespace std;

NumericBox::NumericBox(Border *border, short left, short top) : Control(left, top, border), value(0), width(17), focus(FALSE)
{
}

void NumericBox::setValue(int val){
    value = val;
}

int NumericBox::getValue(){
    return value;
}

void NumericBox::onFocus(bool flag)
{
    focus = flag;
}

void NumericBox::draw(Graphics &GUI, int x, int y, size_t z)
{
    GUI.setBackground(Color::Cyan);

    short topBorder = top;
    short leftBorder = left;

    GUI.moveTo(leftBorder, topBorder);

    cout << (char)201;
    for (int i = 0; i < 17; i++)
    {
        cout << (char)205;
    }
    cout << (char)187;

    GUI.moveTo(leftBorder, topBorder + 1);
    cout << (char)186 << ' ' << "+" << ' ' << (char)221;

    for (int i = 0; i < 9; i++)
    {
        cout << ' ';
    }
    cout << (char)221 << ' ' << "-" << ' ' << (char)186;

    GUI.moveTo(leftBorder, topBorder + 2);
    cout << (char)200;

    for (int i = 0; i < 17; i++)
    {
        cout << (char)205;
    }
    cout << (char)188;
    GUI.write(x + 8, y + 1, to_string(value));

    if (focus)
    {
        GUI.write("_");
    }
}

void NumericBox::mousePressed(int x, int y, bool isLeft)
{
    //if plus
    if (y == top && (x > left && x < left + 3))
    {
        value++;
    }
    //if minus
    else if (y == top && (x >= (left + 13) && x <= left + 16))
    {
        if (value == 0)
        {
        }
        else
        {
            --value;
        }
    }
}

void NumericBox::keyDown(int keyCode, char charecter, Graphics &GUI)
{
    switch (keyCode)
    {
    case VK_DELETE:
        value = 0;
        break;
    case VK_LEFT:
        value++;
        break;
    case VK_NUMPAD4:
        value++;
    case VK_RIGHT:
        if (value == 0)
        {
            break;
        }
        value--;
        break;
    case VK_NUMPAD6:
        if (value == 0)
        {
            break;
        }
        value--;
        break;
    }
}

NumericBox::~NumericBox() {}