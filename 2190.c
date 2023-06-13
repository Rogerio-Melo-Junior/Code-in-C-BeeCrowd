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
int compararVertice(const void *a,const void *b){
    Aresta *a1 = (Aresta*)a;
    Aresta *a2 = (Aresta*)b;
    return a1->u - a2->u;
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
void AlgKruskal(Grafo *g,int teste){
    int V,E,e=0,i,v,origem,destino;
    V = g->V;
    E = g->E;
    Aresta prox;
    Aresta *res = (Aresta*)malloc(E*sizeof(Aresta));
    int *subconjunto = (int*)malloc(V*sizeof(int));
    int *tamanho = (int*)malloc(V*sizeof(int));
    qsort(g->aresta, E, sizeof(g->aresta[0]), compararArestas);
    for(v=0;v<V;v++){
        subconjunto[v] = v;
        tamanho[v] = 1;
    }
    
    for(i=0;i<E && e<V-1;++i){
        prox = g->aresta[i];
        origem = find(subconjunto,prox.u);
        destino = find(subconjunto,prox.v);
        if(origem!=destino){
            res[e] = prox;
            if(prox.u>prox.v){
                res[e].u = prox.v;
                res[e].v = prox.u;
            }
            unir(subconjunto,origem,destino,tamanho);
            e++;
        }
    }
    qsort(res, e, sizeof(res[0]),compararVertice);
    printf("Teste %d\n",teste);
    for(i=0;i<e;i++){
        printf("%d %d\n",res[i].u+1,res[i].v+1);
    }
    free(subconjunto);
    free(tamanho);
}
int main(){
    int i,V,E,P,n,a,b,c,teste=1;
        while(scanf("%d%d",&V,&E)!=EOF){
            
            if(V==0 && E==0)
                return 0;
            Grafo *gr = (Grafo*)malloc(sizeof(Grafo));
            gr->E = E;
            gr->V = V;
            gr->aresta = (Aresta*)malloc(E*sizeof(Aresta));
            for(i=0;i<E;++i){
                scanf("%d%d%d",&a,&b,&c);
                gr->aresta[i].u = a-1;
                gr->aresta[i].v = b-1;
                gr->aresta[i].peso = c;
            }
            AlgKruskal(gr,teste);
            teste++;
            free(gr->aresta);
            free(gr);
           }
    return 0;
}