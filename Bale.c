#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 100002

void update(int i,int valor,int *BIT,int tam){
    for(;i<=tam; i+=((i) & -(i)))
        BIT[i]+=valor;
}

int soma(int i,int *BIT){
    int sum = 0;
    for(;i!=0;i-=((i) & -(i)))
        sum +=BIT[i];
    return sum;
}

int main(){
    int sum=0,i,j,n;
    int maior = 0;
    
    int ret = 0;
    scanf("%d",&n);
    
    int *vet = (int*)malloc(n*sizeof(int));
    for(j=0;j<n;j++){
          scanf("%d",&vet[j]);
          if(vet[j]>maior)
            maior = vet[j];
    }
    int *Oi = (int*)malloc((maior+1)*sizeof(int));
    Oi = (int*)calloc(maior+1,sizeof(int));
    for (i = n - 1 ; i >= 0 ; i-- ){
       sum+=soma(vet[i]-1,Oi);
       update(vet[i],1,Oi,maior+1);
    }
    printf("%d\n",sum);
    return 0;
}