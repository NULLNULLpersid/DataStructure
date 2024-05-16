#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 1000L

typedef struct GraphType {
    int n;
    int weight[MAX][MAX];
} Graph;

int selected[MAX];
int distance[MAX];

int MinVertex(int n) {
    int v = -1;
    for (int i = 0; i < n; i++) {
        if (!selected[i] && (v == -1 || distance[i] < distance[v])) {
            v = i;
        }
    }
    return v;
}

void Prim(Graph *graph, int s) {
    int i, u, v;
    for (u = 0; u < graph->n; u++) distance[u] = INF;
    distance[s] = 0;
    for (i = 0; i < graph->n; i++) {
        u = MinVertex(graph->n);
        if (u == -1) return;
        selected[u] = 1;
        printf("정점 %d 추가\n", u);
        for (v = 0; v < graph->n; v++) {
            if (graph->weight[u][v] != INF && !selected[v] && graph->weight[u][v] < distance[v]) {
                distance[v] = graph->weight[u][v];
            }
        }
    }
}

int main(void) {
    Graph graph = { 7,
    {{ 0, 29, INF, INF, INF, 10, INF },
    { 29, 0, 16, INF, INF, INF, 15 },
    { INF, 16, 0, 12, INF, INF, INF },
    { INF, INF, 12, 0, 22, INF, 18 },
    { INF, INF, INF, 22, 0, 27, 25 },
    { 10, INF, INF, INF, 27, 0, INF },
    { INF, 15, INF, 18, 25, INF, 0 } }
    };

    for (int i = 0; i < MAX; i++) {
        selected[i] = 0;
    }

    Prim(&graph, 0);
    return 0;
}