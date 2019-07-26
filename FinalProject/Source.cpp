#include "../Common/Graphics.h"
#include "../Common/EventEngine.h"
#include "../Common/Button.h"
#include "../Common/TextBox.h"
#include <iostream>

int main(int argc, char **argv)
{
	EventEngine e;
	// Button b(new NormalBorder(), 2, 23, "button");
	TextBox textBox1(new NormalBorder(), 2, 20, 20, 4);
	// TextBox textBox2(new NormalBorder(), 23, 20, 20, 4);
	e.run(textBox1);
}