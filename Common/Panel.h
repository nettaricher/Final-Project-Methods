#pragma once
#include "Control.h"
class Panel :public Control
{
private:
	vector<Control*> controls;
	short width;
	short height;

public:
	Panel(Border* border, short left, short top);

	void draw(Graphics& GUI, int x, int y, size_t z);
	void mousePressed(int posX, int posY, bool isLeft);
	void keyDown(int keyCode, char charecter) {};
	bool canGetFocus() { return TRUE; };
	void add(Control* control);
	bool isInsideBoundaries(int posX, int posY, Control control);
	Control* getFirstControl();
	void getAllControls(vector<Control*> *controls);

	void setWidth(short width);
	void setHeight(short hige);
	~Panel();
};
