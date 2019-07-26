#include "../Common/Graphics.h"
#include "../Common/EventEngine.h"
#include "../Common/Panel.h"
#include "../Common/Button.h"
#include "../Common/TextBox.h"
#include "../Common/CheckList.h"
#include <iostream>

int main(int argc, char **argv)
{
	EventEngine e;
	// Button b(new NormalBorder(), 2, 23, "button");
	Panel p(new NormalBorder(), 1, 1);
	p.setWidth(100);
	p.setHeight(30);
	TextBox textBox1(new NormalBorder(), 2, 20, 20, 4);
	TextBox textBox2(new NormalBorder(), 23, 20, 20, 4);

	p.add(&textBox1);

	Control *firstFocus;
	if (firstFocus = p.getFirstControl())
	{
		Control::setFocus(*firstFocus);
	}
	e.run(textBox1);
}