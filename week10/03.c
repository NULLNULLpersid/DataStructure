#include <stdio.h>
#include <stdlib.h>

#define MAX 25

int N;
int map[MAX][MAX];
int visited[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int houseCount[MAX * MAX];
int complexCount = 0;

void DFS(int x, int y) {
    visited[x][y] = 1;
    houseCount[complexCount]++;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
            if (map[nx][ny] == 1 && !visited[nx][ny]) {
                DFS(nx, ny);
            }
        }
    }
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && !visited[i][j]) {
                complexCount++;
                DFS(i, j);
            }
        }
    }

    qsort(houseCount + 1, complexCount, sizeof(int), compare);

    printf("%d\n", complexCount);
    for (int i = 1; i <= complexCount; i++) {
        printf("%d\n", houseCount[i]);
    }

    return 0;
}