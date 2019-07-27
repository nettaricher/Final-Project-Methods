#include "RadioList.h"

RadioList::RadioList(Border *border, short left, short top, vector<string> radioList) : Control(left, top, border), currentRadioBox(-1), selectedRadioBox(0), lastSelected(-1)
{
	for (int i = 0; i < radioList.size(); i++)
	{
		radioBoxList.push_back(new RadioBox(left + 3, top + (1 + (i * 3)), radioList[i]));
		COORD posXY = {left + (short)4, top + (short)(2 + (i * 3))};
	}
}

void RadioList::mousePressed(int posX, int posY, bool isLeft)
{
	int currentindex = 0;
	for (auto radioBox : radioBoxList)
	{
		if (radioBox->mouseClicked(posX, posY, isLeft))
		{
			for (auto radioBox : radioBoxList)
			{
				if (radioBoxList[currentindex] != radioBox)
				{
					radioBox->flipBgToBlack();
					radioBox->setIsRadioBoxSelected(false);
				}
				else
				{
					// radioBox->flipBgToWhite();
					radioBox->setIsRadioBoxSelected(true);
				}
			}
			lastSelected = currentindex;
			break;
		}
		currentindex++;
	}
}

bool RadioList::getIsInLastChild()
{
	int size = radioBoxList.size();

	if (++currentRadioBox == 0)
	{
		selectedRadioBox = currentRadioBox;
		radioBoxList[currentRadioBox]->flipBgToWhite();
		return FALSE;
	}
	else if (currentRadioBox == size - 1)
	{
		radioBoxList[currentRadioBox]->flipBgToWhite();
		radioBoxList[currentRadioBox - 1]->flipBgToBlack();
		currentRadioBox = size - 1;
		selectedRadioBox = currentRadioBox;
		return FALSE;
	}
	else if (currentRadioBox == size)
	{
		radioBoxList[currentRadioBox - 1]->flipBgToBlack();
		currentRadioBox = -1;
		return TRUE;
	}
	else
	{
		radioBoxList[currentRadioBox - 1]->flipBgToBlack();
		radioBoxList[currentRadioBox]->flipBgToWhite();
		selectedRadioBox = currentRadioBox;
		return FALSE;
	}
}

void RadioList::draw(Graphics &GUI, int posX, int posY, size_t z)
{
	GUI.setBackground(bgColor);
	GUI.setForeground(fgColor);
	border->draw(GUI, posX, posY, 25, radioBoxList.size() * 4);
	for (auto rb : radioBoxList)
	{
		rb->draw(GUI, rb->getLeft(), rb->getTop(), z);
	}
}

void RadioList::keyDown(int keyCode, char charecter, Graphics &GUI)
{
	int size = radioBoxList.size();

	switch (keyCode)
	{
	case VK_TAB:
		if (++currentRadioBox == 0)
		{
			selectedRadioBox = currentRadioBox;
			radioBoxList[currentRadioBox]->flipBgToWhite();
		}
		else
		{
			radioBoxList[currentRadioBox - 1]->flipBgToBlack();
			radioBoxList[currentRadioBox]->flipBgToWhite();
			selectedRadioBox = currentRadioBox;
		}
		break;
	case VK_DOWN:
	case VK_NUMPAD2:
		if (++currentRadioBox == 0)
		{
			radioBoxList[currentRadioBox]->flipBgToWhite();
		}
		else if (currentRadioBox == size)
		{
			radioBoxList[currentRadioBox - 1]->flipBgToBlack();
			radioBoxList[0]->flipBgToWhite();
			currentRadioBox = 0;
		}
		else
		{
			radioBoxList[currentRadioBox - 1]->flipBgToBlack();
			radioBoxList[currentRadioBox]->flipBgToWhite();
		}
		selectedRadioBox = currentRadioBox;
		break;
	case VK_UP:
	case VK_NUMPAD8:
		if (--currentRadioBox == 0)
		{
			radioBoxList[currentRadioBox + 1]->flipBgToBlack();
			radioBoxList[currentRadioBox]->flipBgToWhite();
		}
		else if (currentRadioBox <= -1)
		{
			currentRadioBox = size - 1;
			radioBoxList[0]->flipBgToBlack();
			radioBoxList[currentRadioBox]->flipBgToWhite();
		}
		else
		{
			radioBoxList[currentRadioBox]->flipBgToWhite();
			radioBoxList[currentRadioBox + 1]->flipBgToBlack();
		}
		selectedRadioBox = currentRadioBox;
		break;
	case VK_SPACE:
		if (lastSelected == -1)
		{
			lastSelected = selectedRadioBox;
			radioBoxList[selectedRadioBox]->toggleSelected();
		}
		else
		{
			radioBoxList[lastSelected]->toggleSelected();
			radioBoxList[selectedRadioBox]->toggleSelected();
			lastSelected = selectedRadioBox;
		}
		break;
	}
}

void RadioList::onFocus(bool flag)
{
	focus = flag;
}

RadioList::~RadioList()
{
}
