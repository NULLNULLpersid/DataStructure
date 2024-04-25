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
//     NodeLink(nodelist, num, r, c, FindPossibleNumber(nodelist, num, r+1));


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
#include <stdio.h>
#include <stdlib.h>

//구조체 선언 함수
typedef struct TreeNode {
    int data;
    struct TreeNode *nodelinklist;
} TreeNode;

//한개의 노드 생성 및 초기화 함수
TreeNode *CreateNode(int data) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    return node;
}

//1차원 노드 생성
TreeNode **CreateNodeList(int num, int data) {
    TreeNode **nodelist = (TreeNode**)malloc(sizeof(TreeNode*) * num);
    for (int i = 0; i < num; i++) {
        nodelist[i] = CreateNode(data);
    }
    return nodelist;
}

//2차원 노드 생성
TreeNode ***Create2DNodeList(int num) {
    TreeNode ***nodelist = (TreeNode***)malloc(sizeof(TreeNode**) * num);
    for (int i = 0; i < num; i++) {
        nodelist[i] = CreateNodeList(num, 1);
    }
    return nodelist;
}

int FindPossibleNumber(TreeNode ***nodelist, int num, int r) {
    int count = 0;
    for (int col = 0; col < num; col++) {
        if(nodelist[r][col]->data) count++;
    }
    return count;
}

void CreateTreeNode(TreeNode ***nodelist) {

}

int main(void) {
    
    return 0;
}