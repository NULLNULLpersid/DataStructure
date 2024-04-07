#include <stdio.h>
#define MAX_LEVEL 50
#define MAX_WIDTH 40
char screen[MAX_LEVEL][MAX_WIDTH];

void initialize_screen() {
    for (int i = 0; i < MAX_LEVEL; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            screen[i][j] = '-';
        }
    }
}
void draw_tree(int row, int left, int right) {
    if (right - left < 3 || row >= MAX_LEVEL) return;
    int root = (left + right) / 2;
    screen[row][root] = 'X';
    draw_tree(row + 1, root, right); // 왼쪽 영역
    draw_tree(row + 1, left, root); // 오른쪽 영역
}

void print_screen() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            printf("%c", screen[i][j]);
        }
        printf("\n");
    }
}

int main() {
    initialize_screen();
    draw_tree(0, 0, MAX_WIDTH);
    print_screen();

    return 0;
}