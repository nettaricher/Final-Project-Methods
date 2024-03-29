#pragma once
#include "Control.h"
#include "../Common/CheckBox.h"

class CheckList : public Control
{

private:
	vector<CheckBox *> checkBoxList;
	int currentCboxIndex;
	int selectedIndex;
	bool focus;

public:
	CheckList(Border *border, short _left, short _top, vector<string> _values);
	string getValue();
	bool setValue(int option, string val);
	bool setValue (int option);
	void draw(Graphics &g, int x, int y, size_t z);
	void mousePressed(int x, int y, bool isLeft);
	void keyDown(int keyCode, char charecter, Graphics &g);
	bool canGetFocus() { return TRUE; };
	bool isListObj() { return TRUE; }
	bool getIsInLastChild();
	void onFocus(bool flag);
	~CheckList();
};
