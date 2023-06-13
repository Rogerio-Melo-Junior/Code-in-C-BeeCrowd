#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1002

int main(){
    int N,M,i,j;
    char mat[MAX][MAX],count=0;
    memset(mat,'0',sizeof(mat));
    scanf("%d%d",&N,&M);
    for(i=1;i<=N;i++){
        for(j=1;j<=M;j++){
            scanf(" %c",&mat[i][j]);
        }
    }
    for(i=1;i<=N;i++){
        for(j=1;j<=M;j++){
            if(mat[i][j]=='#'){
                if(mat[i-1][j]!='#' || mat[i+1][j]!='#' || mat[i][j-1]!='#' || mat[i][j+1]!='#')
                 count++;
                else
                 continue;
            }
            
        }
    }
    printf("%d\n",count);
    return 0;
}