#include <iostream>
#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#define MAX 10
#define INFINITY 9999
using namespace std;

int n=0,point=0;
char place[MAX][50];
float x_cor[10],y_cor[10];
float graph[10][10];
int path_array[MAX];

void graph_in_val(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) graph[i][j]=0.0;
            else{
                float dis = ((x_cor[i]-x_cor[j])*(x_cor[i]-x_cor[j]))+((y_cor[i]-y_cor[j])*(y_cor[i]-y_cor[j]));
                graph[i][j]=sqrt(dis)*100;
            }
        }
    }
}

void view_graph(){

    float min_x=99999,min_y=99999;
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
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,WHITE);

    //rotating co ordinates
    for(int i=0;i<n;i++){
        float temp;
        temp=x_cor[i];
        x_cor[i]=y_cor[i];
        y_cor[i]=600-temp;
    }

    for(int i=0;i<n;i++){
        circle(x_cor[i],y_cor[i],10);
        floodfill(x_cor[i],y_cor[i],WHITE);
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            line(x_cor[i],y_cor[i],x_cor[j],y_cor[j]);
        }
    }

    for(int i=0;i<n;i++){
        outtextxy(x_cor[i]-25,y_cor[i]+15,place[i]);
    }

    setcolor(YELLOW);
    for(int i=0;path_array[i+1];i++){
        line(x_cor[path_array[i]],y_cor[path_array[i]],x_cor[path_array[i+1]],y_cor[path_array[i+1]]);

        int x=x_cor[path_array[i]],y=y_cor[path_array[i]];
        float h1=x_cor[path_array[i+1]]-x , h2=y_cor[path_array[i+1]]-y;
        h1/=20;
        h2/=20;
        for(int i=0;i<=20;x+=h1,y+=h2,i++){
            circle(x,y,5);
            delay(50);
        }
    }
    getch();
    closegraph();
}

void graph_input(){
    FILE *fp;
    fp=fopen("input.txt","r");
    fscanf(fp,"%d",&n);
    for(int i=0;i<n;i++){
        fscanf(fp,"%s",&place[i]);
        fscanf(fp,"%f",&x_cor[i]);
        fscanf(fp,"%f",&y_cor[i]);
    }

    fclose(fp);
    graph_in_val();
}

int get_index(char name[]){
    for(int i=0;i<n;i++){
        if(!strcmp(name,place[i])) return i;
    }
}
/*
void print_path(int start,int end,int prev[],int flag){
    if(flag){
        printf("%s ->",place[start]);
    }
    if(prev[end]==start){
        printf("%s ->",place[end]);
    }
    if(prev[end]!=start){
        print_path(start,prev[end],prev,0);
    }
}
*/

void print_path(int start,int end,int prev[],int flag){
    if(flag){
        printf("%s ->",place[start]);
        path_array[point]=start;
        point++;
    }
    if(prev[end]==start){
        printf("%s ->",place[end]);
        path_array[point]=end;
        point++;
    }
    if(prev[end]!=start){
        print_path(start,prev[end],prev,0);
        printf("%s ->",place[end]);
        path_array[point]=end;
        point++;
    }
}

void Dijkstra(int start,int end){
    int cost[MAX][MAX],dis[MAX],prev[MAX];
    int visited[MAX],count=0,min,next;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            if(graph[i][j]==0)
                cost[i][j]=INFINITY;

            else cost[i][j]=graph[i][j];
        }
    }

    for(int i=0;i<n;i++){
        dis[i]=cost[start][i];
        prev[i]=start;
        visited[i]=0;
    }

    dis[start]=0;
    visited[start]=1;
    count++;

    while(count<n-1){
        min=INFINITY;

        for(int i=0;i<n;i++){
            if(dis[i]<min && visited[i]==0){
                min=dis[i];
                next=i;
            }
        }

        visited[next]=1;

        for(int i=0;i<n;i++){
            if(visited[i]==0){
                if(min+cost[next][i]<dis[i]){
                    dis[i]=min+cost[next][i];
                    prev[i]=next;
                }
            }
        }

        count++;
    }
/*
    for(int i=0;i<n;i++){
        printf("MIN Distance from %d to %d is %d\n",start,i,dis[i]);
        printf("Previous node is %d\n",prev[i]);
    }
*/
    printf("Min distance from %s to %s is %d\n",place[start],place[end],dis[end]);

    print_path(start,end,prev,1);
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

void menu(){
    int op=0;
    for(;op!=5;){
    printf("\n===Welcome===\n");
    printf("1. Load Map\n");
    printf("2. View the Locations\n");
    printf("3. View the Graph\n");
    printf("4. View the Shortest Path\n");
    printf("5. Exit\n");
    printf("Select Your Option: ");
    scanf("%d",&op);
    if(op==1){
        printf("\n***Map LOADED***");
        graph_input();
    }
    else if(op==2){
        for(int i=0;i<n;i++){
        printf("%d. %s\n",i,place[i]);
    }
    }
    else if(op==3){
        view_graph();
    }

    else if(op==4){
        char start[50],end[50];
        printf("Enter the Starting Location-");
        scanf("%s",start);
        getchar();
        printf("Enter the Stopping Location-");
        scanf("%s",end);
        getchar();
        Dijkstra(get_index(start),get_index(end));
    }
    else if(op==5){
        break;
    }
    }
}

int main(){
    menu();
    return 0;
}
