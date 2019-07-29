#include "Label.h"



Label::Label(short left, short top , string value) :Control(left , top) , value(value)
{
}

void Label::setValue(string val){
	value = val;
}

string Label::getValue(){
	return value;
}

void Label::draw(Graphics & GUI, int x, int y, size_t z)
{
	GUI.moveTo(x, y);
	GUI.setBackground(bgColor);
	GUI.setForeground(fgColor);
	
	
	GUI.moveTo(x + 3, y + 1);
	GUI.write(value);
}

Label::~Label()
{
}
