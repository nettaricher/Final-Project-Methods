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

void Button::draw(Graphics &g, int x, int y, size_t z)
{
    g.setBackground(bgColor);
    g.setForeground(fgColor);
    border->drawBorder(g, x, y, static_cast<int>(value.size()) + 2, 4);
    g.setCursorVisibility(FALSE);
    g.moveTo(x + 1, y + 1);
    g.write(value);
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
