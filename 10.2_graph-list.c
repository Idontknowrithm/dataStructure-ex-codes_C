#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
#define N 50
typedef struct _Node{
    int vertex;
    struct _Node* nextNode;
}Node;

typedef struct{
    int n;
    Node* graphList[N];
}graph;

void init(graph* g);
void insertVertex(graph* g, int v);
void insertEdge(graph* g, int u, int v);
void printAdjList(graph* g);

int main () {
    graph* g = (graph*)malloc(sizeof(graph));
    init(g);
    for(int i = 0; i < 4; ++i)
        insertVertex(g, i);
    insertEdge(g, 0, 1);
    insertEdge(g, 1, 0);
    insertEdge(g, 0, 2);
    insertEdge(g, 2, 0);
    insertEdge(g, 0, 3);
    insertEdge(g, 3, 0);
    insertEdge(g, 1, 2);
    insertEdge(g, 2, 1);
    insertEdge(g, 2, 3);
    insertEdge(g, 3, 2);
    printAdjList(g);
    free(g);
    return 0;
    system("pause");
}

void init(graph* g){
    int v; g->n = 0;
    for(v = 0; v < N; ++v)
        g->graphList[v] = NULL;
}
void insertVertex(graph* g, int v){
    if((g->n + 1) > N){
        fprintf(stderr, "Error");
        return;
    }
    ++g->n;
}
void insertEdge(graph* g, int u, int v){
    Node* node = (Node*)malloc(sizeof(Node));
    if(u >= g->n || v >= g->n){
        fprintf(stderr, "Error");
        return;
    }
    node->vertex = v;
    node->nextNode = g->graphList[u];
    g->graphList[u] = node;
}
void printAdjList(graph* g){
    for(int i = 0; i < g->n; ++i){
        Node* p = g->graphList[i];
        printf("Adjacent list of vertex %d ", i);
        while(p != NULL){
            printf("-> %d ", p->vertex);
            p = p->nextNode;
        }
        printf("\n");
    }
}