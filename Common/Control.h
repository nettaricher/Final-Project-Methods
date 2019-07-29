#pragma once

#include "Graphics.h"
#include "NormalBorder.h"
#include "DblBorder.h"
#include "DotBorder.h"
#include <vector>

using namespace std;

class Control
{
private:

	static Control* focusCtl;

protected:
	short left;
	short top;
	int width;
	Color bgColor;
	Color fgColor;
	Border* border;

public:
	Control();
	Control(short _left, short _top);
	Control(short _left, short _top , Border* border );

	static Control* getFocus() { return focusCtl; };
	static bool setFocus(Control& control) 
	{
		if(focusCtl != NULL)
		{	
			 if(!control.isListObj())
			{
				focusCtl->onFocus(FALSE);
				focusCtl = &control;
				control.onFocus(TRUE);
				return TRUE;
			}
			 focusCtl->onFocus(FALSE);
			 focusCtl = &control;
			 control.onFocus(TRUE);
			 return TRUE;	
			 	}
		focusCtl = &control;
		control.onFocus(TRUE);	
		return TRUE;
	};
	
	virtual void setBgColor(Color _bgColor) { bgColor = _bgColor;};
	virtual void setFgColor(Color _fgColor) { fgColor = _fgColor;};
	virtual void setBorder(Border* _border) { border = _border; };
	
	virtual void draw(Graphics& GUI, int x, int y, size_t z) {};
	virtual void mousePressed(int x, int y, bool isLeft) {};
	virtual void keyDown(int keyCode, char charecter , Graphics & g) {};
	virtual short getLeft() { return this->left; };
	virtual short getTop() { return this->top; };
	virtual void onFocus(bool flag) {};
	virtual void setWidth(int width) { this->width = width; };
	virtual int getWidth() { return width; };
	virtual bool getIsInLastChild() { return TRUE; };
	virtual void getAllControls(vector<Control*> *controls) {};
	virtual bool isListObj() { return FALSE; };
	virtual bool canGetFocus() { return FALSE; };

	virtual void flipBgToWhite();
	virtual void flipBgToBlack();

	virtual void buttonEvent() {};
	~Control();
};

