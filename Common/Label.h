#pragma once
#include "Control.h"

class Label : public Control
{
private:
	string value;

public:
	Label(short left ,short top , string value);
	void draw(Graphics& GUI, int x, int y, size_t z);
	string getValue();
	void setValue(string value);
	~Label();
};
