#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *element;  // 요소 배열
    int now_size; // 현재 힙의 크기
    int max_size;  // 최대 용량
} HeapType;

// 힙 생성
HeapType* create_heap(int max_size) {
    HeapType *heap = (HeapType*)malloc(sizeof(HeapType));
    heap->element = (int*)malloc(sizeof(int) * max_size);
    heap->now_size = 0;
    heap->max_size = max_size;
    return heap;
}

// 힙 메모리 해제
void free_heap(HeapType *heap) {
    free(heap->element);
    free(heap);
}

// 요소 삽입
void insert_max_heap(HeapType *heap, int item) {
    int i = ++heap->now_size;
    while ((i != 1) && (item > heap->element[i / 2])) {
        heap->element[i] = heap->element[i / 2];
        i /= 2;
    }
    heap->element[i] = item;
}

// 최대 요소 삭제
int delete_max_heap(HeapType *heap) {
    int parent, child;
    int item, temp;

    item = heap->element[1];
    temp = heap->element[heap->now_size--];
    parent = 1;
    child = 2;

    while (child <= heap->now_size) {
        if ((child < heap->now_size) && (heap->element[child] < heap->element[child + 1])) child++;
        if (temp >= heap->element[child]) break;

        heap->element[parent] = heap->element[child];
        parent = child;
        child *= 2;
    }

    heap->element[parent] = temp;
    return item;
}

int main() {
    int max_size = 10; // 최대 용량
    HeapType *heap = create_heap(max_size);

    // 힙에 요소 삽입
    insert_max_heap(heap, 99);
    insert_max_heap(heap, 56);
    insert_max_heap(heap, 56);
    insert_max_heap(heap, 34);
    insert_max_heap(heap, 27);
    insert_max_heap(heap, 23);
    insert_max_heap(heap, 11);
    insert_max_heap(heap, 9);

    // 힙에서 최대값 삭제
    for (int i = 0; i < 8; i++) printf("%d ", delete_max_heap(heap));

    free_heap(heap);
    return 0;
}