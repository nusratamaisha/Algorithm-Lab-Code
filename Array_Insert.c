#include<stdio.h>
int main(){
    int n,i,p;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        if(i==3){
            p=i;
        }
    }
    for(i=n;i>p;i--){
        a[i]=a[i-1];
    }
    a[p]=10;
    for(i=0;i<=n;i++){
        printf("%d ",a[i]);
    }
}
