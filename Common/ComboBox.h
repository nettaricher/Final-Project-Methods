#pragma once
#include "Control.h"
class ComboBox : public Control
{
private:
	int currentOption;
	int selectedOption;
	int width;
	bool isComboBoxOpen;
	string title;
	vector<string> listOptions;

public:
	ComboBox(Border *border, int left, int top, vector<string> listOptions);
	void mousePressed(int l, int t, bool isLeft);
	void resetSelection();
	int getWidth() { return width; };
	void draw(Graphics &GUI, int x, int y, size_t z);
	void keyDown(int keyCode, char charecter, Graphics &g);
	bool canGetFocus() { return TRUE; };
	bool isListObj() { return TRUE; }
	~ComboBox();
};