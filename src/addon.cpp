#include <raylib.h>
#include <iostream>
#include "addon.h"
using namespace std;

int aR = 1, aG = 1, aB = 1;
void ColUpdate(Color* Col)
{
    if (aR == 1)
    {
        if (aB == -1)
        {
            if (Col->r < 255)
            {
                Col->r += aR;
                Col->b += aB;
            }
            else
            {
                aR *= -1;
                aG *= -1;
                aB *= -1;
            }
        }
        else
        {
            if (Col->r < 255)
            {
                Col->r += aR;
            }
            else
                aR *= -1;
        }
    }

    else if (aR == -1 && aG == 1)
    {
        if (Col->g < 255)
        {
            Col->g += aG;
            Col->r += aR;
        }
        else
        {
            aG *= -1;
        }
    }
    else if (aG == -1 && aB == 1)
    {
        if (Col->b < 255)
        {
            Col->b += aB;
            Col->g += aG;
        }
        else
        {
            aB *= -1;
            aR *= -1;
        }
    }
}
