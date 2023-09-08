/*

*/
#include <iostream>
#include <graphics.h>
#include <stdio.h>
#include <string.h>
#define MAX 10
#define INFINITY 99999
using namespace std;

int n=0,graph[MAX][MAX],point=0;
char place[MAX][50];
float x_cor[MAX],y_cor[MAX];
int path_array[MAX+1];

int visited_ALL;
int dp[MAX][1<<MAX],parent[MAX][1<<MAX];

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
        circle(x_cor[i],y_cor[i],10);
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
        circle(x_cor[path_array[0]],y_cor[path_array[0]],10);
        floodfill(x_cor[path_array[0]],y_cor[path_array[0]],GREEN);

        setcolor(MAGENTA);
        setfillstyle(SOLID_FILL,MAGENTA);
        circle(x_cor[path_array[point-1]],y_cor[path_array[point-1]],10);
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
            circle(x,y,5);
            delay(50);
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

int get_index(char name[]){
    for(int i=0;i<n;i++){
        if(!strcmp(name,place[i])) return i;
    }
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

void clear_path(){
    for(int i=0;i<point;i++){
        path_array[i]=-1;
    }
    point=0;
}

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

void tsp_initials(){
    visited_ALL = (1<<n)-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<(1<<MAX);j++){
            dp[i][j]=-1;
        }
    }
}

int tsp(int mask, int pos,int start){

    if(mask==visited_ALL){
        return graph[pos][start];
    }
    if(dp[pos][mask]!=-1){
        return dp[pos][mask];
    }

    int dis=9999;
    int next_c=-1;
    for(int c=0;c<n;c++){
        if((mask & (1<<c))==0){
            int new_dis=graph[pos][c]+tsp(mask|(1<<c),c,start);
            if(new_dis < dis){
                dis=new_dis;
                next_c=c;
            }
        }
    }
    dp[pos][mask]=dis;
    parent[pos][mask]=next_c;
    return dis;
}

void print_tsp_path(int mask,int pos,int start,int flag){
    if(flag){
        path_array[point]=start;
        point++;
    }
    if(mask==visited_ALL){
        if (pos != start) {
            path_array[point] = start;
            point++;
        }
        return;
    }
    int next=parent[pos][mask];
    path_array[point]=next;
    point++;
    print_tsp_path(mask|(1<<next),next,start,0);
}

void menu(){
    int op=0;
    for(;op!=6;){
    printf("\n");
    printf(" _______________________________________\n");
    printf("|               ===MENU===              |\n");
    printf("| 1. Load Map                           |\n");
    printf("| 2. View the Locations                 |\n");
    printf("| 3. View the Graph                     |\n");
    printf("| 4. View the Shortest Path             |\n");
    printf("| 5. View the route with min distance   |\n");
    printf("| 6. Exit                               |\n");
    printf("|_______________________________________|\n");
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
        char choose;
        printf("Enter the Starting Location-");
        scanf("%s",start);
        getchar();
        printf("Enter the Stopping Location-");
        scanf("%s",end);
        getchar();
        Dijkstra(get_index(start),get_index(end));
        printf("Show the graph?(Y/N) :");
        scanf("%c",&choose);
        if(choose=='Y'){
             view_graph();
             clear_path();
        }
        else if(choose=='N') clear_path();
    }
    else if(op==5){
        tsp_initials();
        char s_loc[50];
        char choose;
        printf("Enter the starting location: ");
        scanf("%s",s_loc);
        getchar();
        //CHAGING THE MASK
        int x=get_index(s_loc);
        printf("Minimum distance is %d\n",tsp(1<<x,x,x));
        print_tsp_path(1<<x,x,x,1);
        printf("\n");
        for(int i=0;i<point;i++){
            printf("%s->",place[path_array[i]]);
        }
        printf("\n");
        printf("Show the graph?(Y/N) :");
        scanf("%c",&choose);
        if(choose=='Y'){
             view_graph();
             clear_path();
        }
        else if(choose=='N') clear_path();
    }
    else if(op==6){
        break;
    }
    }
}

int main(){
    menu();
    return 0;
}
