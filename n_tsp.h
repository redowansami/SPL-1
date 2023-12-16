//#ifndef N_TSP_H_INCLUDED
//#define N_TSP_H_INCLUDED
//
//int a[10][10], tsp_visited[10], cost = 0;
//int tsp_start;
//
//bool visited_all(){
//    for(int i=0;i<n;i++){
//        if(tsp_visited[i]==0) return false;
//        else {
//            return true;
//        }
//
//    }
//
//}
//
//void init_tsp() {
//
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            if(graph[i][j]==INT_MAX){
//                a[i][j]=0;
//                continue;
//            }
//            a[i][j]=graph[i][j];
//        }
//    }
//
//    for(int i=0;i<n;i++) {
//        tsp_visited[i]=0;
//    }
//}
//
//int least(int c) {
//    int i, nc = 999;
//    int min = 999, kmin;
//    for (i = 0; i < n; i++) {
//        if ((a[c][i] != 0) && (tsp_visited[i] == 0))
//            if (a[c][i] < min) {
//                min = a[i][tsp_start] + a[c][i];
//                kmin = a[c][i];
//                nc = i;
//            }
//    }
//    if (min != 999)
//        cost += kmin;
//    return nc;
//}
//
//
//void mincost(int loc,int start) {
//    tsp_start=start;
//    int n_loc;
//
////    printf("%d –>", loc + 1);
//    path_array[point]=loc;
//    point++;
//    tsp_visited[loc] = 1;
//    n_loc = least(loc);
//    if (n_loc == 999 && visited_all()) {
//        n_loc = start;
////        printf("%d", n_loc + 1);
//        path_array[point]=n_loc;
//        point++;
//        cost += a[loc][n_loc];
//        return;
//    }
//    mincost(n_loc,start);
//}
//
//void tsp_print(){
//    for(int i=0;i<=point;i++){
//        printf("%s ->",place[path_array[i]]);
//    }
//    printf("\n\nMinimum cost is :");
//    printf("%d", cost);
//    cost=0;
//}
//
//#endif // N_TSP_H_INCLUDED
//
