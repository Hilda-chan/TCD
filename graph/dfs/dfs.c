#include <stdlib.h>
#include <stdio.h>
#include "../base/graph.h"


// DFS algo
void DFS(struct Graph* graph, int vertex) 
{
    struct node* adjList = graph->adj[vertex];
    struct node* temp = adjList;

    graph->visited[vertex] = 1;
    printf("Visited %d \n", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}




/*
int* DFS(struct Graph* graph, int vertex) 
{
    int* dfs_res = malloc(sizeof(int)*graph->numVertices);
    struct node* adjList = graph->adj[vertex];
    struct node* temp = adjList;

    graph->visited[vertex] = 1;
    printf("Visited %d \n", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}
*/
