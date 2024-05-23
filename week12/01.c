#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, k, t, i, j;
    
    scanf("%d %d", &n, &k);
    
    int *arr = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            if (arr[i] > arr[j]) {
                t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
    printf("%d", arr[k-1]);
    return 0;
}