#include <raylib.h>
#include <cmath>
#include <iostream>
using namespace std;

int aR = 1, aG = 1, aB = 1;
void ColUpdate(Color *Col)
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
int main()
{
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(1000, 1000, "SED");
    int X = 1000 / 2, Y = 1000 / 2;
    float theta = 0, x1, y1, alpha = 0, x2, y2;
    float x3, y3, beta = 0;
    int R = 275, r = 150, r3 = 50;
    double pi = 3.141519;
    SetTargetFPS(60);
    Color MyCol = {0, 0, 0, 255};
    ClearBackground(BLACK);
    while (!WindowShouldClose())
    {
        BeginDrawing();

        x1 = R * cos(theta * pi / 180);
        y1 = R * sin(theta * pi / 180);

        x2 = r * cos(alpha * pi / 180);
        y2 = r * sin(alpha * pi / 180);

        x3 = r3 * cos(beta * pi / 180);
        y3 = r3 * cos(beta * pi / 180);

        ColUpdate(&MyCol);

        DrawPixel(X + x1 + x2 + x3, Y + y1 + y2 + y3, MyCol);

        theta += 0.7;
        alpha += 1;
        beta += 2;

        if (theta >= 360)
            theta = 0;
        if (alpha >= 360)
            alpha = 0;
        if (beta >= 360)
            beta = 0;
        EndDrawing();
    }
}
