#include "Border.h"

class NormalBorder :public Border
{
public:
	NormalBorder();
	void draw(Graphics& GUI, short left, short top, int width , int height);
	~NormalBorder();
};

