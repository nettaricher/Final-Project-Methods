#include "Label.h"
#include "Panel.h"
#include "Button.h"

class PopUp : public Control
{
public:
	PopUp(short left, short top, string text);

	void mousePressed(int x, int y, bool isLeft);
	void draw(Graphics& g, int x, int y, size_t z);
	bool canGetFocus() { return TRUE; };
	void setIsVisible(bool isVisible);
	void setFocus(bool focus);
	bool getIsVisible();
	void buttonEvent();
	~PopUp();

private:
	Label label;
	Panel panel;
	Button sendBtn;
	Button cancelBtn;
	bool isVisible;
	bool isFocus;
	int counter;
};