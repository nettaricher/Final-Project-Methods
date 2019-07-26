#include "../Common/Graphics.h"
#include "../Common/EventEngine.h"
#include "../Common/Button.h"
#include "../Common/CheckList.h"
#include <iostream>

int main(int argc, char** argv)
{
	EventEngine e;
	CheckList cl(new DblBorder(), 2, 2, { "check Box 1" , "check Box 2"  , "check Box 3" ,  "check Box 4" });
	e.run(cl);
}