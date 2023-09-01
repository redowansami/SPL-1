#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 10

int n,graph[MAX][MAX];
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

    return 0;
}
