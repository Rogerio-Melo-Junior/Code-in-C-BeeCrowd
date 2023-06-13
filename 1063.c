#include <stdio.h>
#include <string.h>
#define max 28

int main(){
    int n,tam=0,i,topo1,topo2,k,j;
    char pilha1[max]={},pilha[max]={},aux[max]={},vagoes1[max]={},vagoes[max]={};
    while(scanf("\n%d",&n)!=EOF){
        if(n==0)
            break;
        topo1 = topo2 = n-1;
        k = -1;
        for(i=0;i<n;i++)
            scanf(" %c",&pilha1[i]);
        for(i=0;i<n;i++)
            scanf(" %c",&vagoes1[i]);
        
        for(j=0;j<n;j++){
            pilha[j] = pilha1[topo1--];
            vagoes[j] = vagoes1[topo2--];
        }
        topo1 = topo2 = n-1;
        while(1){
                 if(k!=-1 && topo2!=-1 && aux[k] == vagoes[topo2]){
                       aux[k--] = '0';
                       printf("R");
                       topo2--;
                 }else if(topo1!=-1){
                        aux[++k]=pilha[topo1];
                        printf("I");
                        topo1--;
                 }else break;                    
        }
        (k==-1) ? printf("\n") : printf(" Impossible\n");
        strcpy(pilha1,"");
        strcpy(vagoes1,"");
        strcpy(pilha,"");
        strcpy(vagoes,"");
    }
    return 0;
}