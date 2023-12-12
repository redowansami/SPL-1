#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <graphics.h>
#include "CalcDistance.h"
#define MAX 10
#define INFINITY 99999
int graph[MAX][MAX],n=0,point=0;
char place[MAX][50];
float x_cor[MAX],y_cor[MAX];
int path_array[MAX+1];

void view_graph(){
    float min_x=INFINITY,min_y=INFINITY;
    //getting the min value
    for(int i=0;i<n;i++){
        if(x_cor[i]<min_x) min_x=x_cor[i];
        if(y_cor[i]<min_y) min_y=y_cor[i];
    }

    for(int i=0;i<n;i++){
        x_cor[i]=((x_cor[i]-min_x+1)*100);
        y_cor[i]=(y_cor[i]-min_y+1)*100;
    }
    //for(int i=0;i<n;i++) printf("%s %f %f\n",place[i],x_cor[i],y_cor[i]);

    initwindow(700,700,"THE WINDOWS");

    for(int i=0;i<n;i++){
        float temp;
        temp=x_cor[i];
        x_cor[i]=y_cor[i];
        y_cor[i]=600-temp;
    }

//    for(int i=0;i<=700;i+=25){
//        line(i,0,i,700);
//        line(0,i,700,i);
//    }
    int p=75;
    setcolor(LIGHTGREEN);
    line(56,80,57,73);
    //continued to leftt
    line(57,73,51,72);
    line(51,72,45,90);
    line(45,90,49,94);
    line(49,94,51,90);
    line(51,90,56,91);
    line(56,91,61,91);
    line(61,91,65,101);
    line(65,101,60,100);
    line(60,100,48,109);
    line(48,109,49,116);
    line(49,116,37,120);
    line(37,120,29,129);
    line(29,129,32,137);
    line(32,137,24,147);
    line(24,147,28,152);
    line(28,152,26,159);
    line(26,159,30,162);
    line(30,162,41,158);
    line(41,158,52,167);
    line(52,167,56,172);
    line(56,172,61,173);
    line(61,173,62,178);
    line(62,178,72,186);
    line(72,186,85,192);
    line(85,192,90,189);
    line(90,189,95,190);
    line(95,190,99,185);
    line(99,185,102,190);
    line(102,190,102,198);
    line(102,198,112,207);
    line(112,207,119,206);
    line(119,206,121,209);
    line(121,209,115,211);
    line(115,211,115,218);
    line(115,218,112,221);
    line(112,221,104,216);
    line(104,216,99,220);
    line(99,220,92,219);
    line(92,219,81,219);
    line(81,219,77,221);
    line(77,221,70,218);
    line(70,218,63,218);
    line(63,218,66,225);
    line(66,225,64,235);
    line(64,235,60,244);
    line(60,244,54,248);
    line(54,248,54,253);
    line(54,253,45,253);
    line(45,253,44,248);
    line(44,248,42,246);
    line(42,246,37,245);
    line(37,245,34,251);
    line(34,251,35,256);
    line(35,256,28,265);
    line(28,265,25,272);
    line(25,272,19,279);
    line(19,279,31,289);
    line(31,289,51,301);
    line(51,301,58,302);
    line(58,302,65,304);
    line(65,304,71,305);
    line(71,305,79,310);
    line(79,310,84,309);
    line(84,309,99,315);
    line(99,315,95,329);
    line(95,329,99,336);
    line(99,336,102,341);
    line(102,341,99,343);
    line(99,343,100,348);
    line(100,348,89,353);
    line(89,353,82,354);
    line(82,354,84,358);
    line(84,358,81,363);
    line(81,363,82,371);
    line(82,371,81,376);
    line(81,376,86,379);
    line(86,379,89,379);
    line(89,379,89,382);
    line(89,382,101,391);
    line(101,391,106,389);
    line(106,389,105,394);
    line(105,394,102,395);
    line(102,395,104,402);
    line(104,402,101,408);
    line(101,408,96,409);
    line(96,409,102,414);
    line(102,414,105,415);
    line(105,415,106,417);
    line(106,417,109,415);
    line(109,415,118,416);
    line(118,416,122,417);
    line(122,417,126,416);
    line(126,416,127,419);
    line(127,419,120,423);
    line(120,423,119,426);
    line(119,426,114,428);
    line(114,428,114,431);
    line(114,431,116,435);
    line(116,435,114,438);
    line(114,438,115,443);
    line(115,443,118,450);
    line(118,450,125,453);
    line(125,453,125,458);
    line(125,458,119,464);
    line(119,464,124,468);
    line(124,468,122,473);
    line(122,473,124,481);
    line(124,481,127,489);
    line(127,489,130,493);
    line(130,493,128,496);
    line(128,496,129,505);
    line(129,505,136,517);
    line(136,517,141,523);
    line(141,523,136,526);
    line(136,526,137,533);
    line(137,533,146,545);
    line(146,545,146,550);

    //continued to right
    line(56,80,57,82);
    line(57,82,62,82);
    line(62,82,66,87);
    line(66,87,69,87);
    line(69,87,71,91);
    line(71,91,73,91);
    line(73,91,74,89);
    line(74,89,76,89);
    line(76,89,76,93);
    line(76,93,80,93);
    line(80,93,86,100);
    line(86,100,86,103);
    line(86,103,92,103);
    line(92,103,90,106);
    line(90,106,96,106);
    line(96,106,98,109);
    line(98,109,103,109);
    line(103,109,108,108);
    line(108,108,116,112);
    line(116,112,122,112);
    line(122,112,122,108);
    line(122,108,121,107);
    line(121,107,116,105);
    line(116,105,114,104);
    line(114,104,113,102);
    line(113,102,109,103);
    line(109,103,104,94);
    line(104,94,107,95);
    line(107,95,112,90);
    line(112,90,118,96);
    line(118,96,123,96);
    line(123,96,126,102);
    line(126,102,129,103);
    line(129,103,130,105);
    line(130,105,126,105);
    line(126,105,127,107);
    line(127,107,131,111);
    line(131,111,132,120);
    line(132,120,134,122);
    line(134,122,140,123);
    line(140,123,143,126);
    line(143,126,144,130);
    line(144,130,152,131);
    line(152,131,156,135);
    line(156,135,162,129);
    line(162,129,162,134);
    line(162,134,163,135);
    line(163,135,172,134);
    line(172,134,174,137);
    line(174,137,175,137);
    line(175,137,177,136);
    line(177,136,176,130);
    line(176,130,178,129);
    line(178,129,182,129);
    line(182,129,182,125);
    line(182,125,178,121);
    line(178,121,176,120);
    line(176,120,176,118);
    line(176,118,182,115);
    line(182,115,181,111);
    line(181,111,186,110);
    line(186,110,187,115);
    line(187,115,188,118);
    line(188,118,192,117);
    line(192,117,198,123);
    line(198,123,198,131);
    line(198,131,201,130);
    line(201,130,200,134);
    line(200,134,205,134);
    line(205,134,204,137);
    line(204,137,203,139);
    line(203,139,207,138);
    line(207,138,206,142);
    line(206,142,203,146);
    line(203,146,202,153);
    line(202,153,204,158);
    line(204,158,205,186);
    line(205,186,206,196);
    line(206,196,205,205);
    line(205,205,209,206);
    line(209,206,216,203);
    line(216,203,221,205);
    line(221,205,223,207);
    line(223,207,228,208);
    line(228,208,232,211);
    line(232,211,237,211);
    line(237,211,240,210);
    line(240,210,248,213);
    line(248,213,255,212);
    line(255,212,260,216);
    line(260,216,265,215);
    line(265,215,271,216);
    line(271,216,278,214);
    line(278,214,285,216);
    line(285,216,290,213);
    line(290,213,292,214);
    line(292,214,298,215);
    line(298,215,301,213);
    line(301,213,305,214);
    line(305,214,311,213);
    line(311,213,318,212);
    line(318,212,333,208);
    line(333,208,339,209);
    line(339,209,345,208);
    line(345,208,352,208);
    line(352,208,358,210);
    line(358,210,368,211);
    line(368,211,373,214);
    line(373,214,377,214);
    line(377,214,385,210);
    line(385,210,388,211);
    line(388,211,391,213);
    line(391,213,397,213);
    line(397,213,405,209);
    line(405,209,411,210);
    line(411,210,439,208);
    line(439,208,444,212);
    line(444,212,448,213);
    line(448,213,457,217);
    line(457,217,463,216);
    line(463,216,468,221);
    line(468,221,472,222);
    line(472,222,473,225);
    line(473,225,476,230);
    line(476,230,478,230);
    line(478,230,480,231);
    line(480,231,481,236);
    line(481,236,479,238);
    line(479,238,469,240);
    line(469,240,465,239);
    line(465,239,460,235);
    line(460,235,456,235);
    line(456,235,454,237);
    line(454,237,456,242);
    line(456,242,459,244);
    line(459,244,460,247);
    line(460,247,459,254);
    line(459,254,456,263);
    line(456,263,456,275);
    line(456,275,454,277);
    line(454,277,453,277);
    line(453,277,451,275);
    line(451,275,449,274);
    line(449,274,447,275);
    line(447,275,447,278);
    line(447,278,448,284);
    line(448,284,445,286);
    line(445,286,441,289);
    line(441,289,437,290);
    line(437,290,431,289);
    line(431,289,430,289);
    line(430,289,430,291);
    line(430,291,432,293);
    line(432,293,433,294);
    line(433,294,432,296);
    line(432,296,425,295);

    setcolor(LIGHTCYAN);
    setfillstyle(SOLID_FILL,LIGHTCYAN);

    //rotating co ordinates

    for(int i=0;i<n;i++){
        circle(x_cor[i],y_cor[i],5);
        floodfill(x_cor[i],y_cor[i],LIGHTCYAN);
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            line(x_cor[i],y_cor[i],x_cor[j],y_cor[j]);
        }
    }

    if(path_array[0]>=0){
        setcolor(GREEN);
        setfillstyle(SOLID_FILL,GREEN);
        char reached[50];
        strcat(reached,"STARTED FROM ");
        strcat(reached,place[path_array[0]]);
        outtextxy(250,0,reached);
        circle(x_cor[path_array[0]],y_cor[path_array[0]],5);
        floodfill(x_cor[path_array[0]],y_cor[path_array[0]],GREEN);

        setcolor(MAGENTA);
        setfillstyle(SOLID_FILL,MAGENTA);
        circle(x_cor[path_array[point-1]],y_cor[path_array[point-1]],5);
        floodfill(x_cor[path_array[point-1]],y_cor[path_array[point-1]],MAGENTA);

        setcolor(LIGHTCYAN);
        setfillstyle(SOLID_FILL,LIGHTCYAN);
    }

    for(int i=0;i<n;i++){
        outtextxy(x_cor[i]-25,y_cor[i]+15,place[i]);
    }

    setcolor(YELLOW);
    for(int i=0;path_array[i+1]>=0;i++){
        line(x_cor[path_array[i]],y_cor[path_array[i]],x_cor[path_array[i+1]],y_cor[path_array[i+1]]);

        int x=x_cor[path_array[i]],y=y_cor[path_array[i]];
        float h1=x_cor[path_array[i+1]]-x , h2=y_cor[path_array[i+1]]-y;
        h1/=10;
        h2/=10;
        for(int i=0;i<=10;x+=h1,y+=h2,i++){
            circle(x,y,3);
            delay(200);
        }
        char reached[50];
        strcpy(reached,"");
        strcat(reached,"REACHED ");
        strcat(reached,place[path_array[i+1]]);
        outtextxy(0,0+i*20,reached);
    }

    getch();
    closegraph();
}


