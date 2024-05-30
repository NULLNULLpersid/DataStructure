#include <stdio.h>

int Search(int list[], int key, int left, int right) {
    int result, mid, j;
    
    while (list[left] < key && key <= list[right]) {
        j = (size_t)(key - list[left]) / (list[right] - list[left]) * (right - left) + left;
        if (key > list[j]) left = j + 1;
        else if (key < list[j]) right = j - 1;
        else left = j;
    }
    return (list[left] == key) ? left : -1;
}

int main(void) {
    int list[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int key, result;
    
    scanf("%d", &key);
    
    result = Search(list, key, 0, sizeof(list)/sizeof(int)-1);
    
    (result != -1) ? printf("Key found at index %d", result) : printf("Key not found");
    
    return 0;
}