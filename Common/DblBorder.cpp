#include "DblBorder.h"
#include <iostream>

using namespace std;
DblBorder::DblBorder()
{
}

void DblBorder::draw(Graphics & GUI, short left, short top, int width, int height)
{
	short topBorder = top;
	short leftBorder = left;

	GUI.moveTo(leftBorder, topBorder);

	cout << (char)201;
	for (int i = 0; i < width - 2; i++) {
		cout << (char)205;
	}
	cout << (char)187;								
	GUI.moveTo(leftBorder, topBorder + 1);
	int tempX = topBorder + 1;
	for (int i = 0; i < height - 2; i++) {
		cout << (char)186;						
		for (int y = 0; y < width - 2; y++) {
			cout << ' ';
		}
		cout << (char)186;
		GUI.moveTo(leftBorder, tempX++);
	}
	GUI.moveTo(leftBorder, topBorder + height - 2);
	cout << (char)200;			
	GUI.moveTo(leftBorder + 1, topBorder + height - 2);
	for (int i = 0; i < width - 2; i++) {
		cout << (char)205;			
	}
	cout << (char)188;	
}

DblBorder::~DblBorder() {}