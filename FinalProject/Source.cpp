#include "../Common/Graphics.h"
#include "../Common/EventEngine.h"
#include "../Common/Panel.h"
#include "../Common/Button.h"
#include "../Common/TextBox.h"
#include "../Common/CheckList.h"
#include "../Common/NumericBox.h"
#include "../Common/MassageBox.h"

#include <iostream>

int main(int argc, char **argv)
{
	EventEngine engine;
	Panel panel(new NormalBorder(), 1, 1);
	panel.setWidth(100);
	panel.setHeight(30);

	Label label(30,15,"Todo List");
	Button btn1(new DblBorder(), 2, 23, "OPEN POPUP");
	Button btn2(new DblBorder(), 40, 18, "CLICK ME!");
	TextBox textBox1(new NormalBorder(), 2, 20, 20, 4);
	NumericBox numbox(new DotBorder(), 2, 17);
	CheckList checklist(new NormalBorder(), 2, 2, {"Workout", "Hangout", "Do Homework"});
	PopUp popup(35, 10, "Pop up!");

	panel.add(&label);
	panel.add(&btn1);
	panel.add(&btn2);
	panel.add(&textBox1);
	panel.add(&numbox);
	panel.add(&checklist);
	panel.add(&popup);
	btn1.setEvent(&popup);


	Control *firstFocus;
	if (firstFocus = panel.getFirstControl())
	{
		Control::setFocus(*firstFocus);
	}
	engine.run(panel);
}