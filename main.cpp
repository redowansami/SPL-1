#include <iostream>
//#include <graphics.h>
#include "graph.h"
#include "dijkstra.h"
#include "tsp.h"
#include "floyd.h"
#include "A-star.h"
#include <stdio.h>
#include <string.h>

using namespace std;


void menu(){
    int op=0;
    for(;op!=6;){
    printf("\n");
    printf(" _______________________________________\n");
    printf("|               ===MENU===              |\n");
    printf("| 1. Load Map                           |\n");
    printf("| 2. View the Locations                 |\n");
    printf("| 3. View the Graph                     |\n");
    printf("| 4. View the Shortest Path             |\n");
    printf("| 5. View the route with min distance   |\n");
    printf("| 6. Exit                               |\n");
    printf("| 7. A* Search                          |\n");
    printf("| 8. Remove path                        |\n");
    printf("|_______________________________________|\n");
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
        view_graph();
    }

    else if(op==4){
        char start[50],end[50];
        char choose;
        printf("Enter the Starting Location-");
        scanf("%s",start);
        getchar();
        printf("Enter the Stopping Location-");
        scanf("%s",end);
        getchar();
        Dijkstra(get_index(start),get_index(end));
        printf("Show the graph?(Y/N) :");
        scanf("%c",&choose);
        if(choose=='Y'){
             view_graph();
             clear_path();
        }
        else if(choose=='N') clear_path();
    }
    else if(op==5){
        tsp_initials();
        char s_loc[50];
        char choose;
        printf("Enter the starting location: ");
        scanf("%s",s_loc);
        getchar();
        //CHAGING THE MASK
        int x=get_index(s_loc);
        printf("Minimum distance is %d\n",tsp(1<<x,x,x));
        print_tsp_path(1<<x,x,x,1);
        printf("\n");
        for(int i=0;i<point;i++){
            printf("%s->",place[path_array[i]]);
        }
        printf("\n");
        printf("Show the graph?(Y/N) :");
        scanf("%c",&choose);
        if(choose=='Y'){
             view_graph();
             clear_path();
        }
        else if(choose=='N') clear_path();
    }

    else if(op==7){
        char start[50],end[50];
        char choose;
        printf("Enter the Starting Location-");
        scanf("%s",start);
        getchar();
        printf("Enter the Stopping Location-");
        scanf("%s",end);
        getchar();
        int heuristicValues[MAX_NODES] = {0, 9, 40, 2, 8000, 1, 3, 5};
        aStarSearch(graph ,n ,get_index(start) ,get_index(end) , heuristicValues);
        printf("Show the graph?(Y/N) :");
        scanf("%c",&choose);
        if(choose=='Y'){
             view_graph();
             clear_path();
        }
        else if(choose=='N') clear_path();
    }

    else if(op==8){
        char start[50],end[50];
        char choose;
        printf("Enter the Starting Location-");
        scanf("%s",start);
        getchar();
        printf("Enter the Stopping Location-");
        scanf("%s",end);
        getchar();
        graph[get_index(start)][get_index(end)]=INT_MAX;
        graph[get_index(end)][get_index(start)]=INT_MAX;
        printf("Path removed successfully from %s to %s\n",start,end);
    }

    else if(op==6){
        break;
    }
    }
}

int main(){
    menu();
//    graph_input();
//    for(int i=0;i<n;i++){
//        printf("%d. %s\n",i,place[i]);
//    }
//    floydWarshall();
//    print_graph();
    return 0;
}
