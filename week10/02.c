// #include <stdio.h>
// #include <stdlib.h>

// #define MAX 10001

// typedef struct {
//     int nodes[MAX];
//     int size;
// } AdjList;

// int N, M, V;
// AdjList graph[MAX];
// int visitedDFS[MAX], visitedBFS[MAX];

// // 인접 리스트에 정점을 추가하는 함수
// void addEdge(int u, int v) {
//     graph[u].nodes[graph[u].size++] = v;
//     graph[v].nodes[graph[v].size++] = u;
// }

// // DFS 함수
// void DFS(int v) {
//     visitedDFS[v] = 1;
//     printf("%d ", v);

//     for (int i = 0; i < graph[v].size; i++) {
//         int next = graph[v].nodes[i];
//         if (!visitedDFS[next]) {
//             DFS(next);
//         }
//     }
// }

// // BFS 함수
// void BFS(int start) {
//     int queue[MAX];
//     int front = 0, rear = 0;

//     queue[rear++] = start;
//     visitedBFS[start] = 1;

//     while (front < rear) {
//         int v = queue[front++];
//         printf("%d ", v);

//         for (int i = 0; i < graph[v].size; i++) {
//             int next = graph[v].nodes[i];
//             if (!visitedBFS[next]) {
//                 queue[rear++] = next;
//                 visitedBFS[next] = 1;
//             }
//         }
//     }
// }

// int compare(const void *a, const void *b) {
//     return (*(int*)a - *(int*)b);
// }

// int main() {
//     scanf("%d %d %d", &N, &M, &V);

//     for (int i = 0; i < M; i++) {
//         int u, v;
//         scanf("%d %d", &u, &v);
//         addEdge(u, v);
//     }

//     // 각 정점의 인접 리스트를 정렬하여 작은 정점 번호를 먼저 방문하도록 함
//     for (int i = 1; i <= N; i++) {
//         qsort(graph[i].nodes, graph[i].size, sizeof(int), compare);
//     }

//     // DFS 탐색 결과 출력
//     DFS(V);
//     printf("\n");

//     // BFS 탐색 결과 출력
//     BFS(V);

//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>

#define MAX 10001

// 인접 행렬과 방문 배열 선언
int graph[MAX][MAX] = {0};
int visited[MAX] = {0};

// 스택과 큐 관련 변수 선언
int stack[MAX], top = -1;
int queue[MAX], front = -1, rear = -1;

// 그래프의 정점 개수와 간선 개수 선언
int N, M, V;

// 스택 push 함수
void push(int v) {
    stack[++top] = v;
}

// 스택 pop 함수
int pop() {
    return stack[top--];
}

// 큐 enqueue 함수
void enqueue(int v) {
    queue[++rear] = v;
}

// 큐 dequeue 함수
int dequeue() {
    return queue[++front];
}

// DFS 함수
void DFS(int v) {
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 1; i <= N; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

// BFS 함수
void BFS(int v) {
    enqueue(v);
    visited[v] = 1;

    while (front != rear) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 1; i <= N; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    // 입력 받기
    scanf("%d %d %d", &N, &M, &V);

    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    // DFS 실행 및 결과 출력
    DFS(V);
    printf("\n");

    // 방문 배열 초기화
    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
    }

    // BFS 실행 및 결과 출력
    BFS(V);
    //printf("\n");

    return 0;
}