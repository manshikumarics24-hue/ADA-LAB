#include<stdio.h>

#define INF 9999

int main()
{
    int n;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    int graph[n][n];

    printf("Enter adjacency matrix:\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%d",&graph[i][j]);
    }

    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(graph[i][k] + graph[k][j] < graph[i][j])
                    graph[i][j]=graph[i][k]+graph[k][j];
            }
        }
    }

    printf("Shortest Path Matrix:\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",graph[i][j]);

        printf("\n");
    }

    return 0;
}