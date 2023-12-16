#ifndef PRIMS_H_INCLUDED
#define PRIMS_H_INCLUDED

void prims(int startNode) {
    int no_edge=0;
    bool selected[MAX];

    for(int i=0;i<MAX;i++){
        selected[i]=false;
    }

    selected[startNode]=true;

    int x;
    int y;

    printf("Path : Distance\n");

    while(no_edge<n-1){
        int min = INT_MAX;
        x=0;
        y=0;
        for(int i=0;i<n;i++){
            if(selected[i]){
                for(int j=0;j<n;j++) {
                    if (!selected[j] && graph[i][j] && graph[i][j]!=INT_MAX){
                        if (min>graph[i][j]) {
                            min=graph[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }
        edges[n_edge].u=x;
        edges[n_edge].v=y;
        n_edge++;
        printf("%s -> %s : %d\n",place[x],place[y],graph[x][y]);
        selected[y]=true;
        no_edge++;
    }
}

#endif // PRIMS_H_INCLUDED
