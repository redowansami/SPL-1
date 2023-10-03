#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <graphics.h>
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
    char from[50],to[50];
    int x,y;

    for(int i=0;i<((n*n)-n)/2;i++){
        int num;
        fscanf(fp,"%s",from);
        fscanf(fp,"%s",to);
        x=get_index(from);
        y=get_index(to);
        fscanf(fp,"%d",&num);
        graph[x][y]=graph[y][x]=num;
    }
    fclose(fp);
}


#endif // GRAPH_H_INCLUDED
