#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int orig, dest, peso;
}Aresta;


typedef struct {
    int V, E;
    Aresta* arestas;
}Grafo;


int compararArestas(const void *a, const void *b) {
    Aresta* a1 = (Aresta*)a;
    Aresta* a2 = (Aresta*)b;
    return a1->peso - a2->peso;
}

int encontrar(int *subconjuntos, int i) {
    if (subconjuntos[i] == -1)
        return i;
    return encontrar(subconjuntos, subconjuntos[i]);
}


void unir(int *subconjuntos, int x, int y) {
    int raiz_x = encontrar(subconjuntos, x);
    int raiz_y = encontrar(subconjuntos, y);
    subconjuntos[raiz_x] = raiz_y;
}


int calcularSomaMenoresCaminhos(Grafo *grafo) {
    int V = grafo->V;
    int E = grafo->E;
    int soma = 0,i = 0,e = 0,v;
    int raiz_origem ;
    int raiz_destino;
    Aresta proximaAresta;
    qsort(grafo->arestas, E, sizeof(grafo->arestas[0]), compararArestas);
    
    int* subconjuntos = (int*)malloc(V* sizeof(int));
    
    for (v = 0; v < V; v++)
        subconjuntos[v] = -1;
   
    for (i = 0; i < E && e < V-1; ++i) {
        proximaAresta = grafo->arestas[i];

        raiz_origem = encontrar(subconjuntos, proximaAresta.orig);
        raiz_destino = encontrar(subconjuntos, proximaAresta.dest);

        if (raiz_origem != raiz_destino) {
            unir(subconjuntos, raiz_origem, raiz_destino);
            soma += proximaAresta.peso;
            e++;
        }
    }
    free(subconjuntos);
    return soma;
}


int main() {
    int M,soma=0,i;
    unsigned short N,a,b,c;
    scanf("%hu%d", &N,&M);

    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->V = N;
    grafo->E = M;
    grafo->arestas = (Aresta*)malloc((M)* sizeof(Aresta));

    for (i = 0; i < M; ++i) {
        scanf("%hu%hu%hu", &a,&b,&c);
        grafo->arestas[i].orig = a-1;
        grafo->arestas[i].dest = b-1;
        grafo->arestas[i].peso = c;
    }
    soma = calcularSomaMenoresCaminhos(grafo);
    printf("%d\n", soma);

    free(grafo->arestas);
    free(grafo);
    return 0;
}
