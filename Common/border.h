#pragma once
#include "Graphics.h"

class Border
{
    public:
        Border();
        virtual void draw(Graphics& GUI , short left, short top, int width , int height);
        virtual ~Border();
};

