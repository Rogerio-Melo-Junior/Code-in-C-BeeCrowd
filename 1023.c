
#include <stdio.h>
#include <math.h>
#include <string.h>

struct residencia{
    int qtd_moradores;
    int consumo;
    int media_consumo;
};

typedef struct residencia Casa;
int main(){
    int n,j,k=0,i,maior,first;
    unsigned long long int count[202],total1=0,total2=0;
    float media;
    Casa casa;
    while(scanf("%d",&n)!=EOF){
        i=0;
        maior = 0; 
        if(n==0){
            return 0;
        }
        if(k)
            printf("\n");
        memset(count, 0,sizeof(count));
        while(i<n){
            scanf("%d%d",&casa.qtd_moradores,&casa.consumo);
            casa.media_consumo = casa.consumo/casa.qtd_moradores;
            total1 += casa.qtd_moradores;
            total2 += casa.consumo;
            count[casa.media_consumo]  += casa.qtd_moradores; 
            if(casa.media_consumo>maior)
                maior  = casa.media_consumo;
           i++;
        }
        
        printf("Cidade# %d:\n",++k);
        first = 1;
        for(i=0;i<=maior;i++){
               if(count[i]>0){
                    if (first)
                        first = 0;
                    else
                        printf(" ");

                  printf("%llu-%d",count[i],i);
               }
        }
        media = ((100 * total2) / total1) / 100.0;
        printf("\nConsumo medio: %.2f m3.\n",media);
        total2=total1=0;
    }
    return 0;
}