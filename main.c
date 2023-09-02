#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define INFINITY 9999

int n=0,graph[MAX][MAX];
char place[MAX][50];

void graph_input(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",&place[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
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
    printf("Min distance from %d to %d is %d\n",start,end,dis[end]);

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

int main()
{   freopen("input.txt","r",stdin);
    graph_input();
    print_graph();
    Dijkstra(0,3);
    return 0;
}
