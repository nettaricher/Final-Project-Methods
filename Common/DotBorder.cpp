#include "DblBorder.h"
#include "DotBorder.h"
#include <iostream>

using namespace std;
DotBorder::DotBorder()
{
}

void DotBorder::draw(Graphics & GUI, short left, short top, int width, int height)
{
	short topBorder = top;
	short leftBorder = left;

	GUI.moveTo(leftBorder, topBorder);

	cout << (char)167;
	for (int i = 0; i < width - 2; i++) {
		cout << (char)167;
	}
	cout << (char)167;								
	GUI.moveTo(leftBorder, topBorder + 1);
	int tempX = topBorder + 1;
	for (int i = 0; i < height - 2; i++) {
		cout << (char)167;									
		for (int y = 0; y < width - 2; y++) {
			cout << ' ';
		}
		cout << (char)167;										
		GUI.moveTo(leftBorder, tempX++);
	}
	GUI.moveTo(leftBorder, topBorder + height - 2);
	cout << (char)167;				
	GUI.moveTo(leftBorder + 1, topBorder + height - 2);
	for (int i = 0; i < width - 2; i++) {
		cout << (char)167;	
	}
	cout << (char)167;		
}

DotBorder::~DotBorder() {}