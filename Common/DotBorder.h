#include "Border.h"
class DotBorder :public Border
{
public:
	DotBorder();
	void draw(Graphics& GUI, short left, short top, int width, int height);
	~DotBorder();
};

