#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char s[10];
}Nome;
int main(){
    int i;
    char a[6]={"pedra"},b[6]={"papel"},c[8]={"tesoura"};
    Nome *nomes =(Nome*)malloc(3*sizeof(Nome));
        while(scanf("%s%s%s",nomes[0].s,nomes[1].s,nomes[2].s)!=EOF){
         if((strcmp(nomes[0].s,a)==0 && strcmp(nomes[1].s,c)==0 && strcmp(nomes[2].s,c)==0) || (strcmp(nomes[0].s,c)==0 && strcmp(nomes[1].s,b)==0 && strcmp(nomes[2].s,b)==0) || (strcmp(nomes[0].s,b)==0 && strcmp(nomes[1].s,a)==0 && strcmp(nomes[2].s,a)==0)){
            printf("Os atributos dos monstros vao ser inteligencia, sabedoria...\n");
         }
         else if((strcmp(nomes[1].s,a)==0 && strcmp(nomes[0].s,c)==0 && strcmp(nomes[2].s,c)==0) || (strcmp(nomes[1].s,c)==0 && strcmp(nomes[0].s,b)==0 && strcmp(nomes[2].s,b)==0) || (strcmp(nomes[1].s,b)==0 && strcmp(nomes[0].s,a)==0 && strcmp(nomes[2].s,a)==0)){
            printf("Iron Maiden's gonna get you, no matter how far!\n");
         }
         else if((strcmp(nomes[2].s,a)==0 && strcmp(nomes[1].s,c)==0 && strcmp(nomes[0].s,c)==0) || (strcmp(nomes[2].s,c)==0 && strcmp(nomes[1].s,b)==0 && strcmp(nomes[0].s,b)==0) || (strcmp(nomes[2].s,b)==0 && strcmp(nomes[1].s,a)==0 && strcmp(nomes[0].s,a)==0)){
            printf("Urano perdeu algo muito precioso...\n");
         }
         else{
            printf("Putz vei, o Leo ta demorando muito pra jogar...\n");
         }
         strcpy(nomes[0].s,"");
         strcpy(nomes[1].s,"");
         strcpy(nomes[2].s,"");
        }
    free(nomes);
    return 0;
}