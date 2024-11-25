#include <stdio.h>
#include <stdbool.h>

#define MAX 100

struct Node {
    int cost;
    bool isAndNode; 
    int children[2]; 
    int numChildren; 
};

int aoStar(int node, struct Node graph[], int n) {
   
    if (graph[node].numChildren == 0) {
        return graph[node].cost;
    }

    int minCost = 1000;  

    if (graph[node].isAndNode) {
        int cost1 = aoStar(graph[node].children[0], graph, n) + 1;
        int cost2 = aoStar(graph[node].children[1], graph, n) + 1;
        minCost = cost1 + cost2;
    } else {
        for (int i = 0; i < graph[node].numChildren; i++) {
            int cost = aoStar(graph[node].children[i], graph, n) + 1;
            if (cost < minCost) {
                minCost = cost;
            }
        }
    }
    return minCost;
}

int main() {
    struct Node graph[MAX];
    int n, startNode;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the node data (cost, isAndNode, numChildren, children):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &graph[i].cost, &graph[i].isAndNode, &graph[i].numChildren);

        for (int j = 0; j < graph[i].numChildren; j++) {
            scanf("%d", &graph[i].children[j]);
        }
    }

    printf("Enter the start node: ");
    scanf("%d", &startNode);

    int result = aoStar(startNode, graph, n);

    printf("\nTotal Cost: %d\n", result);

    return 0;
}

/*
0 0 2 1 2
2 1 2 3 4
4 0 2 5 6
1 0 0
3 0 0
2 1 2 7 8
6 0 0
2 0 0
4 0 0 */

