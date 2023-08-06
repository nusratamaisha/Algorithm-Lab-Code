
#include<stdio.h>
int main(){
    int n,i,p;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("enter position");
    scanf("%d",&p);
    /*
    for(i=0;i<n;i++){
        if(i==3){
            p=i;
        }
    }
    */
    for(i=p;i<n-1;i++){
        a[i]=a[i+1];
    }
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
