#include "CheckBox.h"
#include <iostream>

using namespace std;

CheckBox::CheckBox(short _left, short _top, string _value) :Control(_left, _top), value(_value) , isSelected(FALSE) {}

void CheckBox::draw(Graphics & GUI, int x, int y, size_t z)
{

	GUI.moveTo(x, y);
	GUI.setBackground(bgColor);
	GUI.setForeground(fgColor);


	cout << '\xDA' << '\xC4'<< '\xC4' << '\xBF';
	for (int i = 0; i < value.size() + 1 ; i++) {
		cout << ' ';
	}

	GUI.moveTo(x, y + 1);
	cout << '\xB3' << ' ' << ' ' << '\xB3' <<' ';

	GUI.moveTo(x, y + 2);
	cout << '\xC0' << '\xC4' << '\xC4' << '\xD9';

	for (int i = 0; i < value.size() + 1; i++) {
		cout << ' ';
	}

	if (isSelected)
	{
		GUI.write(x + 1, y + 1 , "X");
	}

	GUI.moveTo(x + 5, y + 1);
	GUI.write(value);
}

//reaction to mouse press
void CheckBox::mousePressed(int x, int y, bool isLeft)
{
}

//colors current item to white
void CheckBox::flipBgToWhite()
{
	bgColor = Color::White;
	fgColor = Color::Black;
}

//colors current item to black
void CheckBox::flipBgToBlack()
{
	bgColor = Color::Black;
	fgColor = Color::White;
}

//returns true if current item is selected
bool CheckBox::getIsSelected()
{
	return isSelected;
}

//set current item as selected
void CheckBox::setIsSelected()
{
	if (!isSelected)
	{
		isSelected = TRUE;
	}
	else
	{
		isSelected = FALSE;
	}
}

//destructor
CheckBox::~CheckBox()
{
}
