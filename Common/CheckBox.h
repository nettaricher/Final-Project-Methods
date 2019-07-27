#pragma once
#include "Control.h"

class CheckBox : public Control
{

private:
	string value;
	bool isSelected;

public:
	CheckBox(short _left, short _top, string _value);
	void draw(Graphics &g, int x, int y, size_t z);
	void mousePressed(int x, int y, bool isLeft);
	void keyDown(int keyCode, char charecter){};
	bool canGetFocus() { return TRUE; };
	void flipBgToWhite();
	void flipBgToBlack();
	bool getIsSelected();
	void setIsSelected();
	~CheckBox();
};
