#include "MassageBox.h"
#define BTN_WIDTH 4
#define MED_PADDING 8
#define BIG_PADDING 16
#define POPUP_WIDTH 30
#define POPUP_HEIGHT 10

PopUp::PopUp(short left, short top, string text) :
	Control(left, top), 
	label(left + MED_PADDING, top, text), 
	panel(new DblBorder(), left, top), 
	sendBtn(new NormalBorder(), left + BTN_WIDTH, top + BTN_WIDTH, "SEND"), 
	cancelBtn(new NormalBorder(), left + BIG_PADDING, top + BTN_WIDTH, "CANCEL"),
	isFocus(FALSE), isVisible(false)
{
	panel.setFocus(panel);
	cancelBtn.setEvent(this);
	sendBtn.setEvent(this);
	panel.setWidth(POPUP_WIDTH);
	panel.setHeight(POPUP_HEIGHT);
	panel.add(&label);
	panel.add(&sendBtn);
	panel.add(&cancelBtn);
}

void PopUp::mousePressed(int posX, int posY, bool isLeft)
{
	if( isVisible
	&& (posX >= left) 
	&& (posX <= (left + POPUP_WIDTH)) 
	&& (posY >= top) 
	&& (posY<= (top + POPUP_HEIGHT)) ){
				panel.mousePressed(posX, posY, isLeft);
	}
}

void PopUp::setFocus(bool focus)
{
	isFocus = focus;
}

void PopUp::setIsVisible(bool _isVisible)
{
	isVisible = _isVisible;
}

bool PopUp::getIsVisible()
{
	return isVisible;
}

void PopUp::draw(Graphics& GUI, int x, int y, size_t z)
{
	if (isVisible) {
		panel.draw(GUI, x, y, z);
	}
}


void PopUp::buttonEvent() 
{
	isVisible = !isVisible;
}

PopUp::~PopUp()
{

}