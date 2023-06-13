#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 12

void merge(int *v,int ini,int m,int fim){
    int c1=ini,c2=m+1,k=0;
    int aux[max];
    while(c1<=m && c2<=fim){
        if(v[c1]<v[c2])
            aux[k++]=v[c1++];
        else
            aux[k++]=v[c2++];
    }
    while(c1<=m)
            aux[k++]=v[c1++];
    while(c2<=fim)
            aux[k++]=v[c2++];
    for(k=ini;k<=fim;k++)
        v[k] = aux[k-ini];
}
void mergesort(int *v,int i,int f){
    int m;
    if(i<f){
        m = (i+f)/2;
        mergesort(v,i,m);
        mergesort(v,m+1,f);
        merge(v,i,m,f);
    }
}

int main(){
   int i,j=0,b,n,v[12],s;
   char *str = (char*)malloc(sizeof(char)*100003);
    scanf("%[^\n]",str);
    scanf("%d",&n);
            while(n!=0){
              scanf("%d",&b);
              s =0;
              for(i=0;str[i]!='\0';i++)
                s = (2*s + (int)(str[i] - '0'))%b;
              
              if(s==0)
                  v[j++] = b;
              n--;
            }
      
      if(j!=0){
         mergesort(v,0,j-1);
         for(i=0;i<j;i++)
            (i==0) ? printf("%d",v[i]) : (printf(" %d",v[i]));
        printf("\n");
      }
      else{
        printf("Nenhum\n");
      }
    free(str);
  return 0;
}