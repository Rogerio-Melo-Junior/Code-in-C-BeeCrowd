#include <stdio.h>

int main(){
    int Bit,n50,n10,n5,n1,teste=0;
    while(scanf("%d",&Bit)!=EOF){
        n50 = n10 = n5 = n1 = 0;
        if(Bit==0)
            return 0;
        if(Bit>=50){
          n50 = Bit/50;
          Bit = Bit%50;
        }
        if(Bit>=10){
          n10 = Bit/10;
          Bit = Bit%10;
        }
        if(Bit>=5){
          n5 = Bit/5;
          Bit = Bit%5;
        }
        if(Bit>=1){
          n1 = Bit;
        }
        teste++;
        printf("Teste %d\n%d %d %d %d\n\n",teste,n50,n10,n5,n1);
    }
    return 0;
}