#include<stdio.h>
#define max 100;e4

int partition(int array[100],int low,int high){
    int pivot = array[low];
    int i = low ;
    int j = high;
    while(i<=j){
        while(array[i]<=pivot){
            i++;
        }
        while(array[j]>pivot){
        j--;
       }
       if(i<j){
        int temp=array[i];
        array[i]=array[j];
        array[j]=temp;
       }
       else{
        array[low]=array[j];
        array[j]=pivot;
       }
    }
    return j;
    
}

void quicksort(int array[100],int low,int high){
    if(low<high){
        int j = partition(array,low,high);
        quicksort(array,low,j-1);
        quicksort(array,j+1,high);
    }
}
int main(){
    int array[100];
    int n;
    printf("enter no of elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);

    }
    quicksort(array,0,n-1);
    printf("sorted array:");
    for(int i=0;i<n;i++){
        printf("%d\t",array[i]);
    }

}