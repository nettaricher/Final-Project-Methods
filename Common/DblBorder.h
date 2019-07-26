#pragma once

#include "Border.h"

class DblBorder :public Border
{
public:
	DblBorder();
	void draw(Graphics& GUI, short left, short top, int width, int height);
	~DblBorder();
};

