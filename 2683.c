#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int u;
    int v;
    int peso;
}Aresta;

typedef struct{
    int V,E;
    Aresta *aresta;
}Grafo;

int compararArestas(const void *a,const void *b){
    Aresta *a1 = (Aresta*)a;
    Aresta *a2 = (Aresta*)b;
    return a1->peso - a2->peso;
}
int compararArestas1(const void *a,const void *b){
    Aresta *a1 = (Aresta*)a;
    Aresta *a2 = (Aresta*)b;
    return a2->peso - a1->peso;
}

int find(int *id,int i){
    if(id[i]!=i)
        id[i] = find(id,id[i]);
    return id[i];
}
void unir(int *id,int p,int q,int *sz){
    int a = find(id,p);
    int b = find(id,q);
    if(sz[a]<sz[b]){
        id[a] = b;
    }else if(sz[a]>sz[b]){
        id[b] = a;
    }
    else{
        id[b] = a;
        sz[a]++;
    }
}
int AlgKruskal(Grafo *g,int op){
    int V,E,e=0,i,v,origem,destino,soma=0;
    V = g->V;
    E = g->E;
    Aresta prox;
    int *subconjunto = (int*)malloc(V*sizeof(int));
    int *tamanho = (int*)malloc(V*sizeof(int));
    
    if(op==1)
        qsort(g->aresta, E, sizeof(g->aresta[0]), compararArestas);
    else
        qsort(g->aresta, E, sizeof(g->aresta[0]), compararArestas1);
    for(v=0;v<V;v++){
        subconjunto[v] = v;
        tamanho[v] = 1;
    }
    
    for(i=0;i<E && e<V-1;++i){
        prox = g->aresta[i];
        origem = find(subconjunto,prox.u);
        destino = find(subconjunto,prox.v);
        if(origem!=destino){
            unir(subconjunto,origem,destino,tamanho);
            soma+=prox.peso;
            e++;
        }
    }
    free(subconjunto);
    free(tamanho);
    return soma;
}
int main(){
    int i,V,E,P,n,a,b,c,soma1=0,soma=0,maior;
        maior = 0;
        scanf("%d",&E);
        Grafo *gr = (Grafo*)malloc(sizeof(Grafo));
        gr->E = E;
        gr->aresta = (Aresta*)malloc(E*sizeof(Aresta));
        for(i=0;i<E;++i){
            scanf("%d%d%d",&a,&b,&c);
            gr->aresta[i].u = a-1;
            gr->aresta[i].v = b-1;
            gr->aresta[i].peso = c;
            if(a>maior)
                maior = a;
            if(b>maior)
                maior = b;
            soma1+=c;
        }
        V = maior;
        gr->V = V;
        soma1 = AlgKruskal(gr,2);
        soma = AlgKruskal(gr,1);
        printf("%d\n%d\n",soma1,soma);
        free(gr->aresta);
        free(gr);
    return 0;
}