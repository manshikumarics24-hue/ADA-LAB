#include<stdio.h>

struct Item
{
    int weight;
    int profit;
    float ratio;
};

int main()
{
    int n,W;

    printf("Enter number of items: ");
    scanf("%d",&n);

    struct Item item[n];

    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&item[i].weight,
                     &item[i].profit);

        item[i].ratio=
        (float)item[i].profit/item[i].weight;
    }

    printf("Enter capacity: ");
    scanf("%d",&W);

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(item[i].ratio < item[j].ratio)
            {
                struct Item temp=item[i];
                item[i]=item[j];
                item[j]=temp;
            }
        }
    }

    float total=0;

    for(int i=0;i<n;i++)
    {
        if(W >= item[i].weight)
        {
            total+=item[i].profit;
            W-=item[i].weight;
        }
        else
        {
            total+=item[i].ratio*W;
            break;
        }
    }

    printf("Maximum Profit = %.2f",total);

    return 0;
}
