#include <raylib.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <numeric>
#include "addon.h"

using namespace std;

int main()
{
	int RESOLUTION;
	printf("Resolution: ");
	scanf("%d",&RESOLUTION);

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

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(RESOLUTION, RESOLUTION, "raylib"); 
    double pi = 3.14159265358979323846;
    int FPS = 60;
    SetTargetFPS(FPS);
    Color MyCol = {0, 0, 0, 255};
	Vector2 Spos, Epos = {
		accumulate(R_list.begin(),R_list.end(),(float)RESOLUTION/2),
		(float)RESOLUTION/2
	};
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
        ColUpdate(MyCol);
        Epos = {(RESOLUTION/2)+Epos.x,(RESOLUTION/2)+Epos.y};

        BeginDrawing();
        /* DrawLineV(Spos, Epos, MyCol); */
        DrawLineEx(Spos, Epos, 3, MyCol);
        
        for(i=0;i<nR;++i){
            VA_list[i] += A_list[i];
            if(VA_list[i]>=360 || VA_list[i]<=-360)
                VA_list[i] = 0;
        }

        EndDrawing();
    }
}
