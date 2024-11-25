#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100
#define INF 999

typedef struct {
    int adjMatrix[MAX][MAX];
    int num;
    int heuristic[MAX];
} Graph;

int getMinCostNode(int f[], bool visited[], int num) {
    int min = INF;
    int minIndex = -1;
    for (int i = 0; i < num; i++) {
        if (!visited[i] && f[i] < min) {
            min = f[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void printPath(int parent[], int node) {
    if (node == -1) return;
    printPath(parent, parent[node]);
    printf("%d ", node);
}

void aStarSearch(Graph *g, int start, int goal) {
    bool visited[MAX] = { false };
    int gCost[MAX];
    int fCost[MAX];
    int parent[MAX];

    for (int i = 0; i < g->num; i++) {
        gCost[i] = INF;
        fCost[i] = INF;
        parent[i] = -1;
    }

    gCost[start] = 0;
    fCost[start] = g->heuristic[start];

    printf("A* Search Traversal: ");

    while (true) {
        int current = getMinCostNode(fCost, visited, g->num);

        if (current == -1) {
            printf("\nGoal node %d not reachable.\n", goal);
            return;
        }

        printf("%d ", current);

        if (current == goal) {
            printf("\nGoal node %d reached.\n", goal);
            printf("Total cost: %d\n", gCost[goal]);
            printf("Path: ");
            printPath(parent, goal);
            printf("\n");
            return;
        }

        visited[current] = true;

        for (int i = 0; i < g->num; i++) {
            if (g->adjMatrix[current][i] < INF && !visited[i]) {
                int newCost = gCost[current] + g->adjMatrix[current][i];
                if (newCost < gCost[i]) {
                    gCost[i] = newCost;
                    fCost[i] = newCost + g->heuristic[i];
                    parent[i] = current;
                }
            }
        }
    }
}

int main() {
    Graph g;
    int i, j, edges, v1, v2, weight, start, goal;

    printf("Enter the number of vertices: ");
    scanf("%d", &g.num);

    for (i = 0; i < g.num; i++) {
        for (j = 0; j < g.num; j++) {
            g.adjMatrix[i][j] = INF;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges with weights (v1 v2 weight):\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d %d", &v1, &v2, &weight);
        g.adjMatrix[v1][v2] = weight;
    }

    printf("Enter heuristic values:\n");
    for (i = 0; i < g.num; i++) {
        printf("Heuristic value for vertex %d: ", i);
        scanf("%d", &g.heuristic[i]);
    }

    printf("Enter the start vertex: ");
    scanf("%d", &start);

    printf("Enter the goal vertex: ");
    scanf("%d", &goal);

    aStarSearch(&g, start, goal);

    return 0;
}

/*
Enter the number of vertices: 5
Enter the number of edges: 6
Enter the edges with weights (v1 v2 weight):
0 1 2
0 2 4
1 2 1
1 3 7
2 4 3
3 4 2
Enter heuristic values:
Heuristic value for vertex 0: 10
Heuristic value for vertex 1: 8
Heuristic value for vertex 2: 5
Heuristic value for vertex 3: 7
Heuristic value for vertex 4: 0
Enter the start vertex: 0
Enter the goal vertex: 4
*/