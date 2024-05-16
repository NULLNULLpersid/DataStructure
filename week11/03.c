#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int stack[MAX_VERTICES];
    int top;
} StackType;

typedef struct GraphNode {
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
    int n;
    GraphNode* adj_list[MAX_VERTICES];
} GraphType;

void init_stack(StackType* s) {
    s->top = -1;
}

int is_empty(StackType* s) {
    return s->top == -1;
}

int is_full(StackType* s) {
    return s->top == (MAX_VERTICES - 1);
}

void push(StackType* s, int item) {
    if (is_full(s)) {
        fprintf(stderr, "Stack is full\n");
        exit(1);
    } else {
        s->stack[++(s->top)] = item;
    }
}

int pop(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "Stack is empty\n");
        exit(1);
    } else {
        return s->stack[(s->top)--];
    }
}

void graph_init(GraphType* g) {
    g->n = 0;
    for (int i = 0; i < MAX_VERTICES; i++) {
        g->adj_list[i] = NULL;
    }
}

void insert_vertex(GraphType* g, int v) {
    if (((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "Graph: number of vertices exceeds limit\n");
        return;
    }
    g->n++;
}

void insert_edge(GraphType* g, int u, int v) {
    GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        return;
    }
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

int topo_sort(GraphType* g) {
    int i;
    StackType s;
    GraphNode* node;
    
    int* in_degree = (int*)malloc(g->n * sizeof(int));
    if (in_degree == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        return 0;
    }
    for (i = 0; i < g->n; i++) {
        in_degree[i] = 0;
    }
    for (i = 0; i < g->n; i++) {
        node = g->adj_list[i]; 
        while (node != NULL) {
            in_degree[node->vertex]++;
            node = node->link;
        }
    }

    init_stack(&s);
    for (i = 0; i < g->n; i++) {
        if (in_degree[i] == 0) {
            push(&s, i);
        }
    }

    while (!is_empty(&s)) {
        int w = pop(&s);
        printf("Á¤Á¡ %d ->", w);
        node = g->adj_list[w];
        while (node != NULL) {
            int u = node->vertex;
            in_degree[u]--;
            if (in_degree[u] == 0) {
                push(&s, u);
            }
            node = node->link;
        }
    }
    free(in_degree);
    printf("\n");
    return 1;
}

int main(void) {
    GraphType g;
    graph_init(&g);
    
    insert_vertex(&g, 0); insert_vertex(&g, 1);
    insert_vertex(&g, 2); insert_vertex(&g, 3);
    insert_vertex(&g, 4); insert_vertex(&g, 5);
    
    insert_edge(&g, 0, 2); insert_edge(&g, 0, 3);
    insert_edge(&g, 1, 3); insert_edge(&g, 1, 4);
    insert_edge(&g, 2, 3); insert_edge(&g, 2, 5);
    insert_edge(&g, 3, 5); insert_edge(&g, 4, 5);
    

    topo_sort(&g);
    
    return 0;
}