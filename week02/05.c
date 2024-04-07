#include <stdio.h>
#include <string.h>

char str[100];

void reverse(int c, int i, char newstr[100]) {
	if (c < 0) {
		newstr[i] = NULL;
		printf("%s", newstr);
		return;
	}
	newstr[i] = str[c];
	return reverse(c-1, i + 1, newstr);
}

int main() {
	char new_str[100];
	scanf("%s", str);
	reverse(strlen(str) - 1, 0, new_str);
	return 0;
}