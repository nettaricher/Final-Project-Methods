#include "../Common/Graphics.h"
#include "../Common/EventEngine.h"
#include "../Common/Panel.h"

#include "../Common/Button.h"
#include "../Common/CheckList.h"
#include <iostream>

int main(int argc, char** argv)
{
	EventEngine e;
	CheckList cl(new DblBorder(), 2, 2, { "check Box 1" , "check Box 2"  , "check Box 3" ,  "check Box 4" });
	Panel p(new NormalBorder(), 1, 1);
	p.setWidth(100);
	p.setHeight(30);
	
	p.add(&cl);
	
	Control* firstFocus;
	if (firstFocus = p.getFirstControl())
	{
		Control::setFocus(*firstFocus);
	}
	e.run(p);
}