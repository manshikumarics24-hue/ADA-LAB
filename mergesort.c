#include<stdio.h>
#define max 100

void merge(int array[max],int low,int high,int mid){
int temp[max];

int i=low;
int j=mid+1;
int k=low;
while(i<j&&j<=high){
if(array[i]<array[j]){
temp[k]=array[i];
i++;
}else{
    temp[k]=array[j];
     j++;
}
k++;
}

while(i<=mid){
    temp[k]=array[i];
    i++;
    k++;
}while(j<=high)
{
    temp[k]=array[j];
    j++;
    k++;

}for(int i=low;i<=high;i++){
    array[i]=temp[i];
}
}

void mergesort(int array[max],int low,int high){
    if(low<high){
    int mid=(low+high)/2;
     mergesort(array,low,mid);
     mergesort(array,mid+1,high);
     merge(array,low,high,mid);
}
}



int main(){
    int array[max];
     int n;
    
    printf("enter number:");
    scanf("%d",&n);
    array[n];
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    mergesort(array,0,n-1);
    printf("sorted arrray:");
    for(int i=0;i<n;i++){
      printf("%d\t",array[i]);
    }
    
}
