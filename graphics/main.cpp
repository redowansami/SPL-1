#include <iostream>
#include <graphics.h>
using namespace std;

int main(){
    int ran_x=100,ran_y=100,raj_x=75,raj_y=200,khul_x=150,khul_y=350,bar_x=250,bar_y=300,
    dha_x=200,dha_y=200,mym_x=250,mym_y=100,chit_x=350,chit_y=400,syl_x=350,syl_y=120;

    initwindow(500,500,"THE WINDOWS");
    setcolor(BLUE);
    setfillstyle(SOLID_FILL,BLUE);
    //0
    circle(ran_x,ran_y,15);
    floodfill(ran_x,ran_y,BLUE);
    //1
    circle(raj_x,raj_y,15);
    floodfill(raj_x,raj_y,BLUE);
    //2
    circle(khul_x,khul_y,15);
    floodfill(khul_x,khul_y,BLUE);
    //3
    circle(bar_x,bar_y,15);
    floodfill(bar_x,bar_y,BLUE);

    circle(dha_x,dha_y,15);
    floodfill(dha_x,dha_y,BLUE);

    circle(mym_x,mym_y,15);
    floodfill(mym_x,mym_y,BLUE);

    circle(syl_x,syl_y,15);
    floodfill(syl_x,syl_y,BLUE);

    circle(chit_x,chit_y,15);
    floodfill(chit_x,chit_y,BLUE);
    setcolor(RED);
    line(dha_x,dha_y,syl_x,syl_y);
    getch();
    closegraph();
    return 0;
}
