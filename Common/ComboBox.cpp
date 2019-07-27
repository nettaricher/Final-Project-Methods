#include "ComboBox.h"
#include <iostream>

#define MED_BORDER 18
#define SMALL_BORDER 16

using namespace std;
ComboBox::ComboBox(Border *border, int left, int top, vector<string> options) : Control(left, top, border), listOptions(options), width(20), isComboBoxOpen(FALSE), currentOption(0)
{
	title = options[0];
}

void ComboBox::mousePressed(int posX, int posY, bool isLeft)
{
	if ((posY == top) && (posX > left && posX < (left + width - 1)))
	{
		currentOption = 0;
		isComboBoxOpen = !isComboBoxOpen;
	}
}

void ComboBox::keyDown(int keyCode, char charecter, Graphics &g)
{
	int listSize = listOptions.size();
	switch (keyCode)
	{
	case VK_DOWN:
	case VK_NUMPAD2:
		currentOption = currentOption == listSize - 1 ? 0 : ++currentOption;
		break;
	case VK_UP:
	case VK_NUMPAD8:
		currentOption = currentOption == 0 ? listSize - 1 : --currentOption;
		break;
	case VK_SPACE:
		title = listOptions[currentOption];
		isComboBoxOpen = !isComboBoxOpen;
		break;
	case VK_RETURN:
		title = listOptions[currentOption];
		isComboBoxOpen = !isComboBoxOpen;
		break;
	}
}

void ComboBox::draw(Graphics &GUI, int posX, int posY, size_t z)
{
	int listSize = listOptions.size();
	GUI.moveTo(posX, posY);
	GUI.setBackground(bgColor);
	GUI.setForeground(fgColor);

	if (!isComboBoxOpen)
	{
		cout << '\xDA';
		for (int i = 0; i < MED_BORDER; i++)
		{
			cout << '\xC4';
		}
		cout << '\xBF';
		GUI.moveTo(posX, posY + 1);
		cout << '\xB3';
		for (int i = 0; i < SMALL_BORDER; i++)
		{
			cout << ' ';
		}
		cout << '\xB3' << '\x56' << '\xB3';
		GUI.write(posX + 2, posY + 1, title);
		GUI.moveTo(posX, posY + 2);
		cout << '\xC0';
		for (int i = 0; i < MED_BORDER; i++)
		{
			cout << '\xC4';
		}
		cout << '\xD9';
	}
	else
	{
		cout << '\xDA';
		for (int i = 0; i < MED_BORDER; i++)
		{
			cout << '\xC4';
		}
		cout << '\xBF';
		GUI.moveTo(posX, posY + 1);
		cout << '\xB3';
		for (int i = 0; i < SMALL_BORDER; i++)
		{
			cout << ' ';
		}
		cout << '\xB3' << '\x56' << '\xB3';
		GUI.write(posX + 2, posY + 1, listOptions[0]);
		GUI.moveTo(posX, posY + 2);
		cout << '\xB3';
		for (int i = 0; i < MED_BORDER; i++)
		{
			cout << '\xC4';
		}
		cout << '\xB3';

		int tempY = posY + 3;

		for (int y = 0; y < listSize; y++)
		{
			GUI.setBackground(bgColor);
			GUI.setForeground(fgColor);
			if (y == currentOption)
			{
				GUI.setBackground(Color::White);
				GUI.setForeground(Color::Black);
			}
			if (y == listSize - 1)
			{
				GUI.moveTo(posX, tempY);
				cout << '\xB3';
				for (int x = 0; x < MED_BORDER; x++)
				{
					cout << ' ';
				}
				cout << '\xB3';
				GUI.write(posX + 2, tempY, listOptions[y]);
				GUI.moveTo(posX, ++tempY);
				cout << '\xC0';
				for (int x = 0; x < MED_BORDER; x++)
				{
					cout << '\xC4';
				}
				cout << '\xD9';
			}
			else
			{
				GUI.moveTo(posX, tempY);
				cout << '\xB3';
				for (int x = 0; x < MED_BORDER; x++)
				{
					cout << ' ';
				}
				cout << '\xB3';
				GUI.write(posX + 2, tempY, listOptions[y]);
				GUI.moveTo(posX, ++tempY);
				cout << '\xB3';
				for (int x = 0; x < MED_BORDER; x++)
				{
					cout << '\xC4';
				}
				cout << '\xB3';
				tempY++;
			}
		}
	}
}

ComboBox::~ComboBox()
{
}