#include <raylib.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int aR = 1, aG = 1, aB = 1;
void ColUpdate(Color*);

int main()
{
    // TAKING USER INPUT (radius & velocity)
    int nR,i;
    vector<float> R_list, A_list, VA_list;
    printf("Enter no. of arms: ");
    scanf("%d",&nR);
    printf("Enter Data for each separated by a space:\n");
    printf("Radius: ");
    float temp;
    for(i=0;i<nR;++i){
        scanf("%f",&temp);
        R_list.push_back(temp); 
    }
    printf("Angular velocity in degree/ms: ");
    for(i=0;i<nR;++i){
        scanf("%f",&temp);
        A_list.push_back(temp/6);
        VA_list.push_back(0);
    } 

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(1000, 1000, "spirograph"); 
    double pi = 3.14159265358979323846;
    int FPS = 60;
    SetTargetFPS(FPS);
    Color MyCol = {0, 0, 0, 255};
    Vector2 Spos, Epos = {accumulate(R_list.begin(),R_list.end(),500.0f),500.0f};
    ClearBackground(BLACK);
    while (!WindowShouldClose())
    {
        if(IsKeyPressed(KEY_RIGHT))
            FPS *= 2;
        if(IsKeyPressed(KEY_LEFT))
            FPS /= 2;
        SetTargetFPS(FPS);
        Spos = Epos;
        Epos = {0,0};
        for(i=0;i<nR;++i){
            Epos.x += R_list[i]*cos(VA_list[i]*pi/180);
            Epos.y += R_list[i]*sin(VA_list[i]*pi/180);
        }
        ColUpdate(&MyCol);
        Epos = {500+Epos.x,500+Epos.y};

        BeginDrawing();
        DrawLineV(Spos, Epos, MyCol);
        
        for(i=0;i<nR;++i){
            VA_list[i] += A_list[i];
            if(VA_list[i]>=360 || VA_list[i]<=-360)
                VA_list[i] = 0;
        }

        EndDrawing();
    }
}

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
