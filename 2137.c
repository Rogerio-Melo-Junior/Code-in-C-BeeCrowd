#include <stdio.h>
#include <string.h>

struct l{
    char liv[5];
};

typedef struct l Livro;

void merge(Livro *li,int ini,int m,int f){
    int i=ini,j=m+1;
    int k=0;
    int lim_left=m,lim_right=f;
    Livro aux[1002];
    while(i<=lim_left && j<=lim_right){
        if(strcmp(li[i].liv,li[j].liv)<=0)
            strcpy(aux[k++].liv,li[i++].liv);
        else
            strcpy(aux[k++].liv,li[j++].liv);
    }
    while(i<=lim_left){
          strcpy(aux[k++].liv,li[i++].liv);
    }
    while(j<=lim_right){
          strcpy(aux[k++].liv,li[j++].liv);
    }
    for(k = ini;k<=f;k++)
        li[k] = aux[k-ini];
}

void mergesort(Livro *li,int l,int r){
    int m;
    if(l<r){
        m = (l+r)/2;
        mergesort(li,l,m);
        mergesort(li,m+1,r);
        merge(li,l,m,r);
    }
}
int main(){
    int n,i=0;
    Livro livro[1002];
    while(scanf("\n%d",&n)!=EOF){
        i=0;
        while(i<n){
            scanf(" %s",livro[i].liv);
            i++;
        }
        mergesort(livro,0,n-1);
        i=0;
        while(i<n){
            printf("%s\n",livro[i].liv);
            strcpy(livro[i].liv,"");
            i++;
        }
    }
    return 0;
}