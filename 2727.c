#include <stdio.h>
#include <string.h>
int main (){
  int n,i=0,j=0,k=0,tam=0;
  char texto1[98] = {},p[51]= {};
  while(scanf("\n%d",&n)!=EOF){
           i=0;
            while(i<n){
                    scanf(" \n%[^\n]s",texto1);
                    k=0;
                    tam = 0;
                      for(j=0;texto1[j]=='.';j++)
                        tam++;
                        
                      
                      for(j=0;texto1[j]!='\0';j++)
                      {
                        if(texto1[j]==' ')
                            k++;
                      }
                        printf("%c\n",k*3 + 97 + tam-1);
                    strcpy(texto1,"");
                   
                    i++;
            }
  }
  return 0;
}