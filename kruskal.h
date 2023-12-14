#ifndef KRUSKAL_H_INCLUDED
#define KRUSKAL_H_INCLUDED

typedef struct edge {
  int u;
  int v;
  int w;
}edge;

typedef struct edge_list{
  edge edges[MAX];
  int num;
}edge_list;

edge_list e_list;

edge_list span_list;

// Printing the result
void print_kruskal() {
    int cost = 0;

    for (int i=0;i<span_list.num;i++){
        printf("\n%s -> %s : %d",place[span_list.edges[i].u],place[span_list.edges[i].v],span_list.edges[i].w);
        cost+=span_list.edges[i].w;
    }

    for (int i=0;i<span_list.num;i++){
        edges[n_edge].u=span_list.edges[i].u;
        edges[n_edge].v=span_list.edges[i].v;
        n_edge++;
    }

    printf("\nMinimum cost: %d", cost);
}

void sort_edge(){
    edge temp;

    for(int i=1;i<e_list.num;i++){
        for(int j=0;j<e_list.num-1;j++){
            if(e_list.edges[j].w > e_list.edges[j+1].w){
                temp=e_list.edges[j];
                e_list.edges[j]=e_list.edges[j+1];
                e_list.edges[j+1]=temp;
            }
        }
    }
}

int find(int belongs[], int node) {
  return (belongs[node]);
}

void applyUnion(int belongs[],int c1,int c2) {
    for (int i=0;i<n;i++){
        if (belongs[i] == c2){
            belongs[i] = c1;
        }
    }
}

void kruskal() {
    int belongs[MAX],cno1,cno2;
    e_list.num=0;

    for(int i=1;i<n;i++){
        for (int j=0;j<i;j++) {
          if (graph[i][j]!=0 && graph[i][j]!=INT_MAX) {
            e_list.edges[e_list.num].u=i;
            e_list.edges[e_list.num].v=j;
            e_list.edges[e_list.num].w=graph[i][j];
            e_list.num++;
          }
        }
    }
    sort_edge();

    for(int i=0;i<n;i++){
        belongs[i]=i;
    }

    span_list.num=0;

    for(int i=0;i<e_list.num;i++){
        cno1=find(belongs,e_list.edges[i].u);
        cno2=find(belongs,e_list.edges[i].v);

        if(cno1!=cno2){
            span_list.edges[span_list.num] = e_list.edges[i];
            span_list.num+=1;
            applyUnion(belongs,cno1,cno2);
        }
    }
}

//  int i, j, total_cost;
//  kruskalAlgo();
//  print();


#endif // KRUSKAL_H_INCLUDED
