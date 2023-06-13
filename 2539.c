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
        sum+=BIT[i];
    return sum;
}

int main(){
    unsigned long long sum=0;
    int i,n,vet[max],BIT[max];
    int maior = 0;
    while(scanf("%d",&n)!=EOF){
    
    for(i=0;i<n;i++){
          scanf("%d",&vet[i]);
          if(vet[i]>maior)
            maior = vet[i];
    }
    memset(BIT,0,(maior+1)*sizeof(int));
    for (i = 0; i < n ; i++ ){
       update(vet[i]+1,1,BIT,maior+1);
       sum+=soma(vet[i],BIT);
    }
    memset(vet,0,(n)*sizeof(int));
    printf("%llu\n",sum);
    maior = sum = 0;
    }
    return 0;
}