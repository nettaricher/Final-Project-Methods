#include "TextBox.h"
#include <iostream>
#include <string>

using namespace std;

TextBox::TextBox() {}

TextBox::TextBox(Border *border, short left, short top, int width, int height) : Control(left, top, border), width(width), height(height), cursor(0), isFocus(FALSE), value()
{
}

void TextBox::onFocus(bool flag)
{
    isFocus = flag;
}

void TextBox::draw(Graphics &GUI, int x, int y, size_t z)
{
    if (isFocus)
    {
        this->border->draw(GUI, x, y, this->width, this->height);
        GUI.write(x + 1, y + 1, value);
        GUI.moveTo(cursor + (left + 1), top + 1);
        GUI.setCursorVisibility(TRUE);
        GUI.write("_");
    }
    else
    {
        this->border->draw(GUI, x, y, this->width, this->height);
        GUI.setCursorVisibility(FALSE);
        GUI.write(x + 1, y + 1, value);
    }
}

void TextBox::keyDown(int keyCode, char charecter, Graphics &GUI)
{
    int stringSize = static_cast<int>(value.size());
    GUI.moveTo(static_cast<int>(value.size()) + (left + 1), top + 1);
    if (charecter > 0)
    {
        if ((width - 2) > stringSize && (charecter >= 65 && charecter <= 90 || charecter >= 97 && charecter <= 122 || charecter >= 48 && charecter <= 57 || charecter == 32))
        {
            if (cursor < stringSize)
            {
                if (charecter == 32)
                {
                    value.replace(value.begin() + cursor, value.end() - (stringSize - cursor), 1, charecter);
                }
                else
                {
                    value.replace(value.begin() + cursor, value.end() - (stringSize - cursor), 1, charecter);
                    cursor++;
                }
            }
            else
            {
                value.push_back(charecter);
                cursor = static_cast<int>(value.size());
            }
        }
    }
    else
    {
        switch (keyCode)
        {
        case VK_DELETE:
            if (cursor > 0)
            {
                value.erase(value.begin() + (cursor - 1));
                --cursor;
            }
            break;
        case VK_BACK:
            if (cursor > 0)
            {
                value.erase(value.begin() + (cursor - 1));
                --cursor;
            }
        case VK_LEFT:
            if (cursor > 0)
            {
                --cursor;
            }
            break;
        case VK_NUMPAD4:
            if (cursor > 0)
            {
                --cursor;
            }
        case VK_RIGHT:
            if (cursor < stringSize)
            {
                ++cursor;
            }
            break;
        case VK_NUMPAD6:
            if (cursor < stringSize)
            {
                ++cursor;
            }
            break;
        }
    }
}

void TextBox::mousePressed(int posX, int posY, bool isLeft)
{
    int stringSize = static_cast<int>(value.size());
    if (isInsideBoundaries(posX, posY))
    {
        if (posX > stringSize)
            cursor = stringSize;
        else
            cursor = (posX - (left + 1));
    }
}

bool TextBox::isInsideBoundaries(int posX, int posY)
{
	if(posX >= left && 
	posX <= left + getWidth() && 
	posY >= getTop() && 
	posY<= getTop() + height){
		return true;
	}
	return false;
}

TextBox::~TextBox() {}