void print_graph(){
    for(int i=0;i<n;i++){
        printf("%s\n",place[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}

int get_index(char name[]){
    for(int i=0;i<n;i++){
        if(!strcmp(name,place[i])) return i;
    }
}

void clear_path(){
    for(int i=0;i<point;i++){
        path_array[i]=-1;
    }
    point=0;
}

void graph_input(){
    //Path initialization
    for(int i=0;i<=MAX;i++){
        path_array[i]=-1;
    }
    FILE *fp;
    fp=fopen("input.txt","r");
    fscanf(fp,"%d",&n);
    for(int i=0;i<n;i++){
        fscanf(fp,"%s",&place[i]);
        fscanf(fp,"%f",&x_cor[i]);
        fscanf(fp,"%f",&y_cor[i]);
    }
    //taking manual distance
//    char from[50],to[50];
//    int x,y;
//
//    for(int i=0;i<((n*n)-n)/2;i++){
//        int num;
//        fscanf(fp,"%s",from);
//        fscanf(fp,"%s",to);
//        x=get_index(from);
//        y=get_index(to);
//        fscanf(fp,"%d",&num);
//        graph[x][y]=graph[y][x]=num;
//    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) graph[i][j]=0;
            else{
                graph[i][j]=CalcDistance(x_cor[i],y_cor[i],x_cor[j],y_cor[j]);
            }
        }
    }

    fclose(fp);
}

#endif // GRAPH_H_INCLUDED
