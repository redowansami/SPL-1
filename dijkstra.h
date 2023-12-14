#ifndef DIJKSTRA_H_INCLUDED
#define DIJKSTRA_H_INCLUDED

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

void Dijkstra(int start,int end,int op){
    int cost[MAX][MAX],dis[MAX],prev[MAX];
    int visited[MAX],count=0,min,next;
    if(op==5){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(graph[i][j]==0 || graph[i][j]==INT_MAX)
                    cost[i][j]=INFINITY;

                else cost[i][j]=graph[i][j];
            }
        }
    }

    if(op==6){

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


#endif // DIJKSTRA_H_INCLUDED
