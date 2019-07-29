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

void CheckList::mousePressed(int posX, int posY, bool isLeft)
{
	for (auto checkBox : checkBoxList)
	{
		checkBox->mousePressed(posX, posY, isLeft);
	}
}

void CheckList::keyDown(int keyCode, char charecter, Graphics &g)
{
	int vectorSize = static_cast<int>(checkBoxList.size());

	switch (keyCode)
	{
	case VK_DOWN:
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
	case VK_UP:
	case VK_NUMPAD8:
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
		else
		{
			checkBoxList[currentCboxIndex]->flipBgToWhite();
			checkBoxList[currentCboxIndex + 1]->flipBgToBlack();
			selectedIndex = currentCboxIndex;
		}
		break;

	case VK_SPACE:
		checkBoxList[selectedIndex]->setIsSelected();
		break;
	}
}

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
	else
	{
		checkBoxList[currentCboxIndex - 1]->flipBgToBlack();
		checkBoxList[currentCboxIndex]->flipBgToWhite();
		selectedIndex = currentCboxIndex;
		return FALSE;
	}
}

void CheckList::onFocus(bool flag)
{
	focus = flag;
}

CheckList::~CheckList()
{
}
