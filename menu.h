#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "graph.h"
#include "dijkstra.h"
#include "kruskal.h"
#include "prims.h"
#include "tsp.h"
#include "n_tsp.h"
#include "floyd.h"
#include "A-star.h"
#include "bfs.h"

void menu(){
    int op=0;
    for(;op!=12;){
    printf("\n");
    printf("                 ___________________________________________\n");
    printf("                |               ===MENU===                  |\n");
    printf("                | 1. Load Map                               |\n");
    printf("                | 2. View the Locations                     |\n");
    printf("                | 3. View the Graph                         |\n");
    printf("                | 4. View Path                              |\n");
    printf("                | 5. View the Shortest Path                 |\n");
    printf("                | 6. Minimum Cost Path                      |\n");
    printf("                | 7. View the route with minimum distance   |\n");
    printf("                |    and back to starting point             |\n");
    printf("                | 8. Paths with Minimum Distance to visit   |\n");
    printf("                |    all Locations                          |\n");
    printf("                | 9. Paths with Minimum Distance to visit   |\n");
    printf("                |    all Locations(From a start point)      |\n");
    printf("                | 10. Time and cost effiecient path         |\n");
    printf("                | 11. Remove path                           |\n");
    printf("                | 12. Exit                                  |\n");
    printf("                |___________________________________________|\n");
    printf("Select Your Option: ");
    scanf("%d",&op);
    if(op==1){
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
        point=bfs(n,get_index(start),get_index(end),path_array);
        for(int i=0;i<=point;i++) printf("%s ->",place[path_array[i]]);
        printf("Show the graph?(Y/N) :");
        scanf("%c",&choose);
        if(choose=='Y'){
             view_graph();
             clear_path();
        }
        else if(choose=='N') clear_path();
    }

    else if(op==5){
        char start[50],end[50];
        char choose;
        printf("Enter the Starting Location-");
        scanf("%s",start);
        getchar();
        printf("Enter the Stopping Location-");
        scanf("%s",end);
        getchar();
        Dijkstra(get_index(start),get_index(end),5);
        printf("Show the graph?(Y/N) :");
        scanf("%c",&choose);
        if(choose=='Y'){
             view_graph();
             clear_path();
        }
        else if(choose=='N') clear_path();
    }

    else if(op==6){
        char start[50],end[50];
        char choose;
        printf("Enter the Starting Location-");
        scanf("%s",start);
        getchar();
        printf("Enter the Stopping Location-");
        scanf("%s",end);
        getchar();
        Dijkstra(get_index(start),get_index(end),6);
        printf("Show the graph?(Y/N) :");
        scanf("%c",&choose);
        if(choose=='Y'){
             view_graph();
             clear_path();
        }
        else if(choose=='N') clear_path();
    }

    else if(op==7){
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

    else if(op==8){
        kruskal();
        print_kruskal();
        view_graph();
    }

    else if(op==9){
        char start[50];
        printf("Enter the Starting Location-");
        scanf("%s",start);
        getchar();
        prims(get_index(start));
        view_graph();
    }

    else if(op==10){
        char start[50],end[50];
        char choose;
        printf("Enter the Starting Location-");
        scanf("%s",start);
        getchar();
        printf("Enter the Stopping Location-");
        scanf("%s",end);
        getchar();
        printf("Enter the priority of time and cost(<1)-");
        scanf("%f %f",&p_time,&p_cost);
        getchar();
        aStarSearch(get_index(start),get_index(end));
        astar_path(path_array,get_index(start),get_index(end));
        printf("Show the graph?(Y/N) :");
        scanf("%c",&choose);
        if(choose=='Y'){
             view_graph();
             clear_path();
        }
        else if(choose=='N') clear_path();
    }

    else if(op==11){
        char start[50],end[50];
        char choose;
        char stop[5];
        for(;;){
            printf("Enter the Starting Location-");
            scanf("%s",start);
            getchar();
            printf("Enter the Stopping Location-");
            scanf("%s",end);
            getchar();
            graph[get_index(start)][get_index(end)]=INT_MAX;
            graph[get_index(end)][get_index(start)]=INT_MAX;
            printf("Path removed successfully from %s to %s\n",start,end);
            printf("Do you want to remove another path? (Type YES to continue, NO to stop)\n");
            scanf("%s",stop);
            getchar();
            if(!strcmp(stop,"NO")) break;
        }
    }


    else if(op==12){
        break;
    }

    }
}

#endif // MENU_H_INCLUDED
