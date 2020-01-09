#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define True 1
#define False 0
#define M 100
#define INF 10000000

typedef struct{
    int n;
    int weight[M][M];
} graph;

int distance[M];    //시작점으로부터 최단경로 거리
int found[M];       //방문한 정점
int choose(int* distance, int n, int* found);
void printStatus(graph* g);
void shortestPath(graph* g, int start);

int main () {
    graph g = {
        7, 
        {{0,   7, INF, INF, 3, 10,  INF}, 
         {7,   0,   4, 10, 2,  6,   INF},
         {INF, 4,   0, 2, INF, INF, INF},
         {INF, 10,  2,   0,  11, 9,   4},
         {3,   2,   INF, 11, 0,  INF, 5},
         {10,  6,   INF, 9, INF, 0,   INF},
         {INF, INF, INF, 4, 5,   INF, 0}}
    };
    shortestPath(&g, 0);
    system("pause");
}

int choose(int* distance, int n, int* found){
    int i, min, minpos;
    min = 2147000000;
    minpos = -1;
    for(i = 0; i < n; ++i){
        if(distance[i] < min && !found[i]){
            min = distance[i];
            minpos = i;
        }
    }
    return minpos;
}
void printStatus(graph* g){
    static int step = 1;
    printf("STEP %d: ", step++);
    printf("distance: ");
    for(int i = 0; i < g->n; ++i){
        if(distance[i] == INF)
            printf(" * ");
        else 
            printf("%2d ", distance[i]);
    }
    printf("\n");
    printf(" found: ");
    for(int i = 0; i < g->n; ++i)
        printf("%2d ", found[i]);
    printf("\n\n");
}
void shortestPath(graph* g, int start){
    int i, u, w;
    for(i = 0; i < g->n; ++i){
        distance[i] = g->weight[start][i];
        found[i] = False;
    }
    found[start] = True;
    distance[start] = 0;
    for(i = 0; i < g->n - 1; ++i){
        printStatus(g);
        u = choose(distance, g->n, found);
        found[u] = True;
        for(w = 0; w < g->n; ++w)
            if(!found[w])
                if(distance[u] + g->weight[u][w] < distance[w])
                 distance[w] = distance[u] + g->weight[u][w];
    }
}