#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct no{
    int conteudo;
    struct no *left,*right;
}No;

typedef struct{
    No *raiz;
    int tam;
}ArvB;


void inserirLeft(No *no, int valor);

void inserirRight(No *no, int valor){
    if(no->right == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->left = NULL;
        novo->right = NULL;
        no->right = novo; 
    }
    else{
        if(valor > no->right->conteudo)
            inserirRight(no->right,valor);
        else
            inserirLeft(no->right,valor);
    }
}

void inserirLeft(No *no, int valor){
    if(no->left == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->left = NULL;
        novo->right = NULL;
        no->left = novo; 
    }
    else{
        if(valor < no->left->conteudo)
            inserirLeft(no->left,valor);
        else
            inserirRight(no->left,valor);
    }

}


void inserir(ArvB *arv, int valor){
    if(arv->raiz == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->left = NULL;
        novo->right = NULL;
        arv->raiz = novo;
    }
    else{
        if(valor < arv->raiz->conteudo)
            inserirLeft(arv->raiz,valor);
        else
            inserirRight(arv->raiz,valor);
    }
}
int tam = 0,maior = 0;

int* imprimir(No *raiz,int vet[],int qtd){
    if(raiz != NULL){
        imprimir(raiz->left,vet,qtd);
        vet[tam++] = raiz->conteudo;
        imprimir(raiz->right,vet,qtd);
        return vet;
    }
}

int* printTree(No *raiz,int level,int vet[],int qtd){
    if(raiz!=NULL){
        printTree(raiz->left,level+1,vet,qtd);
        vet[tam++] = level;
        if(level>maior)
          maior  = level;
        printTree(raiz->right,level+1,vet,qtd);
        return vet;
    }
}

void freetArv(No *raiz){
    if(raiz!=NULL){
        freetArv(raiz->left);
        freetArv(raiz->right);
        free(raiz);
    }
}

int main(){
    int casos,valor,qtd,i,j,first;
    int vet1[501],vet2[501],lvl=0,k=0;
            
    ArvB arv;
    
    scanf("%d",&casos);
    while(casos>0){
        
     arv.raiz =  NULL;
     scanf("%d",&qtd);
     
     for(i=0;i<qtd;i++){
        vet1[i] = vet2[i] = 0;
        scanf("%d",&valor);
        inserir(&arv,valor);
     }
     
     int *v1 = imprimir(arv.raiz,vet1,qtd); //conteudo
     tam = 0;
     int *v2 = printTree(arv.raiz,lvl,vet2,qtd); // level
     first = 1;
     printf("Case %d:\n",++k);
     for(i=0;i<=maior;i++){
        for(j=0;j<qtd;j++){
            if(v2[j]==i){
                if(first)
                  first = 0;
                else
                  printf(" ");
                 
                 printf("%d",v1[j]);
            }
        }
     }
        printf("\n\n");
     for(j=0;j<qtd;j++)
        v1[j] = v2[j] = 0;
     maior = tam = lvl = 0;
     freetArv(arv.raiz);
     casos--;
    }
    return 0;
}