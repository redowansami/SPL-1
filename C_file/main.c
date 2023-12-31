#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 10
#define INFINITY 9999

int n=0,graph[MAX][MAX];
char place[MAX][50];

void graph_input(){
    FILE *fp;
    fp=fopen("input.txt","r");
    fscanf(fp,"%d",&n);
    for(int i=0;i<n;i++){
        fscanf(fp,"%s",&place[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            fscanf(fp,"%d",&graph[i][j]);
        }
    }
    fclose(fp);
}

int get_index(char name[]){
    for(int i=0;i<n;i++){
        if(!strcmp(name,place[i])) return i;
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

void print_path(int start,int end,int prev[],int flag){
    if(flag){
        printf("%s ->",place[start]);
    }
    if(prev[end]==start){
        printf("%s ->",place[end]);
    }
    if(prev[end]!=start){
        print_path(start,prev[end],prev,0);
        printf("%s ->",place[end]);
    }
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
    for(;op!=4;){
    printf("\n===Welcome===\n");
    printf("1. Load Map\n");
    printf("2. View the Locations\n");
    printf("3. View the Shortest Path\n");
    printf("4. Exit\n");
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
        char start[50],end[50];
        printf("Enter the Starting Location-");
        scanf("%s",start);
        getchar();
        printf("Enter the Stoppting Location-");
        scanf("%s",end);
        getchar();
        Dijkstra(get_index(start),get_index(end));
    }
    else if(op==4){
        break;
    }
    }
}

int main(){
    menu();
    return 0;
}
