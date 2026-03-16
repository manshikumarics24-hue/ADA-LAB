#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int a[],int low,int mid,int high){
    int i=low,j=mid+1,k=low;
    int temp[100000];

    while(i<=mid && j<=high){
        if(a[i]<=a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }

    while(i<=mid)
        temp[k++]=a[i++];

    while(j<=high)
        temp[k++]=a[j++];

    for(i=low;i<=high;i++)
        a[i]=temp[i];
}

void mergesort(int a[],int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

int main(){
    int n;
    int a[100000];
    clock_t start,end;

    printf("Enter no. of elements: ");
    scanf("%d",&n);

    if(n>100000){
        printf("Too many elements\n");
        return 0;
    }

    for(int i=0;i<n;i++)
        a[i]=rand()%1000;

    start=clock();
    mergesort(a,0,n-1);
    end=clock();

    double time_taken=(double)(end-start)*1000/CLOCKS_PER_SEC;

    printf("Time taken to sort %d elements = %f seconds\n",n,time_taken);

    return 0;
}