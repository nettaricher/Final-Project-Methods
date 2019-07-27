#include "RadioBox.h"
#include <iostream>

using namespace std;

RadioBox::RadioBox(short left, short top, string title) : Control(left, top), title(title), isRadioBoxSelected(FALSE)
{
}

void RadioBox::mousePressed(int posX, int posY, bool isLeft)
{
}

bool RadioBox::getIsRadioBoxSelected()
{
	return isRadioBoxSelected;
}

void RadioBox::setIsRadioBoxSelected()
{
	isRadioBoxSelected = isRadioBoxSelected == FALSE ? TRUE : FALSE;
}

void RadioBox::toWhite()
{
	bgColor = Color::White;
	fgColor = Color::Black;
}

void RadioBox::toBlack()
{
	bgColor = Color::Black;
	fgColor = Color::White;
}

void RadioBox::draw(Graphics &GUI, int posX, int posY, size_t z)
{
	GUI.moveTo(posX, posY);
	GUI.setBackground(bgColor);
	GUI.setForeground(fgColor);

	cout << '\xDA' << '\xC4' << '\xC4' << '\xBF';
	for (int i = 0; i < title.size() + 1; i++)
	{
		cout << ' ';
	}

	GUI.moveTo(posX, posY + 1);
	cout << '\xB3' << ' ' << ' ' << '\xB3' << ' ';

	GUI.moveTo(posX, posY + 2);
	cout << '\xC0' << '\xC4' << '\xC4' << '\xD9';

	for (int i = 0; i < title.size() + 1; i++)
	{
		cout << ' ';
	}

	if (isRadioBoxSelected)
	{
		GUI.write(posX + 1, posY + 1, "\xB1\xB1");
	}

	GUI.moveTo(posX + 5, posY + 1);
	GUI.write(title);
}

//Destructor
RadioBox::~RadioBox()
{
}
