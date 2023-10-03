#ifndef FLOYD_H_INCLUDED
#define FLOYD_H_INCLUDED


void printMatrix(int matrix[MAX][MAX]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == INFINITY)
        printf("%4s", "INFINITY");
      else
        printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
}

void print_floyd_path(int next[MAX][MAX],int start,int end){
    if(next[start][end]==-1){
        printf("NO PATH");
        return;
    }
    else if(next[start][end]==start){
        printf("%s",place[start]);
    }
    else{
        print_floyd_path(next,start,next[start][end]);
        print_floyd_path(next,next[start][end],end);
    }
}

void floydWarshall() {
    int matrix[MAX][MAX],next[MAX][MAX];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            matrix[i][j]= graph[i][j];
            if(graph[i][j]==INFINITY) next[i][j]=-1;
            else next[i][j]=i;
        }
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] > (matrix[i][k] + matrix[k][j])){
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                    next[i][j]=next[k][j];
                }
            }
        }
    }

  printMatrix(next);
  print_floyd_path(next,1,7);
}

#endif // FLOYD_H_INCLUDED
