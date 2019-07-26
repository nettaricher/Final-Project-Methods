#include "../Common/Graphics.h"
#include "../Common/EventEngine.h"
#include "../Common/Panel.h"
#include "../Common/Button.h"
#include "../Common/TextBox.h"
#include "../Common/CheckList.h"
#include "../Common/NumericBox.h"
#include <iostream>

int main(int argc, char **argv)
{
	EventEngine e;
	Panel p(new NormalBorder(), 1, 1);
	p.setWidth(100);
	p.setHeight(30);

	NumericBox nb1(new DotBorder(), 2, 17);
	TextBox textBox1(new NormalBorder(), 2, 20, 20, 4);
	Button b1(new DblBorder(), 2, 23, "Click me");
	CheckList cl(new NormalBorder(), 2, 2, {"check Box 1", "check Box 2", "check Box 3", "check Box 4"});

	p.add(&nb1);
	p.add(&cl);
	p.add(&textBox1);
	p.add(&b1);

	Control *firstFocus;
	if (firstFocus = p.getFirstControl())
	{
		Control::setFocus(*firstFocus);
	}
	e.run(p);
}