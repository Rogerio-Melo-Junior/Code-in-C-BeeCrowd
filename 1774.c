#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0

typedef int bool;
typedef int TIPOPESO;

typedef struct adjacencia{
    int vertice;
    TIPOPESO peso;
    struct adjacencia *prox;
}ADJACENCIA;

typedef struct vertice{
    ADJACENCIA *cab;
}VERTICE;

typedef struct grafo{
    int vertices;
    int arestas;
    VERTICE *adj;
}GRAFO;


typedef struct Dados{
    int u;
    int v;
    int aresta;
}Dados;

typedef struct No {
    Dados a;
    struct No *proximo;
} No;

typedef struct Lista{
    int qtd;
    No *topo;
}Lista;

Lista *criar() {
    Lista *li = (Lista*) malloc(sizeof(Lista));
    li->qtd = 0;
    li->topo = NULL;
    return li;
}

void inserir(Lista *l, Dados nod) {
    No* start = l->topo;

    No *elemento = (No*) malloc(sizeof(No));
    elemento->a = nod;

    if(l->topo == NULL){
        l->topo = elemento;
        elemento->proximo = NULL;

    }

    else if(l->topo->c.aresta < nod.aresta){
        elemento->proximo = l->topo;
        l->topo = elemento;
    }
    else {

        while (start->proximo != NULL && start->proximo->a.aresta >= pcliente.aresta) {
            start = start->proximo;
        }

        elemento->proximo = start->proximo;
        start->proximo = elemento;
    }

    l->qtd++;
}


GRAFO *criaGrafo(int v){
    int i;
    GRAFO *g = (GRAFO*)malloc(sizeof(GRAFO));
    g->vertices = v;
    g->arestas = 0;
    g->adj = (VERTICE *)malloc(v*sizeof(VERTICE));
    for(i=0;i<v;i++){
        g->adj[i].cab = NULL;
    }
    return(g);
}

ADJACENCIA *criaAdjacencia(int v,int peso){
    ADJACENCIA *temp = (ADJACENCIA*)malloc(sizeof(ADJACENCIA));
    temp->vertice = v;
    temp->peso = peso;
    temp->prox = NULL;
    return(temp);
}

bool criaAresta(GRAFO *gr, int ini,int fim,TIPOPESO peso){
    if(!gr) return false;
    if((fim<0) || fim>=gr->vertices) return false;
    if((ini<0) || ini>=gr->vertices) return false;

    ADJACENCIA *novo = criaAdjacencia(fim, peso);   
    novo->prox = gr->adj[ini].cab;
    gr->adj[ini].cab = novo;
    gr->arestas++;
    return(true);
}

void imprime(GRAFO *gr){
    int i,adj;
    for(i=0;i<gr->vertices;i++){
        printf("\n%d: ",i+1);
        ADJACENCIA *ad = gr->adj[i].cab;
            while(ad){
                printf("v%dp%d ",ad->vertice+1,ad->peso);
                ad = ad->prox;
            }
    }
}

int tam=0;

int algPrim(GRAFO *gr, int ori,int *pai){
    int i,j,dest,primeiro,menor,aux;
    int k=0,beta=0;
    Dados n;
    Lista *l;
    ADJACENCIA *ad;
    for(i=0;i<gr->vertices;i++){
        pai[i] = -1;
    }

    pai[ori] = ori;
    l = criar();
    printf("\n");
    while(1){
       for(i=0;i<gr->vertices;i++){
            if(pai[ori]!=-1){
                n.u = i;
                menor = 10000;
                   for(ad = gr->adj[ori].cab; ad ;ad = ad->prox){
                      n.v = ad->vertice;
                      n.aresta = ad->peso;
                      inserir(l,n);
                   }
                   for(j=0;j<k;j++){
                      if( menor > lista[j].aresta && pai[lista[j].v]==-1){
                        menor = lista[j].aresta;
                        aux = j;
                        ori = lista[j].v;
                      }
                   }
                   printf("%d ",lista[aux].aresta);
                   lista[aux].aresta = 10000;
                   beta++;
                   if(pai[ori]==-1)
                        tam = tam + menor;
                   pai[ori] = ori;
             }
            // printf("%d-%d ",menor,ori);
             menor = 0;
             
             if(beta==gr->vertices-1)
                return tam;
        }
    }
    return tam;
}

int main(){
    int i,qtd,arestas,v,w,peso;
    int roteadores[61];
    memset(roteadores, 0, sizeof(roteadores));
    scanf("%d%d",&qtd,&arestas);
    GRAFO *gr = criaGrafo(qtd);
    for(i=0;i<arestas;i++){
       scanf("%d%d%d",&v,&w,&peso);
        criaAresta(gr,v-1,w-1,peso);
        criaAresta(gr,w-1,v-1,peso);
    }
    imprime(gr);
    tam = algPrim(gr,0,roteadores);
    printf("\n%d \n",tam);
    return 0;
}