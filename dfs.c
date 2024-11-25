#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int items[MAX_VERTICES];
    int top;
} Stack;

typedef struct {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int num;
} Graph;


void init(Stack *st) {
    st->top = -1;
}

bool isStackEmpty(Stack *st) {
    return st->top ==-1;
}

void push(Stack *st, int item) {
    if (st->top < MAX_VERTICES - 1) {
        st->items[++st->top] = item;
    }
}

int pop(Stack *st) {
    if (!isStackEmpty(st)) {
        return st->items[st->top--];
    }
    return -1; 
}

void dfs(Graph *g, int startVertex) {
    Stack st;
    bool visited[MAX_VERTICES] = {false};
    int i;

    init(&st);
    push(&st, startVertex);
    visited[startVertex] = true;

    printf("DFS Traversal: ");

    while (!isStackEmpty(&st)) {
        int currentVertex = pop(&st);
        printf("%d ", currentVertex);

        for (i = 0; i < g->num; i++) {
            if (g->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                push(&st, i);
                visited[i] = true;
            }
        }
    }

    printf("\n");
}

int main() {
    Graph g;
    int i, j, edges, v1, v2,st;

    printf("Enter the number of vertices: ");
    scanf("%d", &g.num);

    for (i = 0; i < g.num; i++) {
        for (j = 0; j < g.num; j++) {
            g.adjMatrix[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (v1 v2):\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &v1, &v2);
        g.adjMatrix[v1][v2] = 1;
        g.adjMatrix[v2][v1] = 1;
    }

     printf("Graph (Adjacency Matrix):\n");
    for (int i = 0; i < g.num; i++) {
        for (int j = 0; j < g.num; j++) {
            printf("%d ", g.adjMatrix[i][j]);
        }
        printf("\n");
    }

    printf("Enter the start vertex: ");
    scanf("%d", &st);

    dfs(&g,st);
    return 0;
}