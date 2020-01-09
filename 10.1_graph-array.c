/* Undirected Graph */
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct{
    int n;
    int graphArray[50][50];
}graph;
void init(graph* g);
void insertVertex(graph* g, int v);
void insertEdge(graph* g, int start, int end);
void printAdjMat(graph* g);
void printAdjMat(graph* g);
int main () {
    graph* g = (graph*)malloc(sizeof(graph));
    init(g);
    for(int i = 0; i < 4; ++i)
        insertVertex(g, i);
    insertEdge(g, 0, 1);
    insertEdge(g, 0, 2);
    insertEdge(g, 0, 3);
    insertEdge(g, 1, 2);
    insertEdge(g, 2, 3);
    printAdjMat(g);
    free(g);
    return 0;
}

void init(graph* g){
    int r, c;
    g->n = 0;
    for(r = 0; r < 50; ++r)
        for(c = 0; c < 50; ++c)
            g->graphArray[r][c] = 0;
}
void insertVertex(graph* g, int v){
    if((g->n) + 1 > 50){
        fprintf(stderr, "graph : exceed the limit\n");
        return;
    }
    ++g->n;
}
void insertEdge(graph* g, int start, int end){
    if (start >= g->n || end >= g->n){
        fprintf(stderr, "graph : exceed the limit\n");
        return;
    }
    g->graphArray[start][end] = 1;
    g->graphArray[end][start] = 1;
}
void printAdjMat(graph* g){
    for(int i = 0; i < g->n; ++i){
        for(int j = 0; j < g->n; ++j)
            printf("%2d ", g->graphArray[i][j]);
        printf("\n");
    }
}