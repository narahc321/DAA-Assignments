#include <stdio.h>
#include <time.h>
int t1=0,t2=0;


void max_min(int x, int m,int a[][m], int* max, int* min){
	t2+=2;
	*max=*min=a[x][0];
	int i;
	t2+=2;
	for(i=1;i<m;i++){
		t2+=4;
		if(a[x][i]>*max)
			*max=a[x][i];
		else if(a[x][i]<*min){
			*min=a[x][i];
			t2++;
		}
	}
	return;
}

void find(int l, int r, int m,int a[][m], int* max, int* min){
	t1++;
	if(l==r){
		t1++;
		max_min(l,m,a,max,min);
		//printf("%d %d %d\n",l,*min,*max);
		return;
	}
	int max1,max2,min1,min2;
	t1+=6;
	find(l,(l+r)/2,m,a,&max1,&min1);
	find(((l+r)/2)+1,r,m,a,&max2,&min2);
	*max=(max1>max2) ? max1 : max2;
	*min=(min1<min2) ? min1 : min2;
	return;
}

int main()
{ 
	srand(time(NULL));
	FILE *average = fopen("./average.dat", "w");
	FILE *best = fopen("./best.dat", "w");
	FILE *worst = fopen("./worst.dat", "w");
	int i,j,max,min,n=101,m,x;
	//scanf("%d %d",&n,&m);
	while(n-- >2){
		t1=0;t2=0;x=100000;
		m=n;
		int a[n][m];
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				a[i][j]=x--;//rand()%100;
		find(0,n-1,m,a,&max,&min);
		fprintf(worst, "%d\t%d\n", n, t1+t2);
		t1=t2=0;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				a[i][j]=0;//rand()%100;
		find(0,n-1,m,a,&max,&min);
		fprintf(best, "%d\t%d\n", n, t1+t2);
		t1=t2=0;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				a[i][j]=rand()%100;
		find(0,n-1,m,a,&max,&min);
		fprintf(average, "%d\t%d\n", n, t1+t2);
	}
	fclose(average);
	fclose(worst);
	fclose(best);

	system("gnuplot -p sort.gnp");
	return 0;
}
//9*(n-1)+2,(4|5)*n*(m-1)+4;
