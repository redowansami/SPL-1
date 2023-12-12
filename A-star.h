#ifndef A-STAR_H_INCLUDED
#define A-STAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 10
#define INFINITY 999999

typedef struct {
    int id;
    int g;
    int h;
} Node;

typedef struct {
    Node* nodes[MAX_NODES];
    int size;
} PriorityQueue;

void initializePriorityQueue(PriorityQueue* pq) {
    pq->size = 0;
}

bool isPriorityQueueEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

void enqueue(PriorityQueue* pq, Node* node) {
    int i = pq->size++;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (pq->nodes[parent]->g + pq->nodes[parent]->h <= node->g + node->h) {
            break;
        }
        pq->nodes[i] = pq->nodes[parent];
        i = parent;
    }
    pq->nodes[i] = node;
}

Node* dequeue(PriorityQueue* pq) {
    Node* minNode = pq->nodes[0];
    Node* lastNode = pq->nodes[--pq->size];
    int i = 0;
    while (i * 2 + 1 < pq->size) {
        int leftChild = i * 2 + 1;
        int rightChild = leftChild + 1;
        int minChild = (rightChild < pq->size && pq->nodes[rightChild]->g + pq->nodes[rightChild]->h < pq->nodes[leftChild]->g + pq->nodes[leftChild]->h) ? rightChild : leftChild;
        if (pq->nodes[minChild]->g + pq->nodes[minChild]->h >= lastNode->g + lastNode->h) {
            break;
        }
        pq->nodes[i] = pq->nodes[minChild];
        i = minChild;
    }
    pq->nodes[i] = lastNode;
    return minNode;
}

Node* createNode(int id, int g, int h) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    newNode->g = g;
    newNode->h = h;
    return newNode;
}

void aStarSearch(int graph[MAX_NODES][MAX_NODES], int numNodes, int startId, int goalId, int heuristic[MAX_NODES]) {
    int gValues[MAX_NODES];
    int parentNodes[MAX_NODES];

    for (int i = 0; i < numNodes; ++i) {
        gValues[i] = INFINITY;
        parentNodes[i] = -1;
    }

    gValues[startId] = 0;

    PriorityQueue openList;
    initializePriorityQueue(&openList);

    enqueue(&openList, createNode(startId, 0, heuristic[startId]));

    while (!isPriorityQueueEmpty(&openList)) {
        Node* current = dequeue(&openList);

        if (current->id == goalId) {
            printf("Goal node found!\n");

            int node = goalId;

            while (parentNodes[node] != -1) {
                path_array[point++] = node;
                node = parentNodes[node];
            }

            path_array[point] = startId;

            printf("Shortest path: ");
            for (int i=point; i>= 0; --i) {
                printf("%s ", place[path_array[i]]);
            }
            printf("\n");

            int temp[point+1];
            for(int i=0;i<=point;i++){
                temp[i]=path_array[i];
            }

            for(int i=0,j=point;i<=point;i++,j--){
                path_array[i]=temp[j];
            }

            free(current);
            return;
        }

        for (int neighbor = 0; neighbor < numNodes; ++neighbor) {
            if (graph[current->id][neighbor] > 0) {
                int newG = current->g + graph[current->id][neighbor];
                if (newG < gValues[neighbor]) {
                    gValues[neighbor] = newG;
                    parentNodes[neighbor] = current->id;

                    enqueue(&openList, createNode(neighbor, newG, heuristic[neighbor]));
                }
            }
        }

        free(current);
    }

    printf("No path found.\n");
}

#endif // A-STAR_H_INCLUDED
