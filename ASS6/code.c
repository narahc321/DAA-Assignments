#include <stdio.h>

void max_min(int x, int m,int a[][m], int* max, int* min){
    *min=a[x][0];
    *max=*min;
    int i;
    for(i=1;i<m;i++){
        if(a[x][i]>*max)
            *max=a[x][i];
        else if(a[x][i]<*min)
            *min=a[x][i];
    }
    return;
}

void find(int l, int r, int m,int a[][m], int* max, int* min){
    if(l==r){
        max_min(l,m,a,max,min);
        //printf("%d %d %d\n",l,*min,*max);
        return;
    }
    int max1,max2,min1,min2;
    find(l,(l+r)/2,m,a,&max1,&min1);
    find(((l+r)/2)+1,r,m,a,&max2,&min2);
    *max=(max1>max2) ? max1 : max2;
    *min=(min1<min2) ? min1 : min2;
    return;
}

int main()
{
    int i,j,max,min,n,m;
    scanf("%d %d",&n,&m);
    int a[n][m];
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    if(n<=0 || m<=0)
        return 0;
    // for(i=0;i<n;i++){
    //     for(j=0;j<m;j++)
    //         printf("%d ", a[i][j]);
    //     printf("\n");
    // }
    find(0,n-1,m,a,&max,&min);
    printf("max=%d min=%d",max,min);
}
