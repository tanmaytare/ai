#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 100

typedef struct 
{
    int adj[MAX][MAX];
    int num;
}Graph;

typedef struct 
{
    int queue[MAX];
    int front,rear;
}Queue;

void init(Queue *q)
{
    q->front = 0;
    q->rear = -1;
}

bool isEmpty(Queue *q)
{
    return q->front > q->rear;
}

void enqueue(Queue *q,int n)
{
    if(q->rear < MAX-1)
    {
        q->queue[++q->rear] = n;
    }
}

int dequeue(Queue *q) {
    if (!isEmpty(q)) {
        return q->queue[q->front++];
    }
    return -1; 
}

void bfs(Graph *g)
{
    Queue q;
    init(&q);
    int st;
    bool isVisited[MAX] = {false};

    printf("Enter start vertex:");
    scanf("%d",&st);

    enqueue(&q,st);
    isVisited[st] = true;

    while(!isEmpty(&q))
    {
        int cur = dequeue(&q);
        printf("%d",cur);

        for(int i=0;i < g->num ; i++)
        {
            if(g->adj[cur][i]==1 && !isVisited[i])
            {
                enqueue(&q,i);
                isVisited[i] = true;
            }
        }
    }

}

int main()
{
    Graph g;

    int edges,v1,v2;
    printf("Enter No. of vertex:");
    scanf("%d",& g.num);

    for(int i=0;i<g.num;i++)
    {
        for(int j=0;j<g.num;j++)
        {
            g.adj[i][j] = 0;
        }
    }

    
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (v1 v2):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &v1, &v2);
        g.adj[v1][v2] = 1;
        g.adj[v2][v1] = 1;
    }

    bfs(&g);
}