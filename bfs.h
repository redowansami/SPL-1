#ifndef BFS_H_INCLUDED
#define BFS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct {
    int front, rear;
    int items[MAX_VERTICES];
} Queue;

int visited[MAX_VERTICES];
int predecessor[MAX_VERTICES];

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int vertex) {
    if (q->rear == MAX_VERTICES - 1) {
        printf("Queue overflow!\n");
        return;
    }

    if (q->front == -1) {
        q->front = 0;
    }

    q->rear++;
    q->items[q->rear] = vertex;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue underflow!\n");
        return -1;
    }

    int vertex = q->items[q->front];
    q->front++;

    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }

    return vertex;
}

int bfs(int vertices, int start, int end, int path[MAX_VERTICES]) {
    Queue q;
    initQueue(&q);

    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
        predecessor[i] = -1;
    }

    visited[start] = 1;
    enqueue(&q, start);

    while (!isEmpty(&q)) {
        int u = dequeue(&q);

        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] && graph[u][v]!=INT_MAX && !visited[v]) {
                visited[v] = 1;
                predecessor[v] = u;
                enqueue(&q, v);

                if (v == end) {
                    // Path found, reconstruct and store the path in the array
                    int current = end;
                    int pathLength = 0;

                    while (current != -1) {
                        path[pathLength++] = current;
                        current = predecessor[current];
                    }

                    // Reverse the path in the array
                    for (int i = 0, j = pathLength - 1; i < j; i++, j--) {
                        int temp = path[i];
                        path[i] = path[j];
                        path[j] = temp;
                    }

                    return pathLength; // Return the length of the path
                }
            }
        }
    }

    return 0; // Path not found
}

#endif // BFS_H_INCLUDED
