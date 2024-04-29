/*
n-Qneen 문제 풀기

n * n 리스트를 생성한뒤 True값 부여
n번 반복됨 (행)
    n-1번 반복됨 (열)
        이후 n*n번 반복하면서 곂치는 부분은 False값 부여
        False인 부분은 n*n이 실행 안됨
*/

// #include <stdio.h>
// #include <stdlib.h>

// //구조체 선언 함수
// typedef struct TreeNode {
//     int data;
//     struct TreeNode *nodelinklist;
// } TreeNode;

// //한개의 노드 생성 및 초기화 함수
// TreeNode *CreateNode(int data) {
//     TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
//     node->data = data;
//     return node;
// }
// //1차원 노드 생성
// TreeNode **CreateNodeList(int num, int data) {
//     TreeNode **nodelist = (TreeNode**)malloc(sizeof(TreeNode*) * num);
//     for (int i = 0; i < num; i++) {
//         nodelist[i] = CreateNode(data);
//     }
//     return nodelist;
// }
// //2차원 노드 생성
// TreeNode ***Create2DNodeList(int num) {
//     TreeNode ***nodelist = (TreeNode***)malloc(sizeof(TreeNode**) * num);
//     for (int i = 0; i < num; i++) {
//         nodelist[i] = CreateNodeList(num, 1);
//     }
//     return nodelist;
// }

// void NodeInit(TreeNode ***nodelist, int num) {
//     for (int row = 0; row < num; row++) {
//         for (int col = 0; col < num; col++) {
//             nodelist[row][col]->data = 1;
//         }
//     }
// }

// void DataChange(TreeNode ***nodelist, int num, int r, int c) {
//     for (int row = r; row < num; row++) {
//         for (int col = 0; col < num; col++) {
//             //행의 경우
//             if (r == row) {
//                 nodelist[r][col]->data = 0;
//             }
//             //열의 경우
//             if (c == col) {
//                 nodelist[row][c]->data = 0;
//             }
//             //오른쪽 아래의 경우
//             if (c+row < num) {
//                 nodelist[r+row][c+row]->data = 0;
//             }
//             //왼쪽 아래의 경우
//             if (0 <= c+r-row) {
//                 nodelist[row][c+r-row]->data = 0;
//             }
//         }
//     }
// }

// void print(TreeNode ***nodelist, int num) {
//     for (int row = 0; row < num; row++) {
//         for (int col = 0; col < num; col++) {
//             //printf("%p : %d, ", nodelist[row][col], nodelist[row][col]->data);
//             printf("%d, ", nodelist[row][col]->data);
//         }
//         printf("\n");
//     }
// }

// int FindPossibleNumber(TreeNode ***nodelist, int num, int r) {
//     int count = 0;
//     for (int row = r; row < num; row++) {
//         for (int col = 0; col < num; col++) {
//             if(nodelist[row][col]->data) count++;
//         }
//     }
//     return count;
// }

// TreeNode *CreateTreeNode(int num, int data) {
//     TreeNode *node = CreateNode(data);
//     node->nodelinklist = (TreeNode*)malloc(sizeof(TreeNode));

// }

// int FindCaseNumber(TreeNode*** nodelist, int num, int r, int c){
//     DataChange(nodelist, num, r, c);
//     //NodeLink(nodelist, num, r, c, FindPossibleNumber(nodelist, num, r+1));

//     int count = 0;
//     for (int row = 0; row < num; row++) {
//         for (int col = 0; col < num; col++) {
//             if (nodelist[row][col]->data) {
//                 DataChange(nodelist, num, row, col);
//                 print(nodelist, num);
//                 printf("\n");
//                 count++;
//             }
//         }
//     }
//     printf("%d", count);
// }

// int FindPossibleCaseNumber(TreeNode*** nodelist, int num) {
//     int count = 0;
//     for (int i = 0; i < num; i++) {
//         if (FindCaseNumber(nodelist, num, 0, i) == num) count++;
//     }

//     return count;
// }

// int main(void) {
//     int num;
//     scanf("%d", &num);
//     //TreeNode ***nodelist = Create2DNodeList(num);
//     printf("%d", FindPossibleCaseNumber(Create2DNodeList(num), num));

//     return 0;
// }
// #include <stdio.h>
// #include <stdlib.h>

// //구조체 선언 함수
// typedef struct TreeNode {
//     int data;
//     struct TreeNode *nodelinklist;
// } TreeNode;

// //한개의 노드 생성 및 초기화 함수
// TreeNode *CreateNode(int data) {
//     TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
//     node->data = data;
//     return node;
// }
// //1차원 노드 생성
// TreeNode **CreateNodeList(int num, int data) {
//     TreeNode **nodelist = (TreeNode**)malloc(sizeof(TreeNode*) * num);
//     for (int i = 0; i < num; i++) {
//         nodelist[i] = CreateNode(data);
//     }
//     return nodelist;
// }
// //2차원 노드 생성
// TreeNode ***Create2DNodeList(int num) {
//     TreeNode ***nodelist = (TreeNode***)malloc(sizeof(TreeNode**) * num);
//     for (int i = 0; i < num; i++) {
//         nodelist[i] = CreateNodeList(num, 1);
//     }
//     return nodelist;
// }

// void NodeInit(TreeNode ***nodelist, int num) {
//     for (int row = 0; row < num; row++) {
//         for (int col = 0; col < num; col++) {
//             nodelist[row][col]->data = 1;
//         }
//     }
// }

