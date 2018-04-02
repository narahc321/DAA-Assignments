#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int t;
void find(int** m,int key,int n){
    int i,j,count=0;t++;
    t+=2;
    for(i=0;i<n;i++){
        t+=2;
        t+=2;
        for(j=0;j<n;j++){
            t+=2;
            t+=2;
            if(m[i][j]==key){
                t+=2;
                count++;
            }
        }
    }
}
int main(int argc, int **argv){
    srand(time(0));
    int **m;
    int n,i,j,key;
    n=atoi(argv[1]);
    m=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
        m[i]=(int*)malloc(n*sizeof(int));
    FILE *fp=fopen("average.txt","a");
    t=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            m[i][j]=rand()%15;
        }
    }
    key=rand()%15;
    find(m,key,n);
    fprintf(fp,"%d\t%d\n",n,t);
    fclose(fp);
    fp=fopen("worst.txt","a");
    t=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            m[i][j]=1;
        }
    }
    key=1;
    find(m,key,n);
    fprintf(fp,"%d\t%d\n",n,t);
    fclose(fp);
    fp=fopen("best.txt","a");
    t=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            m[i][j]=10;
        }
    }
    key=1;
    find(m,key,n);
    fprintf(fp,"%d\t%d\n",n,t);
    fclose(fp);
   return 0;
}