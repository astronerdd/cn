
#include <stdio.h>

#define MAX 10

int main()
{
    int graph[MAX][MAX], visited[MAX] = {0};
    int queue[MAX], parent[MAX];
    int n, source, i, j, front = 0, rear = 0, u, v;

    printf("Enter number of hosts: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 or 1):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source host (0 to %d): ", n - 1);
    scanf("%d", &source);

    for (i = 0; i < n; i++)
        parent[i] = -1;

    visited[source] = 1;
    queue[rear++] = source;

    printf("\nBroadcast Tree Edges:\n");

    while (front < rear)
    {
        u = queue[front++];

        for (v = 0; v < n; v++)
        {
            if (graph[u][v] && !visited[v])
            {
                visited[v] = 1;
                parent[v] = u;
                queue[rear++] = v;

                printf("%d -> %d\n", u, v);
            }
        }
    }

    printf("\nBroadcast completed.\n");

    return 0;
}
