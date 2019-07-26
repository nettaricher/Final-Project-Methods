#include "Label.h"
#include "Panel.h"
#include "Button.h"

class PopUp : public Control
{
public:
	PopUp(short left, short top, string text);

	void draw(Graphics& g, int x, int y, size_t z);
	bool canGetFocus() { return TRUE; };
	void setFocus(bool focus);
	void setIsVisible(bool isVisible);
	bool getIsVisible();
	void buttonEvent();
	void mousePressed(int x, int y, bool isLeft);
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