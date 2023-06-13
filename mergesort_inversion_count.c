#include <stdio.h>
#include <string.h>
#define max 101

int merge(int *v,int i,int m,int f){
    int k=0,inv=0;
    int c1=i,c2=m+1;
    int Aux[max];
    while(c1<=m && c2<=f){
        if(v[c1]<=v[c2]){
            Aux[k++] = v[c1++];
        }
        else{
            Aux[k++] = v[c2++];
            inv+=(m+1-c1);
        }
    }
    while(c1<=m){
        Aux[k++] = v[c1++];
    }
    while(c2<=f){
        Aux[k++] = v[c2++];
    }
    for(k=i;k<=f;k++)
        v[k] = Aux[k-i];
        
    return inv;
}
int mergesort(int *v,int i,int f){
    int m,inv=0;;
    if(i<f){
        m = (i+f)/2;
        inv = mergesort(v,i,m);
        inv += mergesort(v,m+1,f);
        inv += merge(v,i,m,f);
    }
    return inv;
}
int main(){
    int i,vet[max],n;
    while(scanf("%d",&n)!=EOF){
        if(n==0)
         return 0;
        for(i=0;i<n;i++){
            scanf("%d",&vet[i]);
        }
        (mergesort(vet,0,n-1)%2==0) ? printf("Carlos\n"):printf("Marcelo\n");
    }
    return 0;
}