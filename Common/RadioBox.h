#pragma once
#include "Control.h"
class RadioBox : public Control
{
private:
	bool isRadioBoxSelected;
	string title;

public:
	RadioBox(short left, short top, string title);
	string getValue();
	void setValue(string val);
	void draw(Graphics &GUI, int posX, int posY, size_t z);
	void keyDown(int keyCode, char charecter);
	void toWhite();
	void toBlack();
	void toggleSelected();
	void setIsRadioBoxSelected(bool isSelected);
	bool getIsRadioBoxSelected();
	bool mouseClicked(int posX, int posY, bool isLeft);
	bool canGetFocus() { return TRUE; };
	bool isListObj() { return TRUE; };
	~RadioBox();
};
