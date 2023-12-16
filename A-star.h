#ifndef A-STAR_H_INCLUDED
#define A-STAR_H_INCLUDED

float p_time,p_cost;
int A_parent[MAX];

int costArray[MAX][MAX] = {
        {0, 270, 340, 620, 3800, 490, 580, 680},
        {270, 0, 310, 580, 340, 320, 400, 640},
        {340, 310, 0, 340, 160, 460, 550, 450},
        {620, 580, 340, 0, 300, 750, 840, 480},
        {3800, 340, 160, 300, 0, 520, 600, 310},
        {490, 320, 460, 750, 520, 0, 170, 790},
        {580, 400, 550, 840, 600, 170, 0, 880},
        {680, 640, 450, 480, 310, 790, 880, 0}
    };

int timeArray[MAX][MAX] = {
        {0, 200, 240, 420, 270, 250, 400, 450},
        {200, 0, 230, 430, 260, 240, 300, 440},
        {240, 230, 0, 240, 120, 340, 280, 290},
        {420, 430, 240, 0, 210, 400, 600, 310},
        {270, 260, 120, 210, 0, 380, 440, 190},
        {250, 240, 340, 400, 380, 0, 120, 540},
        {400, 300, 280, 600, 440, 120, 0, 600},
        {450, 440, 290, 310, 190, 540, 600, 0}
    };
int astar_graph[MAX][MAX];

int minFValue(int f[],int openSet[]) {
    int min=INT_MAX,minIndex;

    for(int v=0;v<n;v++) {
        if (openSet[v] && f[v]<min) {
            min = f[v];
            minIndex = v;
        }
    }
    return minIndex;
}

int heuristic_f(int node,int goal){
    return costArray[node][goal]*p_cost+timeArray[node][goal]*p_time;
}

void aStarSearch(int start, int goal) {
    int g[MAX];
    int f[MAX];
    int openSet[MAX];


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]==INT_MAX) astar_graph[i][j]=0;
            else astar_graph[i][j]=graph[i][j]*(1-p_cost-p_time)+costArray[i][j]*p_cost+timeArray[i][j]*p_time;
        }
    }
    for (int i=0;i<n;i++) {
        g[i]=INT_MAX;
        f[i]=INT_MAX;
        openSet[i]=1;
        A_parent[i]=-1;
    }

    g[start]=0;
    f[start]=heuristic_f(start, goal);

    while(1){
        int curr=minFValue(f,openSet);

        if (curr == goal || f[curr] == INT_MAX) {
            break;
        }

        openSet[curr] = 0;

        for (int i=0;i<n;i++) {
            if (astar_graph[curr][i] && openSet[i]) {
                int tentativeG=g[curr]+astar_graph[curr][i];

                if (tentativeG<g[i]) {
                    g[i]=tentativeG;
                    f[i]=g[i]+heuristic_f(i, goal);
                    A_parent[i] = curr;
                }
            }
        }
    }
}

void astar_path(int path[], int start, int goal) {
    int curr = goal;
    int pathIndex = 0;
    while (curr != -1) {
        path[pathIndex] = curr;
        pathIndex++;
        point++;
        curr = A_parent[curr];
    }

    for (int i = 0, j = pathIndex - 1; i < j; i++, j--) {
        int temp = path[i];
        path[i] = path[j];
        path[j] = temp;
    }

    printf("Stored path from %s to %s: ", place[start], place[goal]);
    for (int i = 0; i < pathIndex; i++) {
        printf("%s ", place[path[i]]);
    }

    printf("\n");
}

#endif // A-STAR_H_INCLUDED
