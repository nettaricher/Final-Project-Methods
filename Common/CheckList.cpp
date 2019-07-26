#include "CheckList.h"
#include <iostream>
using namespace std;


//Constructor
CheckList::CheckList(Border * _border, short _left, short _top, vector<string> _values) :Control(_left, _top, _border), currentCboxIndex(-1) , selectedIndex(0)
{
	for (int i = 0; i < _values.size(); i++) {
		checkBoxs.push_back(new CheckBox(_left + 2, 1 + (i * 3), _values[i]));
		COORD pos = { _left + (short)4  , _top + (short)(2 + (i * 3)) };
		checkBoxCoord.push_back(pos);
	}
}

//Overloads the father mathod draw()
void CheckList::draw(Graphics & GUI, int x, int y, size_t z)
{
	GUI.setBackground(bgColor);
	GUI.setForeground(fgColor);
	border->draw(GUI, x, y, 25, static_cast<int>(checkBoxs.size() * 4));
	for (auto c : checkBoxs) {
		c->draw(GUI,  c->getLeft()  , y  + c->getTop(), z);
	}
}

//reaction to mouse press
void CheckList::mousePressed(int x, int y, bool isLeft)
{
}

//reaction to key down press
void CheckList::keyDown(int keyCode, char charecter , Graphics & g)
{
	int vectorSize = static_cast<int>(checkBoxs.size());
	
	switch (keyCode)
	{
		//tab was pressed
		case VK_TAB:
			// if no focused
			if (++currentCboxIndex == 0)
			{
				selectedIndex = currentCboxIndex;
				checkBoxs[currentCboxIndex]->flipBgToWhite();
			}
			// if is in last position befor out of the check list
			else if (currentCboxIndex == vectorSize -1)
			{
				checkBoxs[currentCboxIndex - 1]->flipBgToBlack();
				checkBoxs[currentCboxIndex]->flipBgToWhite();
				selectedIndex = currentCboxIndex;
			}	
			// middle
			else
			{
				checkBoxs[currentCboxIndex - 1]->flipBgToBlack();
				checkBoxs[currentCboxIndex]->flipBgToWhite();
				selectedIndex = currentCboxIndex;
			}
			break;

			//key down was pressed
		case VK_DOWN:
			// if no focused
			if (++currentCboxIndex == 1)
			{
				checkBoxs[currentCboxIndex - 1]->flipBgToBlack();
				checkBoxs[currentCboxIndex]->flipBgToWhite();
				selectedIndex = currentCboxIndex;
			}
			else if (currentCboxIndex == 0)
			{
				checkBoxs[currentCboxIndex]->flipBgToWhite();
				selectedIndex = currentCboxIndex;
			}
			// if is in last position befor out of the check list
			else if (currentCboxIndex == vectorSize)
			{
				checkBoxs[currentCboxIndex - 1]->flipBgToBlack();
				checkBoxs[0]->flipBgToWhite();
				currentCboxIndex = 0;
				selectedIndex = currentCboxIndex;
			}
			// middle
			else
			{
				checkBoxs[currentCboxIndex - 1]->flipBgToBlack();
				checkBoxs[currentCboxIndex]->flipBgToWhite();
				selectedIndex = currentCboxIndex;
			}
			break;

			//numpad2 was pressed like key down
		case VK_NUMPAD2:
			// if no focused
			if (++currentCboxIndex == 1)
			{
				checkBoxs[currentCboxIndex - 1]->flipBgToBlack();
				checkBoxs[currentCboxIndex]->flipBgToWhite();
				selectedIndex = currentCboxIndex;
			}
			else if (currentCboxIndex == 0)
			{
				checkBoxs[currentCboxIndex]->flipBgToWhite();
				selectedIndex = currentCboxIndex;
			}
			// if is in last position befor out of the check list
			else if (currentCboxIndex == vectorSize)
			{
				checkBoxs[currentCboxIndex - 1]->flipBgToBlack();
				checkBoxs[0]->flipBgToWhite();
				currentCboxIndex = 0;
				selectedIndex = currentCboxIndex;
			}
			// middle
			else
			{
				checkBoxs[currentCboxIndex - 1]->flipBgToBlack();
				checkBoxs[currentCboxIndex]->flipBgToWhite();
				selectedIndex = currentCboxIndex;
			}
			break;

			//key up was pressed
		case VK_UP:
			// if no focused
			if (--currentCboxIndex == 0)
			{
				checkBoxs[currentCboxIndex + 1]->flipBgToBlack();
				checkBoxs[currentCboxIndex]->flipBgToWhite();
				selectedIndex = currentCboxIndex;
			}
			else if (currentCboxIndex <= -1)
			{
				currentCboxIndex = vectorSize - 1;
				checkBoxs[0]->flipBgToBlack();
				checkBoxs[currentCboxIndex]->flipBgToWhite();
				selectedIndex = currentCboxIndex;
			}
			// if is in last position befor out of the check list
			// middle
			else
			{
				checkBoxs[currentCboxIndex]->flipBgToWhite();
				checkBoxs[currentCboxIndex + 1]->flipBgToBlack();	
				selectedIndex = currentCboxIndex;
			}
			break;

			//numpad 8 was pressed like key up
		case VK_NUMPAD8:
			// if no focused
			if (--currentCboxIndex == 0)
			{
				checkBoxs[currentCboxIndex + 1]->flipBgToBlack();
				checkBoxs[currentCboxIndex]->flipBgToWhite();
				selectedIndex = currentCboxIndex;
			}
			else if (currentCboxIndex <= -1)
			{
				currentCboxIndex = vectorSize - 1;
				checkBoxs[0]->flipBgToBlack();
				checkBoxs[currentCboxIndex]->flipBgToWhite();
				selectedIndex = currentCboxIndex;
			}
			// if is in last position befor out of the check list
			// middle
			else
			{
				checkBoxs[currentCboxIndex]->flipBgToWhite();
				checkBoxs[currentCboxIndex + 1]->flipBgToBlack();
				selectedIndex = currentCboxIndex;
			}
			break;

			//space button was pressed to select current item and check it
		case VK_SPACE:

			checkBoxs[selectedIndex]->setIsSelected();
			break;

	}
}

//return true if the checklist focus is on last child
bool CheckList::getIsInLastChild()
{	
	int vectorSize = static_cast<int>(checkBoxs.size());
	// if no focused
	if (++currentCboxIndex == 0)
	{
		selectedIndex = currentCboxIndex;
		checkBoxs[currentCboxIndex]->flipBgToWhite();
		return FALSE;
	}
	// if is in last position befor out of the check list
	else if (currentCboxIndex == vectorSize - 1)
	{
		checkBoxs[currentCboxIndex]->flipBgToWhite();
		checkBoxs[currentCboxIndex - 1]->flipBgToBlack();
		currentCboxIndex = vectorSize - 1;
		selectedIndex = currentCboxIndex;
		return FALSE;
	}
	else if (currentCboxIndex == vectorSize )
	{
		checkBoxs[vectorSize - 1]->flipBgToBlack();
		currentCboxIndex = - 1;
		return TRUE;
	}
	// middle
	else
	{
		checkBoxs[currentCboxIndex - 1]->flipBgToBlack();
		checkBoxs[currentCboxIndex]->flipBgToWhite();
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
