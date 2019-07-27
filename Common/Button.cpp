#include "Button.h"
#include "Control.h"

Button::Button(Border* _border, short _left, short _top, string _value) : Control(_left, _top, _border), value(_value), isClicked(FALSE)
{
	width = static_cast<int>(_value.size() + 2);
}



void Button::draw(Graphics & GUI, int x, int y, size_t z)
{
	GUI.setBackground(bgColor);
	GUI.setForeground(fgColor);
	border->draw(GUI, x, y,static_cast<int>(value.size()) + 2, 4);
	GUI.setCursorVisibility(FALSE);
	GUI.moveTo(x + 1, y + 1);
	GUI.write(value);
}

void Button::mousePressed(int posX, int posY, bool isLeft)
{
	if(isInsideBoundaries(posX,posY))
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

		for (int i = 0; i < events.size(); i++) 
		{
			events[i]->buttonEvent();
		}
	}



	
}

int Button::getWidth() 
{
	return width; 
};

void Button::setEvent(Control* c)
{
	events.push_back(c);
}

Button::~Button() {}

bool Button::isInsideBoundaries(int posX, int posY)
{
	if(posX >= left && 
	posX <= left + 8 && 
	posY >= getTop() && 
	posY<= getTop() + 1){
		return true;
	}
	return false;
}