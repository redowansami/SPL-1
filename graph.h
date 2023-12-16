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
int d_cost[MAX][MAX],d_op=0,total=0;

int n_edge=0;
typedef struct mst_edges{
    int u;
    int v;
};
mst_edges edges[MAX];

void view_graph(){
    float min_x=INFINITY,min_y=INFINITY;
    //getting the min value
    for(int i=0;i<n;i++){
        if(x_cor[i]<min_x) min_x=x_cor[i];
        if(y_cor[i]<min_y) min_y=y_cor[i];
    }

    for(int i=0;i<n;i++){
        x_cor[i]=((x_cor[i]-min_x+1.2)*95);
        y_cor[i]=(y_cor[i]-min_y+1.15)*95;
    }

    for(int i=0;i<n;i++){
        float temp;
        temp=x_cor[i];
        x_cor[i]=y_cor[i];
        y_cor[i]=600-temp;
    }

    initwindow(700,700,"THE WINDOWS");

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
    line(425,295,426,303);
    line(426,303,424,310);
    line(424,310,423,314);
    line(423,314,420,315);
    line(420,315,419,310);
    line(419,310,416,307);
    line(416,307,411,307);
    line(411,307,408,305);
    line(408,305,407,307);
    line(407,307,408,311);
    line(408,311,409,315);
    line(409,315,405,316);
    line(405,316,401,313);
    line(401,313,399,310);
    line(399,310,396,307);
    line(396,307,396,314);
    line(396,314,395,319);
    line(395,319,390,322);
    line(390,322,380,321);
    line(380,321,371,320);
    line(371,320,369,322);
    line(369,322,371,325);
    line(371,325,369,330);
    line(369,330,360,332);
    line(360,332,359,336);
    line(359,336,357,341);
    line(357,341,355,347);
    line(355,347,354,353);
line(354,353,351,356);
line(351,356,347,356);
line(347,356,345,358);
line(345,358,349,360);
line(349,360,352,362);
line(352,362,350,366);
line(350,366,346,365);
line(346,365,347,371);
line(347,371,351,373);
line(351,373,352,378);
line(352,378,356,381);
line(356,381,360,388);
line(360,388,361,393);
line(361,393,363,398);
line(363,398,366,407);
line(366,407,367,418);
line(367,418,374,424);
line(374,424,377,425);
line(377,425,376,421);
line(376,421,373,416);
line(373,416,373,411);
line(373,411,374,405);
line(374,405,376,404);
line(376,404,379,405);
line(379,405,382,410);
line(382,410,383,415);
line(383,415,387,420);
line(387,420,387,426);
line(387,426,391,433);
line(391,433,394,434);
line(394,434,400,433);
line(400,433,412,428);
line(412,428,411,425);
line(411,425,413,424);
line(413,424,416,423);
line(416,423,419,420);
line(419,420,416,417);
line(416,417,415,410);
line(415,410,413,404);
line(413,404,410,401);
line(410,401,409,399);
line(409,399,412,396);
line(412,396,413,391);
line(413,391,416,386);
line(416,386,418,390);
line(418,390,423,385);
line(423,385,427,384);
line(427,384,430,378);
line(430,378,428,363);
line(428,363,426,359);
line(426,359,429,355);
line(429,355,431,356);
line(431,356,432,359);
line(432,359,436,363);
line(436,363,441,362);
line(441,362,446,355);
line(446,355,447,354);
line(447,354,449,353);
line(449,353,452,357);
line(452,357,454,360);
line(454,360,456,361);
line(456,361,456,356);
line(456,356,458,354);
line(458,354,461,356);
line(461,356,462,365);
line(462,365,466,371);
line(466,371,467,378);
line(467,378,468,382);
line(468,382,470,384);
line(470,384,471,388);
line(471,388,473,392);
line(473,392,473,396);
line(473,396,476,400);
line(476,400,476,403);
line(476,403,475,404);
line(475,404,472,405);
line(472,405,471,406);
line(471,406,473,412);
line(473,412,473,416);
line(473,416,476,419);
line(476,419,477,427);
line(477,427,476,435);
line(476,435,481,438);
line(481,438,484,439);
line(484,439,486,444);
line(486,444,488,452);
line(488,452,491,454);
line(491,454,495,467);
line(495,467,494,471);
line(494,471,493,472);
line(493,472,493,473);
line(493,473,496,476);
line(496,476,498,484);
line(498,484,499,487);
line(499,487,498,489);
line(498,489,499,492);
line(499,492,502,494);
line(502,494,501,498);
line(501,498,504,508);
line(504,508,505,513);
line(505,513,502,515);
line(502,515,500,514);
line(500,514,499,516);
line(499,516,502,523);
line(502,523,503,531);
line(503,531,506,536);
line(506,536,507,541);
line(507,541,503,545);
line(503,545,506,550);
line(506,550,506,566);
line(506,566,509,579);
line(509,579,512,589);
line(512,589,513,593);
line(513,593,516,597);
line(516,597,515,598);
line(515,598,512,600);
line(512,600,509,601);
line(509,601,508,603);
line(508,603,505,603);
line(505,603,504,600);
line(504,600,504,594);
line(504,594,501,591);
line(501,591,499,590);
line(499,590,496,591);
line(496,591,492,590);
line(492,590,489,591);
line(489,591,488,589);
line(488,589,486,584);
line(486,584,482,580);
line(482,580,479,580);
line(479,580,477,583);
line(477,583,477,586);
line(477,586,475,587);
line(475,587,473,585);
line(473,585,471,584);
line(471,584,469,587);
line(469,587,469,592);
line(469,592,468,594);
line(468,594,466,594);
line(466,594,464,596);
line(464,596,465,599);
line(465,599,467,602);
line(467,602,466,607);
line(466,607,462,610);
line(462,610,466,616);
line(466,616,472,621);
line(472,621,471,623);
line(471,623,467,621);
line(467,621,467,624);
line(467,624,472,629);
line(472,629,473,633);
line(473,633,477,639);
line(477,639,479,642);
line(479,642,481,651);
line(481,651,484,659);
line(484,659,487,670);
line(487,670,482,659);
line(482,659,475,652);
line(475,652,471,645);
line(471,645,470,642);
line(470,642,464,634);
line(464,634,459,627);
line(459,627,456,620);
line(456,620,453,613);
line(453,613,452,605);
line(452,605,446,597);
line(446,597,446,591);
line(446,591,449,584);
line(449,584,449,574);
line(449,574,446,574);
line(446,574,442,569);
line(442,569,445,561);
line(445,561,444,559);
line(444,559,439,560);
line(439,560,437,559);
line(437,559,441,554);
line(441,554,440,553);
line(440,553,438,548);
line(438,548,434,543);
line(434,543,433,536);
line(433,536,431,534);
line(431,534,428,528);
line(428,528,428,519);
line(428,519,421,516);
line(421,516,416,504);
line(416,504,411,496);
line(411,496,407,487);
line(407,487,397,476);
line(397,476,388,467);
line(388,467,387,463);
line(387,463,382,458);
line(382,458,380,460);
line(380,460,378,461);
line(378,461,374,461);
line(374,461,368,470);
line(368,470,364,472);
line(364,472,360,470);
line(360,470,358,471);
line(358,471,365,479);
line(365,479,363,486);
line(363,486,361,492);
line(361,492,364,498);
line(364,498,365,504);
line(365,504,364,511);
line(364,511,360,520);
line(360,520,354,534);
line(354,534,351,533);
line(351,533,349,536);
line(349,536,345,538);
line(345,538,340,542);
line(340,542,328,540);
line(328,540,324,540);
line(324,540,316,543);
line(316,543,311,549);
line(311,549,305,552);
line(305,552,301,553);
line(301,553,296,556);
line(296,556,292,562);
line(292,562,285,564);
line(285,564,275,559);
line(275,559,272,559);
line(272,559,267,562);
line(267,562,262,564);
line(262,564,255,565);
line(255,565,251,564);
line(251,564,252,558);
line(252,558,250,557);
line(250,557,247,560);
line(247,560,244,560);
line(244,560,244,549);
line(244,549,247,543);
line(247,543,235,549);
line(235,549,229,541);
line(229,541,225,540);
line(225,540,223,541);
line(223,541,219,538);
line(219,538,217,542);
line(217,542,220,550);
line(220,550,219,558);
line(219,558,213,560);
line(213,560,211,555);
line(211,555,209,554);
line(209,554,207,556);
line(207,556,203,550);
line(203,550,200,549);
line(200,549,195,551);
line(195,551,190,553);
line(190,553,188,556);
line(188,556,187,564);
line(187,564,186,568);
line(186,568,179,574);
line(179,574,172,575);
line(172,575,167,578);
line(167,578,162,583);
line(162,583,160,582);
line(160,582,159,575);
line(159,575,160,571);
line(160,571,157,567);
line(157,567,154,569);
line(154,569,146,559);
line(146,559,138,553);
line(138,553,135,548);
line(135,548,135,546);
line(135,546,139,543);
line(139,543,140,538);
line(140,538,139,542);
line(139,542,143,547);
line(143,547,147,551);

//the island
line(389,480,387,481);
line(387,481,386,485);
line(386,485,384,488);
line(384,488,382,491);
line(382,491,383,496);
line(383,496,386,503);
line(386,503,392,509);
line(392,509,395,510);
line(395,510,400,506);
line(400,506,398,497);
line(398,497,397,494);
line(397,494,391,488);
line(391,488,390,485);
line(390,485,389,482);
line(389,482,389,480);

    setcolor(LIGHTRED);
    setfillstyle(SOLID_FILL,LIGHTRED);

    for(int i=0;i<n;i++){
        circle(x_cor[i],y_cor[i],5);
        floodfill(x_cor[i],y_cor[i],LIGHTRED);
    }

    //DRAWLINE
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(graph[i][j]==INT_MAX) continue;
            line(x_cor[i],y_cor[i],x_cor[j],y_cor[j]);
        }
    }

    for(int i=0;i<n;i++){
        outtextxy(x_cor[i]-25,y_cor[i]+15,place[i]);
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

        setcolor(LIGHTRED);
        setfillstyle(SOLID_FILL,LIGHTRED);
    }

    setcolor(YELLOW);
    for(int i=0;path_array[i+1]>=0;i++){
        line(x_cor[path_array[i]],y_cor[path_array[i]],x_cor[path_array[i+1]],y_cor[path_array[i+1]]);
        float x=x_cor[path_array[i]],y=y_cor[path_array[i]];
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

        if(d_op==6) {
            strcat(reached," SPENT ");
            total+=d_cost[path_array[i]][path_array[i+1]];
            char t[6];
            sprintf(t,"%d",total);
            strcat(reached,t);
        }
        outtextxy(0,0+i*20,reached);
    }

    setcolor(YELLOW);
    if(n_edge>0){
        for(int i=0;i<=n_edge;i++){
            line(x_cor[edges[i].u],y_cor[edges[i].u],x_cor[edges[i].v],y_cor[edges[i].v]);
        }
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

    char f_name[50];
    printf("\nEnter the file name to load the locations: ");
    scanf("%s",f_name);
    getchar();

    FILE *fp;
    fp=fopen(f_name,"r");
    if (fp==NULL){
        printf("File doesn't exist\n");
        return;
    }

    fscanf(fp,"%d",&n);
    for(int i=0;i<n;i++){
        fscanf(fp,"%s",&place[i]);
        fscanf(fp,"%f",&x_cor[i]);
        fscanf(fp,"%f",&y_cor[i]);
    }

    printf("***MAP LOADED***\n");

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) graph[i][j]=0;
            else{
                graph[i][j]=CalcDistance(x_cor[i],y_cor[i],x_cor[j],y_cor[j]);
            }
        }
    }

    //Remove edges
    graph[get_index("RANGPUR")][get_index("SYLHET")]=INT_MAX;
    graph[get_index("RANGPUR")][get_index("MYMENSHING")]=INT_MAX;
    graph[get_index("SYLHET")][get_index("RANGPUR")]=INT_MAX;
    graph[get_index("MYMENSHING")][get_index("RANGPUR")]=INT_MAX;

    graph[get_index("CHITTAGONG")][get_index("SYLHET")]=INT_MAX;
    graph[get_index("CHITTAGONG")][get_index("MYMENSHING")]=INT_MAX;
    graph[get_index("CHITTAGONG")][get_index("RAJSHAHI")]=INT_MAX;
    graph[get_index("CHITTAGONG")][get_index("KHULNA")]=INT_MAX;
    graph[get_index("CHITTAGONG")][get_index("BARISHAL")]=INT_MAX;

    graph[get_index("SYLHET")][get_index("CHITTAGONG")]=INT_MAX;
    graph[get_index("MYMENSHING")][get_index("CHITTAGONG")]=INT_MAX;
    graph[get_index("RAJSHAHI")][get_index("CHITTAGONG")]=INT_MAX;
    graph[get_index("KHULNA")][get_index("CHITTAGONG")]=INT_MAX;
    graph[get_index("BARISHAL")][get_index("CHITTAGONG")]=INT_MAX;

    fclose(fp);
}

#endif // GRAPH_H_INCLUDED
