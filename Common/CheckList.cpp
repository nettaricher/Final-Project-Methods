#include "CheckList.h"
#include <iostream>
using namespace std;

//Constructor
CheckList::CheckList(Border *_border, short _left, short _top, vector<string> _values) : Control(_left, _top, _border), currentCboxIndex(-1), selectedIndex(0)
{
	for (int i = 0; i < _values.size(); i++)
	{
		checkBoxList.push_back(new CheckBox(_left + 2, top + (1 + (i * 3)), _values[i]));
	}
}

//Overloads the father mathod draw()
void CheckList::draw(Graphics &g, int x, int y, size_t z)
{
	g.setBackground(bgColor);
	g.setForeground(fgColor);
	border->draw(g, x, y, 25, static_cast<int>(checkBoxList.size() * 4));
	for (auto c : checkBoxList)
	{
		c->draw(g, c->getLeft(), c->getTop(), z);
	}
}

//reaction to mouse press
void CheckList::mousePressed(int posX, int posY, bool isLeft)
{
	for (auto checkBox : checkBoxList)
	{
		checkBox->mousePressed(posX, posY, isLeft);
	}
}

//reaction to key down press
void CheckList::keyDown(int keyCode, char charecter, Graphics &g)
{
	int vectorSize = static_cast<int>(checkBoxList.size());

	switch (keyCode)
	{
	//tab was pressed
	case VK_TAB:
		// if no focused
		if (++currentCboxIndex == 0)
		{
			selectedIndex = currentCboxIndex;
			checkBoxList[currentCboxIndex]->flipBgToWhite();
		}
		// if is in last position befor out of the check list
		else if (currentCboxIndex == vectorSize - 1)
		{
			checkBoxList[currentCboxIndex - 1]->flipBgToBlack();
			checkBoxList[currentCboxIndex]->flipBgToWhite();
			selectedIndex = currentCboxIndex;
		}
		// middle
		else
		{
			checkBoxList[currentCboxIndex - 1]->flipBgToBlack();
			checkBoxList[currentCboxIndex]->flipBgToWhite();
			selectedIndex = currentCboxIndex;
		}
		break;

		//key down was pressed
	case VK_DOWN:
		// if no focused
		if (++currentCboxIndex == 1)
		{
			checkBoxList[currentCboxIndex - 1]->flipBgToBlack();
			checkBoxList[currentCboxIndex]->flipBgToWhite();
			selectedIndex = currentCboxIndex;
		}
		else if (currentCboxIndex == 0)
		{
			checkBoxList[currentCboxIndex]->flipBgToWhite();
			selectedIndex = currentCboxIndex;
		}
		// if is in last position befor out of the check list
		else if (currentCboxIndex == vectorSize)
		{
			checkBoxList[currentCboxIndex - 1]->flipBgToBlack();
			checkBoxList[0]->flipBgToWhite();
			currentCboxIndex = 0;
			selectedIndex = currentCboxIndex;
		}
		// middle
		else
		{
			checkBoxList[currentCboxIndex - 1]->flipBgToBlack();
			checkBoxList[currentCboxIndex]->flipBgToWhite();
			selectedIndex = currentCboxIndex;
		}
		break;

		//numpad2 was pressed like key down
	case VK_NUMPAD2:
		// if no focused
		if (++currentCboxIndex == 1)
		{
			checkBoxList[currentCboxIndex - 1]->flipBgToBlack();
			checkBoxList[currentCboxIndex]->flipBgToWhite();
			selectedIndex = currentCboxIndex;
		}
		else if (currentCboxIndex == 0)
		{
			checkBoxList[currentCboxIndex]->flipBgToWhite();
			selectedIndex = currentCboxIndex;
		}
		// if is in last position befor out of the check list
		else if (currentCboxIndex == vectorSize)
		{
			checkBoxList[currentCboxIndex - 1]->flipBgToBlack();
			checkBoxList[0]->flipBgToWhite();
			currentCboxIndex = 0;
			selectedIndex = currentCboxIndex;
		}
		// middle
		else
		{
			checkBoxList[currentCboxIndex - 1]->flipBgToBlack();
			checkBoxList[currentCboxIndex]->flipBgToWhite();
			selectedIndex = currentCboxIndex;
		}
		break;

		//key up was pressed
	case VK_UP:
		// if no focused
		if (--currentCboxIndex == 0)
		{
			checkBoxList[currentCboxIndex + 1]->flipBgToBlack();
			checkBoxList[currentCboxIndex]->flipBgToWhite();
			selectedIndex = currentCboxIndex;
		}
		else if (currentCboxIndex <= -1)
		{
			currentCboxIndex = vectorSize - 1;
			checkBoxList[0]->flipBgToBlack();
			checkBoxList[currentCboxIndex]->flipBgToWhite();
			selectedIndex = currentCboxIndex;
		}
		// if is in last position befor out of the check list
		// middle
		else
		{
			checkBoxList[currentCboxIndex]->flipBgToWhite();
			checkBoxList[currentCboxIndex + 1]->flipBgToBlack();
			selectedIndex = currentCboxIndex;
		}
		break;

		//numpad 8 was pressed like key up
	case VK_NUMPAD8:
		// if no focused
		if (--currentCboxIndex == 0)
		{
			checkBoxList[currentCboxIndex + 1]->flipBgToBlack();
			checkBoxList[currentCboxIndex]->flipBgToWhite();
			selectedIndex = currentCboxIndex;
		}
		else if (currentCboxIndex <= -1)
		{
			currentCboxIndex = vectorSize - 1;
			checkBoxList[0]->flipBgToBlack();
			checkBoxList[currentCboxIndex]->flipBgToWhite();
			selectedIndex = currentCboxIndex;
		}
		// if is in last position befor out of the check list
		// middle
		else
		{
			checkBoxList[currentCboxIndex]->flipBgToWhite();
			checkBoxList[currentCboxIndex + 1]->flipBgToBlack();
			selectedIndex = currentCboxIndex;
		}
		break;

		//space button was pressed to select current item and check it
	case VK_SPACE:

		checkBoxList[selectedIndex]->setIsSelected();
		break;
	}
}

//return true if the checklist focus is on last child
bool CheckList::getIsInLastChild()
{
	int vectorSize = static_cast<int>(checkBoxList.size());
	// if no focused
	if (++currentCboxIndex == 0)
	{
		selectedIndex = currentCboxIndex;
		checkBoxList[currentCboxIndex]->flipBgToWhite();
		return FALSE;
	}
	// if is in last position befor out of the check list
	else if (currentCboxIndex == vectorSize - 1)
	{
		checkBoxList[currentCboxIndex]->flipBgToWhite();
		checkBoxList[currentCboxIndex - 1]->flipBgToBlack();
		currentCboxIndex = vectorSize - 1;
		selectedIndex = currentCboxIndex;
		return FALSE;
	}
	else if (currentCboxIndex == vectorSize)
	{
		checkBoxList[vectorSize - 1]->flipBgToBlack();
		currentCboxIndex = -1;
		return TRUE;
	}
	// middle
	else
	{
		checkBoxList[currentCboxIndex - 1]->flipBgToBlack();
		checkBoxList[currentCboxIndex]->flipBgToWhite();
		selectedIndex = currentCboxIndex;
		return FALSE;
	}
}

//set focus method
void CheckList::onFocus(bool flag)
{
	focus = flag;
}

//Destructor
CheckList::~CheckList()
{
}
