/*#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct TreeNode {
    int element;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct {
    TreeNode **elements;
    int capacity;
    int size;
} HeapType;

// 힙 생성 함수
HeapType* create_heap(int capacity) {
    HeapType *heap = (HeapType*)malloc(sizeof(HeapType));
    heap->elements = (TreeNode**)malloc(sizeof(TreeNode*) * capacity);
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

// 힙 해제 함수
void free_heap(HeapType *heap) {
    free(heap->elements);
    free(heap);
}

// 힙에 요소 삽입 함수
void insert_min_heap(HeapType *heap, TreeNode *item) {
    int i = heap->size + 1;
    while ((i != 1) && (item->element < heap->elements[i / 2]->element)) {
        heap->elements[i] = heap->elements[i / 2];
        i /= 2;
    }
    heap->elements[i] = item;
    heap->size++;
}

// 힙에서 최소 요소 추출 함수
TreeNode* delete_min_heap(HeapType *heap) {
    int parent, child;
    TreeNode *item, *temp;

    item = heap->elements[1];
    temp = heap->elements[heap->size--];
    parent = 1;
    child = 2;
    while (child <= heap->size) {
        if ((child < heap->size) && (heap->elements[child]->element > heap->elements[child + 1]->element)) {
            child++;
        }
        if (temp->element <= heap->elements[child]->element) break;

        heap->elements[parent] = heap->elements[child];
        parent = child;
        child *= 2;
    }
    heap->elements[parent] = temp;
    return item;
}

// 트리 노드 생성 함수
TreeNode* create_node(int element) {
    TreeNode *new_node = (TreeNode*)malloc(sizeof(TreeNode));
    new_node->element = element;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// 메인 함수
int main() {
    int capacity = 10; // 힙의 최대 용량
    HeapType *heap = create_heap(capacity);

    // 트리 노드 생성 및 힙에 삽입
    TreeNode *node1 = create_node(30);
    TreeNode *node2 = create_node(10);
    TreeNode *node3 = create_node(20);

    insert_min_heap(heap, node1);
    insert_min_heap(heap, node2);
    insert_min_heap(heap, node3);

    // 힙에서 최소값 추출 및 출력
    TreeNode *min_node = delete_min_heap(heap);
    printf("The minimum element is: %d\n", min_node->element);

    // 리소스 해제
    free_heap(heap);
    free(node1);
    free(node2);
    free(node3);

    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct TreeNode {
    int weight;
    char ch;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct {
    TreeNode* ptree;
    char ch;
    int key;
} element;

typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

// Function prototypes
HeapType* create();
void init(HeapType* h);
void insert_min_heap(HeapType* h, element item);
element delete_min_heap(HeapType* h);
TreeNode* make_tree(TreeNode* left, TreeNode* right);
void destroy_tree(TreeNode* root);
int is_leaf(TreeNode* root);
void print_codes(TreeNode* node, int codes[], int top);
void huffman(char data[], int freq[], int size);

// 힙 초기화
HeapType* create() {
    HeapType *h = (HeapType*)malloc(sizeof(HeapType));
    h->heap_size = 0;
    return h;
}

void init(HeapType* h) {
    h->heap_size = 0;
}

// 최소 힙에 요소 삽입
void insert_min_heap(HeapType* h, element item) {
    int i = ++(h->heap_size);
    while ((i != 1) && (item.key < h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;
}

// 최소 힙에서 요소 삭제
element delete_min_heap(HeapType* h) {
    int parent, child;
    element item, temp;
    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while (child <= h->heap_size) {
        if ((child < h->heap_size) && (h->heap[child].key > h->heap[child + 1].key))
            child++;
        if (temp.key <= h->heap[child].key) break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

// 트리 노드 생성
TreeNode* make_tree(TreeNode* left, TreeNode* right) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->left = left;
    node->right = right;
    if (left && right) {
        node->weight = left->weight + right->weight;
    } else {
        node->weight = 0;
    }
    return node;
}

// 트리 해제
void destroy_tree(TreeNode* root) {
    if (root == NULL) return;
    destroy_tree(root->left);
    destroy_tree(root->right);
    free(root);
}

// 리프 노드 확인
int is_leaf(TreeNode* root) {
    return !(root->left) && !(root->right);
}

// 코드 출력
void print_codes(TreeNode* node, int codes[], int top) {
    if (node->left) {
        codes[top] = 0;
        print_codes(node->left, codes, top + 1);
    }
    if (node->right) {
        codes[top] = 1;
        print_codes(node->right, codes, top + 1);
    }
    if (is_leaf(node)) {
        printf("%c: ", node->ch);
        for (int i = 0; i < top; i++) {
            printf("%d", codes[i]);
        }
        printf("\n");
    }
}

// 허프만 코딩 구현
void huffman(char data[], int freq[], int size) {
    HeapType* heap = create();
    init(heap);

    for (int i = 0; i < size; i++) {
        TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
        node->ch = data[i];
        node->weight = freq[i];
        node->left = NULL;
        node->right = NULL;
        element e;
        e.ptree = node;
        e.ch = data[i];
        e.key = freq[i];
        insert_min_heap(heap, e);
    }

    for (int i = 1; i < size; i++) {
        element e1 = delete_min_heap(heap);
        element e2 = delete_min_heap(heap);
        TreeNode* node = make_tree(e1.ptree, e2.ptree);
        element e;
        e.ptree = node;
        e.key = node->weight;
        insert_min_heap(heap, e);
    }

    element e = delete_min_heap(heap);
    TreeNode* root = e.ptree;
    int codes[MAX_ELEMENT];
    print_codes(root, codes, 0);
    destroy_tree(root);
    free(heap);
}

int main() {
    char arr1[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq1[] = {5, 9, 12, 13, 16, 45};

    char arr2[] = {'g', 'h', 'i', 'j'};
    int freq2[] = {3, 7, 10, 14};

    char arr3[] = {'k', 'l', 'm', 'n', 'o'};
    int freq3[] = {1, 4, 5, 6, 8};

    printf("Test Case 1:\n");
    huffman(arr1, freq1, sizeof(arr1) / sizeof(arr1[0]));
    printf("\nTest Case 2:\n");
    huffman(arr2, freq2, sizeof(arr2) / sizeof(arr2[0]));
    printf("\nTest Case 3:\n");
    huffman(arr3, freq3, sizeof(arr3) / sizeof(arr3[0]));

    return 0;
}