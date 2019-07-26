#include "NormalBorder.h"
#include <iostream>

using namespace std;
NormalBorder::NormalBorder()
{
}

void NormalBorder::draw(Graphics & GUI, short left, short top, int width, int height)
{
	short topBorder = top;
	short leftBorder = left;

	GUI.moveTo(leftBorder, topBorder);
	
	cout << (char)218; 
	for (int i = 0; i < width - 2; i++) {
		cout << (char)196;
	}
	cout << (char)191;
	GUI.moveTo(leftBorder, topBorder + 1); 
	int tempX = topBorder + 1;
	for (int i = 0; i < height - 2; i++) {
		cout << (char)179;
		for (int y = 0; y < width - 2; y++) {
			cout << ' ';
		}
		cout << (char)179;
		GUI.moveTo(leftBorder, tempX++ );
	}
	GUI.moveTo(leftBorder, topBorder + height -2 );
	cout << (char)192;
	GUI.moveTo(leftBorder + 1, topBorder + height - 2);
	for (int i = 0; i < width - 2; i++) {
		cout << (char)196;
	}
	cout << (char)217;
}

NormalBorder::~NormalBorder()
{
}
