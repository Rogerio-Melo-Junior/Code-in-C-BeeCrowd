#include <stdio.h>
#include <string.h>

struct carne{
    char nome[21];
    int validade;
};

typedef struct carne Carne;

int main(){
    int n,i=0,j=0,k=0,menor;
    char aux[11];
    Carne peca[11];
    while(scanf("%d",&n)!=EOF){
        while(i<n){
            scanf("%s%d",peca[i].nome,&peca[i].validade);    
            i++;
        }
        for(i=0;i<n;i++){
            menor = peca[i].validade;
            strcpy(aux,peca[i].nome);
            for(j=i+1;j<n;j++){
                if(peca[i].validade>peca[j].validade){
                    menor = peca[i].validade;
                    peca[i].validade = peca[j].validade;
                    peca[j].validade = menor;
                    strcpy(aux,peca[i].nome);
                    strcpy(peca[i].nome,peca[j].nome);
                    strcpy(peca[j].nome,aux);
                }
            }
        }
        for(i=0;i<n;i++){
            if(i!=n-1)
             printf("%s ",peca[i].nome);
            else
             printf("%s\n",peca[i].nome);
        }
        i=0;
    }
    return 0;
}