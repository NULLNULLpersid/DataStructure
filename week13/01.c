#include <stdio.h>

int Search(int list[], int key, int left, int right) {
    int result, mid;
    
    while (left <= right) {
        mid = (left + right) / 2;
        if (key == list[mid]) return mid;
        else if (key > list[mid]) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main(void) {
    int list[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int key, result;
    
    scanf("%d", &key);
    
    result = Search(list, key, 0, sizeof(list) / sizeof(int));
    
    (result != -1) ? printf("Key found at index %d", result) : printf("Key not found");
    
    return 0;
}