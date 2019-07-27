#include "Panel.h"



Panel::Panel(Border * _border, short _left, short _top) :Control(_left, _top, _border) {}

void Panel::draw(Graphics & GUI, int x, int y, size_t z)
{
	GUI.setBackground(bgColor);
	GUI.setForeground(fgColor);
	border->draw(GUI, x, y, width , height);
	for (auto control : controls) {
		control->draw(GUI,  control->getLeft(), control->getTop(), z);
	}
}

void Panel::mousePressed(int posX, int posY, bool isLeft)
{
	for (auto c : controls)
	{
		int top    = c->getTop();
		int left   = c->getLeft();
		int width  = c->getWidth();
		bool getFocus = c->canGetFocus();

			if (posX >= left &&
			 posX<= (left + width) &&
			 posY >= top &&
			 posY <= top + 1)
			{
				if(getFocus)
				{
					Control::setFocus(*c);
				}
			}
				c->mousePressed(posX, posY, isLeft);
	}
}

void Panel::add(Control * _control)
{
	controls.push_back(_control);
}

Control * Panel::getFirstControl()
	{
	if (controls.size() > 0) {
		if (controls[0]->canGetFocus()) {
			return &(*controls[0]);
		}
	}
	return NULL;
}



void Panel::getAllControls(vector<Control*>* controls)
{
	 *controls = this->controls; 
}


void Panel::setWidth(short _width)
{
	width = _width;
}

void Panel::setHeight(short _height)
{
	height = _height;
}

Panel::~Panel()
{
}
