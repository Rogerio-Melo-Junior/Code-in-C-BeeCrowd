#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int dia;
    int mes;
    int ano;
}Datas;

int compararAno(const void *a, const void *b){
    Datas *a1 = (Datas*)a;
    Datas *b1 = (Datas*)b;
    return a1->ano - b1->ano;
}
int compararMes(const void *a, const void *b){
    Datas *a1 = (Datas*)a;
    Datas *b1 = (Datas*)b;
    return a1->mes - b1->mes;
}
int compararDia(const void *a, const void *b){
    Datas *a1 = (Datas*)a;
    Datas *b1 = (Datas*)b;
    return a1->dia - b1->dia;
}
int main(){
    int n,m,i=0,j=0,x,soma=0,e=0,beta,aux;
    Datas *data = (Datas*)malloc(50*sizeof(Datas));
    Datas *d_ano = (Datas*)malloc(50*sizeof(Datas));
    Datas *d_mes = (Datas*)malloc(50*sizeof(Datas));
    Datas *d_dia = (Datas*)malloc(50*sizeof(Datas));
    
    while(scanf("%d%d",&n,&m)!=EOF){
        beta=0;
        while(i<m){
            scanf("%d%*c%d%*c%d",&data[i].dia,&data[i].mes,&data[i].ano);
            while(j<n){
                scanf("%*c%d",&x);
                soma+=x;
                j++;
            }
            if(soma==n){
                beta=1;
                d_ano[e++] = data[i];
            }
            j=soma=0;
            i++;
        }
        if(beta==1){
                qsort(d_ano,e,sizeof(d_ano[0]),compararAno);
                aux = d_ano[0].ano;
                j=0;
                while(d_ano[j].ano == aux){
                    d_mes[j] = d_ano[j];
                    j++;
                }
                
                qsort(d_mes,j,sizeof(d_mes[0]),compararMes);
                aux = d_mes[0].mes;
                j=0;
                while(d_mes[j].mes == aux){
                    d_dia[j] = d_mes[j];
                    j++;
                }
                qsort(d_dia,j,sizeof(d_dia[0]),compararDia);
                printf("%d/%d/%d\n",d_dia[0].dia,d_dia[0].mes,d_dia[0].ano);
        }
        else{
                printf("Pizza antes de FdI\n");
        }
        e=i=j=0;
    }
    return 0;
}