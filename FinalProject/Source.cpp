#include "../Common/Graphics.h"
#include "../Common/EventEngine.h"
#include "../Common/Button.h"
#include <iostream>

int main(int argc, char** argv)
{
	EventEngine e;
	Button b(new NormalBorder(), 2, 23, "button");
	e.run(b);
}