#ifndef TSP_H_INCLUDED
#define TSP_H_INCLUDED


int tsp_visited_ALL;
int dp[MAX][1<<MAX],parent[MAX][1<<MAX];
int tsp_graph[MAX][MAX];
void tsp_initials(){
    tsp_visited_ALL = (1<<n)-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<(1<<MAX);j++){
            dp[i][j]=-1;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]==INT_MAX){
                tsp_graph[i][j]=9999;
            }
            else{
                tsp_graph[i][j]=graph[i][j];
            }
        }
    }
}

int tsp(int mask, int pos,int start){

    if(mask==tsp_visited_ALL){
        return tsp_graph[pos][start];
    }
    if(dp[pos][mask]!=-1){
        return dp[pos][mask];
    }

    int dis=INT_MAX;
    int next_c=-1;
    for(int c=0;c<n;c++){
        if((mask & (1<<c))==0){
            int new_dis=tsp_graph[pos][c]+tsp(mask|(1<<c),c,start);
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
    if(mask==tsp_visited_ALL){
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


#endif // TSP_H_INCLUDED
