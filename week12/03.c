#include <stdio.h>
#include <stdlib.h>

int *MakeArr(int n) {
    int *arr = (int *)malloc(sizeof(int) * n);

    // n개의 수 입력 받음
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    return arr;
}

void SortArr(int arr[], int n) {
    int t;

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] < arr[j]) {
                t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
}

int *DrawArr(int arr[], int n, int k) {
    int *result = (int *)malloc(sizeof(int) * k);

    // 정렬
    SortArr(arr, n);

    for (int i = 0; i < k; i++) {
        if (i < n) result[i] = arr[i];
        else result[i] = arr[0];
    }

    free(arr);

    return result;
}

int main(void) {
    int n, k;
    
    scanf("%d %d", &n, &k);

    // 숫자 뽑기
    int *drawArr = DrawArr(MakeArr(n), n, k);
    SortArr(drawArr, k);
    for (int i = 0; i < k; i++) printf("%d", drawArr[i]);


    free(drawArr);

    return 0;
}