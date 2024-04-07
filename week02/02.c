#include <stdio.h>

void matrix_diff(int *a, int *b, int *c, int size) {
	for (int i = 0; i < size; i++) {
		c[i] = *(a+i) - *(b+i);
	}
	for (int i = 0; i < size; i++) {
		printf("%d ", *(c+i));
	}
}

int main() {

	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int b[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int c[10];
	matrix_diff(a, b, c, sizeof(c) / sizeof(int));
	return 0;
}