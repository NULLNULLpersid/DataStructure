#include <stdio.h>
#include <stdlib.h>

#define MAX 10001

typedef struct {
    int nodes[MAX];
    int size;
} AdjList;

int N, M, V;
AdjList graph[MAX];
int visitedDFS[MAX], visitedBFS[MAX];

// 인접 리스트에 정점을 추가하는 함수
void addEdge(int u, int v) {
    graph[u].nodes[graph[u].size++] = v;
    graph[v].nodes[graph[v].size++] = u;
}

// DFS 함수
void DFS(int v) {
    visitedDFS[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < graph[v].size; i++) {
        int next = graph[v].nodes[i];
        if (!visitedDFS[next]) {
            DFS(next);
        }
    }
}

// BFS 함수
void BFS(int start) {
    int queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = start;
    visitedBFS[start] = 1;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (int i = 0; i < graph[v].size; i++) {
            int next = graph[v].nodes[i];
            if (!visitedBFS[next]) {
                queue[rear++] = next;
                visitedBFS[next] = 1;
            }
        }
    }
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    scanf("%d %d %d", &N, &M, &V);

    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // 각 정점의 인접 리스트를 정렬하여 작은 정점 번호를 먼저 방문하도록 함
    for (int i = 1; i <= N; i++) {
        qsort(graph[i].nodes, graph[i].size, sizeof(int), compare);
    }

    // DFS 탐색 결과 출력
    DFS(V);
    printf("\n");

    // BFS 탐색 결과 출력
    BFS(V);

    return 0;
}