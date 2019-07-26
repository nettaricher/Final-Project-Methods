#include "Button.h"
#include "Control.h"

Button::Button(Border *border, short left, short top, string value) : Control(left, top, border), value(value), isClicked(FALSE)
{
    width = static_cast<int>(value.size() + 2);
}

int Button::getWidth()
{
    return width;
};

void Button::draw(Graphics &GUI, int x, int y, size_t z)
{
    GUI.setBackground(bgColor);
    GUI.setForeground(fgColor);
    border->draw(GUI, x, y, static_cast<int>(value.size()) + 2, 4);
    GUI.setCursorVisibility(FALSE);
    GUI.moveTo(x + 1, y + 1);
    GUI.write(value);
}

void Button::mousePressed(int x, int y, bool isLeft)
{
    if (y == top && (x > left && x < (left + static_cast<int>(value.size()) - 1)))
    {
        if (!isClicked)
        {
            this->flipBgToWhite();
            isClicked = TRUE;
        }
        else
        {
            this->flipBgToBlack();
            isClicked = FALSE;
        }
    }

    for (int i = 0; i < events.size(); i++)
    {
        events[i]->buttonEvent();
    }
}

void Button::setEvent(Control *c)
{
    events.push_back(c);
}

Button::~Button() {}