// void DataChange(TreeNode ***nodelist, int num, int r, int c) {
//     for (int row = r; row < num; row++) {
//         for (int col = 0; col < num; col++) {
//             //행의 경우
//             if (r == row) {
//                 nodelist[r][col]->data = 0;
//             }
//             //열의 경우
//             if (c == col) {
//                 nodelist[row][c]->data = 0;
//             }
//             //오른쪽 아래의 경우
//             if (c+row < num) {
//                 nodelist[r+row][c+row]->data = 0;
//             }
//             //왼쪽 아래의 경우
//             if (0 <= c+r-row) {
//                 nodelist[row][c+r-row]->data = 0;
//             }
//         }
//     }
// }

// void print(TreeNode ***nodelist, int num) {
//     for (int row = 0; row < num; row++) {
//         for (int col = 0; col < num; col++) {
//             //printf("%p : %d, ", nodelist[row][col], nodelist[row][col]->data);
//             printf("%d, ", nodelist[row][col]->data);
//         }
//         printf("\n");
//     }
// }

// int FindPossibleNumber(TreeNode ***nodelist, int num, int r) {
//     int count = 0;
//     for (int row = r; row < num; row++) {
//         for (int col = 0; col < num; col++) {
//             if(nodelist[row][col]->data) count++;
//         }
//     }
//     return count;
// }

// TreeNode *CreateTreeNode(int num, int data) {
//     TreeNode *node = CreateNode(data);
//     node->nodelinklist = (TreeNode*)malloc(sizeof(TreeNode));

// }

// int FindCaseNumber(TreeNode*** nodelist, int num, int r, int c){
//     DataChange(nodelist, num, r, c);
//     print(nodelist, num);
// }

// int FindPossibleCaseNumber(TreeNode*** nodelist, int num) {
// }

// int main(void) {
//     int num;
//     scanf("%d", &num);
//     TreeNode ***nodelist = Create2DNodeList(num);
//     for (int i = 0; i < num; i++) {
//         FindCaseNumber(nodelist, num, 0, i);
//         printf("\n");
//         NodeInit(nodelist, num);
//     }
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

//구조체 선언 함수
typedef struct TreeNode{
    size_t data;
    struct TreeNode **nodelinklist;
} TreeNode;

//노드 생성 함수
TreeNode *CreateNode(size_t data, size_t len) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    if (len > 0) {
        node->nodelinklist = (TreeNode**)malloc(sizeof(TreeNode*) * len);
    }
    else {
        node->nodelinklist = NULL;
    }
    return node;
}

//2차원 배열 생성
size_t **Create2DArr(size_t num) {
    size_t **arr2d = (size_t**)malloc(sizeof(size_t*) * num);
    for (size_t row = 0; row < num; row++) {
        arr2d[row] = (size_t*)malloc(sizeof(size_t) * num);
        for (size_t col = 0; col < num; col++) {
            arr2d[row][col] = 1;
        }
    }
    return arr2d;
}

void NodeInit(size_t **arr2d, size_t num) {
    for (size_t row = 0; row < num; row++) {
        for (size_t col = 0; col < num; col++) {
            arr2d[row][col] = 1;
        }
    }
}

void DataChange(size_t **arr2d, size_t num, size_t r, size_t c) {
    for (size_t row = r; row < num; row++) {
        for (size_t col = 0; col < num; col++) {
            //행의 경우
            if (r == row) {
                arr2d[r][col] = 0;
            }
            //열의 경우
            if (c == col) {
                arr2d[row][c] = 0;
            }
            //오른쪽 아래의 경우
            if (c+row < num) {
                arr2d[r+row][c+row] = 0;
            }
            //왼쪽 아래의 경우
            if (0 <= c+r-row) {
                arr2d[row][c+r-row] = 0;
            }
        }
    }
}
size_t FindNodeLen(size_t **arr2d, size_t num, size_t row) {
    size_t count = 0;
    for (size_t col = 0; col < num; col++) {
        if (arr2d[row][col]) count++;
    }
    return count;
}

void print(size_t **arr2d, size_t num) {
    for(size_t row = 0; row < num; row++) {
        for (size_t col = 0; col < num; col++) {
            printf("%d ", arr2d[row][col]);
        }
        printf("\n");
    }
}
void CreateTreeNode(TreeNode *root, size_t **arr2d, size_t num, size_t len, size_t row) {
    size_t col = 0;
    if (root != NULL) {
        while(col < len) {
            DataChange(arr2d, len, row, col);
            root->nodelinklist[col] = CreateNode(col, FindNodeLen(arr2d, num, ++row));
            col += 1;
        }
    }
}

size_t Count(TreeNode *root, size_t len, size_t num, size_t deep, size_t count) {
    if (root != NULL) {
        for (size_t col = 0; col < len; col++) {
            Count(root->nodelinklist[col], sizeof(root->nodelinklist)/sizeof(TreeNode), num, deep, count);
        }
    }
    else {
        if (deep == num) {
            count += 1;
        }
        else {
            deep = 0;
        }
    }

    return count;
}

int main(void) {
    size_t num, len;
    scanf("%d", &num);
    size_t **arr2d = Create2DArr(num);
    TreeNode *root = CreateNode(0, len);
    CreateTreeNode(root, arr2d, num, FindNodeLen(arr2d, num, 0), 1);
    //printf("%d", Count(root, FindNodeLen(arr2d, num, 0), num, 0, 0));
    return 0;
}