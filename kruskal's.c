#include<stdio.h>

#define MAX 100
#define INF 9999

int parent[MAX];

int find(int i)
{
    while(parent[i])
        i=parent[i];

    return i;
}

void uni(int i,int j)
{
    parent[j]=i;
}

int main()
{
    int n;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    int cost[MAX][MAX];

    printf("Enter cost matrix:\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%d",&cost[i][j]);
    }

    int mincost=0,edges=0;

    while(edges < n-1)
    {
        int min=INF,a=-1,b=-1;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(cost[i][j] < min)
                {
                    min=cost[i][j];
                    a=i;
                    b=j;
                }
            }
        }

        int u=find(a);
        int v=find(b);

        if(u!=v)
        {
            printf("%d -> %d = %d\n",a,b,min);

            mincost+=min;

            uni(u,v);

            edges++;
        }

        cost[a][b]=cost[b][a]=INF;
    }

    printf("Minimum Cost = %d",mincost);

    return 0;
}