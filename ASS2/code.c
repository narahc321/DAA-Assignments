#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void find(int** m,int key,int n){
    int i,j,count=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(m[i][j]==key){
                printf("(%d,%d)\n",i,j);
                count++;
            }
        }
    }
    if(count==0)
        printf("Given key is not present in the matrix\n");
    printf("Total number of positions = %d\n",count);
}
int main(){
    srand(time(0));
    int **m;
    int n,i,j;
    printf("Value of N : ");
    scanf("%d",&n);
    m=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
        m[i]=(int*)malloc(n*sizeof(int));
    printf("Random Matrix : ");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            m[i][j]=rand()%10;
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
    int key=rand()%10;
    printf("Key : %d\n",key);
    printf("%d is at position(s) : \n",key);
    find(m,key,n);
   return 0;
}