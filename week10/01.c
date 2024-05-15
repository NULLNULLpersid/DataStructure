#include <stdio.h>
#include <stdlib.h>

char **InputArrCreat(int n, int m) {
    char **arr = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++) {
        arr[i] = (char*)malloc(sizeof(char) * (m + 1));
        scanf("%s", arr[i]);   
    }
    return arr;
}

typedef struct Point {
    int x, y;
} Point;

typedef struct Queue {
    Point *data;
    int front, rear;
} Queue;

void QueueInit(Queue *queue, int n, int m) {
    queue->data = (Point*)malloc(sizeof(Point) * n * m);
    queue->front = queue->rear = 0;
}

int QueueEmpty(Queue *queue) {
    return (queue->front == queue->rear);
}

void EnQueue(Queue *queue, Point p) {
    queue->data[(queue->rear)++] = p;
}

Point DeQueue(Queue *queue) {
    return queue->data[(queue->front)++];
}

void bfs(char **arr, int **dist, int n, int m) {
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    Queue queue;
    QueueInit(&queue, n, m);
    Point start = {0, 0};
    EnQueue(&queue, start);
    dist[0][0] = 1;

    while (!QueueEmpty(&queue)) {
        Point current = DeQueue(&queue);
        int x = current.x;
        int y = current.y;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && arr[nx][ny] == '1' && dist[nx][ny] == 0) {
                dist[nx][ny] = dist[x][y] + 1;
                Point next = {nx, ny};
                EnQueue(&queue, next);
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    char **arr = InputArrCreat(n, m);

    int **dist = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        dist[i] = (int*)malloc(sizeof(int) * m);
        for (int j = 0; j < m; j++) {
            dist[i][j] = 0;
        }
    }

    bfs(arr, dist, n, m);

    printf("%d", dist[n-1][m-1]);

    return 0;
}