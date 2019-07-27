#include "CheckBox.h"
#include <iostream>

using namespace std;

//Constructor
CheckBox::CheckBox(short _left, short _top, string _value) : Control(_left, _top), value(_value), isSelected(FALSE)
{
}

//Overloading of the father method
void CheckBox::draw(Graphics &g, int x, int y, size_t z)
{

	g.moveTo(x, y);
	g.setBackground(bgColor);
	g.setForeground(fgColor);

	cout << '\xDA' << '\xC4' << '\xC4' << '\xBF';
	for (int i = 0; i < value.size() + 1; i++)
	{
		cout << ' ';
	}

	g.moveTo(x, y + 1);
	cout << '\xB3' << ' ' << ' ' << '\xB3' << ' ';

	g.moveTo(x, y + 2);
	cout << '\xC0' << '\xC4' << '\xC4' << '\xD9';

	for (int i = 0; i < value.size() + 1; i++)
	{
		cout << ' ';
	}

	if (isSelected)
	{
		g.write(x + 1, y + 1, "X");
	}

	g.moveTo(x + 5, y + 1);
	g.write(value);
}

//reaction to mouse press
void CheckBox::mousePressed(int posX, int posY, bool isLeft)
{
	if ((posY >= top) && (posY <= top + 1) && (posX >= left) && (posX <= (left + 1)))
	{
		isSelected = !isSelected;
	}
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
