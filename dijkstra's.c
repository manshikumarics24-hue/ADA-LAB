#include<stdio.h>

#define INF 9999

int main()
{
    int n;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    int cost[n][n];

    printf("Enter matrix:\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%d",&cost[i][j]);
    }

    int source;

    printf("Enter source vertex: ");
    scanf("%d",&source);

    int dist[n],visited[n];

    for(int i=0;i<n;i++)
    {
        dist[i]=cost[source][i];
        visited[i]=0;
    }

    visited[source]=1;
    dist[source]=0;

    for(int count=1;count<n-1;count++)
    {
        int min=INF,next;

        for(int i=0;i<n;i++)
        {
            if(!visited[i] && dist[i]<min)
            {
                min=dist[i];
                next=i;
            }
        }

        visited[next]=1;

        for(int i=0;i<n;i++)
        {
            if(!visited[i] &&
            min+cost[next][i] < dist[i])
            {
                dist[i]=min+cost[next][i];
            }
        }
    }

    printf("Shortest distances:\n");

    for(int i=0;i<n;i++)
        printf("%d -> %d\n",i,dist[i]);

    return 0;
}