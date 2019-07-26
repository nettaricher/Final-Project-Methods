#include "Label.h"
#include "Panel.h"
#include "Button.h"

class MassageBox : public Control
{
public:
	MassageBox(short left, short top, string text);

	void draw(Graphics& g, int x, int y, size_t z);
	bool canGetFocus() { return TRUE; };
	void setFocus(bool focus);
	void setIsVisible(bool isVisible);
	bool getIsVisible();
	void buttonEvent();
	~MassageBox();

private:
	Label label;
	Panel panel;
	Button sendBtn;
	Button cancelBtn;
	bool isVisible = FALSE;
	bool isFocus;
};