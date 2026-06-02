#include<stdio.h>
#define max 100
#define left -1
#define right 1
void printpermutation(int n,int p[]){
    for(int i = 0; i< n; i++){
        printf("%d",p[i]);
    }
    printf("\n");
}





int findpos(int p[],int n,int mobile){
    for(int i=0;i<n;i++){
      if(p[i]==mobile){
        return i;
      }
    }
    return -1;
}





int getmobile(int p[],int d[],int n){
    int mobile=0;
    for(int i=0;i<n;i++){
    if(d[p[i]]==left&&i!=0){
        if(p[i]>p[i-1]&&p[i]>mobile){
            mobile=p[i];
        }
    }
      if(d[p[i]]==right&&i!=n-1){
        if(p[i]>p[i+1]&&p[i]>mobile){
            mobile=p[i];
        }
    }}
    return mobile;

}





void johnson(int n,int p[20],int d[max]){
for(int i=0;i<n;i++){
    p[i]=i+1;}
    for(int i = 1; i <= n; i++){
      d[i]=left;
}
printpermutation(n,p);
while(1){
int mobile=getmobile(p,d,n);
if(mobile==0){
    break;
}
int pos=findpos(p,n,mobile);
if(d[mobile]==left){
    int temp=p[pos];
    p[pos]=p[pos-1];
    p[pos-1]=temp;
    pos=pos-1;
}else{
    int temp=p[pos];
    p[pos]=p[pos+1];
    p[pos+1]=temp;
    pos=pos+1;
}
for(int i=1;i<=n;i++){
    if(i>mobile){
        d[i]=d[i]*-1;
    }
}
printpermutation(n,p);
}
}





int main(){
    int p[20], d[20];
    int n;
    printf("enter number:");
    scanf("%d",&n);
    johnson(n,p,d);
    return 0;

}