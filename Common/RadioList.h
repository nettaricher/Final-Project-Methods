#pragma once
#include "Control.h"
#include "../Common/RadioBox.h"
class RadioList : public Control
{
private:
	int currentRadioBox;
	int selectedRadioBox;
	int lastSelected;
	bool focus;
	vector<RadioBox *> radioBoxList;

public:
	RadioList(Border *border, short _left, short _top, vector<string> radioList);
	bool canGetFocus() { return TRUE; };
	bool isListObj() { return TRUE; }
	bool getIsInLastChild();
	void draw(Graphics &GUI, int posX, int posY, size_t z);
	void mousePressed(int posX, int posY, bool isLeft);
	void keyDown(int keyCode, char charecter, Graphics &GUI);
	void onFocus(bool flag);
	~RadioList();
};
