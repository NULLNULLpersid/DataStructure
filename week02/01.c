#include <stdio.h>

int main(void) {
	int day[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (int i = 0; i < sizeof(day) / sizeof(int); i++) {
		printf("%d %d\n", i+1, day[i]);
	}
	return 0;
}