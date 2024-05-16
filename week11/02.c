#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100
#define INF 1000000

typedef struct GraphType {
    int n;
    int weight[MAX][MAX];
} Graph;

int distance[MAX];
int found[MAX];

int Choose(int distance[], int n, int found[]) {
    int i, min = INT_MAX, minpos = -1;
    for (i = 0; i < n; i++) {
        if (distance[i] < min && !found[i]) {
            min = distance[i];
            minpos = i;
        }
    }
    return minpos;
}

void print_status(Graph* graph) {
    for (int i = 0; i < graph->n; i++) {
        if (distance[i] == INF) {
            printf(" * ");
        } else {
            printf("%2d ", distance[i]);
        }
    }
    printf("\n");
    for (int i = 0; i < graph->n; i++) {
        printf("%2d ", found[i]);
    }
    printf("\n\n");
}

void shortest_path(Graph* graph, int start) {
    int i, u, w;
    for (i = 0; i < graph->n; i++) {
        distance[i] = graph->weight[start][i];
        found[i] = 0;
    }
    found[start] = 1;
    distance[start] = 0;

    printf("STEP 1\n");
    print_status(graph);

    for (i = 1; i < graph->n - 1; i++) {
        u = Choose(distance, graph->n, found);
        found[u] = 1;

        for (w = 0; w < graph->n; w++) {
            if (!found[w] && graph->weight[u][w] != INF) {
                if (distance[u] + graph->weight[u][w] < distance[w]) {
                    distance[w] = distance[u] + graph->weight[u][w];
                }
            }
        }

        printf("STEP %d\n", i + 1);
        print_status(graph);
    }
}

int main(void) {
    Graph graph = { 7,
    {{ 0, 7, INF, INF, 3, 10, INF },
    { 7, 0, 4, 10, 2, 6, INF },
    { INF, 4, 0, 2, INF, INF, INF },
    { INF, 10, 2, 0, 11, 9, 4 },
    { 3, 2, INF, 11, 0, INF, 5 },
    { 10, 6, INF, 9, INF, 0, INF },
    { INF, INF, INF, 4, 5, INF, 0 } }
    };
    shortest_path(&graph, 0);
    return 0;
}