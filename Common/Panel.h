#pragma once
#include "Control.h"
class Panel :public Control
{
private:
	vector<Control*> controls;
	short width;
	short height;

public:
	Panel(Border* border, short _left, short _top);

	void draw(Graphics& GUI, int x, int y, size_t z);
	void mousePressed(int x, int y, bool isLeft);
	void keyDown(int keyCode, char charecter) {};
	bool canGetFocus() { return TRUE; };
	void add(Control* _control);
	
	Control* getFirstControl();

	void getAllControls(vector<Control*> *controls);

	void setWidth(short _width);
	void setHeight(short _hige);
	~Panel();
};

