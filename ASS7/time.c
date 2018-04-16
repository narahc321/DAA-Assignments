#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int t;
int heapify(int* a,int i,int n)
{
	t+=3;
	int x=i,j=2*i+1,k=2*i+2;
	t+=4;
	if(j<n && a[j]>a[i])
		x=j;
	if(k<n && a[k]>a[x])
		x=k;
	if(x!=i)
	{
		t+=3;
		k=a[i];
		a[i]=a[x];
		a[x]=k;
		heapify(a,x,n);
	}
	return 0;
}
int sort(int* a,int n)
{
	int i,x;
	for(i=n/2;i>=0;i--){
		heapify(a,i,n);
		t+=2;	
	}
	for(i=n-1;i>=0;i--)
	{
		t+=5;
		x=a[0];
		a[0]=a[i];
		a[i]=x;
		heapify(a,0,i);
	}
	return 0;
}
int main()
{
	int n,m,flag=1,x,y,p[6],i,N3,N2,a[1000000],t1,t2;
	srand(time(NULL));
	FILE *average = fopen("./average.dat", "w");
	FILE *best = fopen("./best.dat", "w");
	FILE *worst = fopen("./worst.dat", "w");
	m=1000;
	//scanf("%d %d",&n,&m);
	while(m>2){
		t=0;
		flag=1;

		for(i=0;i<5;i++)
			p[i]=0;

		n=1;
		t+=12;
		t+=(2*m+2);
		for(i=0;i<m;i++){
			a[i]=i;
		}

		N3=n;N2=n;
		t+=2;
		for(i=0;i<m;i++){
			t+=4;
			x=a[i]/3;y=a[i]%3;
			if(y==1){
				if(a[i]==1)
					p[1]++;
				else{
					p[4]++;
					x--;
				}
				t+=5;
			}
			else{
				t+=2;
				if(y==2)
					p[2]++;
			}
			N3-=x;
			if(N3==0){
				t+=2;
				x=0;
				break;
			}
			if(N3<0){
				t+=5;
				N3+=x;
				x-=N3;
				N3=0;
				a[i]=x*3;
				break;
			}
			x=0;
		}
		t+=6;
		y=x*3;
		N2-=((y/2)+(y%2));
		if(N2<0)
			flag=0;
		for(i=i+1;i<m;i++){
			t+=6;
			y=a[i];
			N2-=((y/2)+(y%2));
			if(N2<0){
				t+=2;
				flag=0;
				break;
			}
		}
		t+=4;
		if(p[2]<=N2){
			N2-=p[2];
			p[2]=0;
		}
		else{
			p[2]-=N2;
			N2=0;
			N3-=p[2];
			if(N3<0)
				flag=0;
			t+=2;
		}
		t+=4;
		if(N2>=p[4]*2){
			N2-=(p[4]*2);
			p[4]=0;
		}
		else{
			p[4]-=(N2/2);
			if(N2%2==1){
				p[4]--;
				N3--;
				t+=2;
			}
			N2=0;
		}
		t+=11;
		p[1]+=p[4];
		N3-=p[4];
		p[1]-=N2;
		N2=0;
		if(p[1]<0)
			p[1]=0;
		N3-=((p[1]/2)+(p[1]%2));
		if(N2<0 || N3<0)
			flag=0;
		fprintf(best, "%d\t%d\n", m, t);
		t1=t;
		t=0;
		flag=1;
		for(i=0;i<5;i++)
			p[i]=0;

		n=m/2;

		t+=12;
		t+=(2*m+2);
		for(i=0;i<m;i++){
			a[i]=rand()%5;
		}

		N3=n;N2=n;
		t+=2;
		for(i=0;i<m;i++){
			t+=4;
			x=a[i]/3;y=a[i]%3;
			if(y==1){
				if(a[i]==1)
					p[1]++;
				else{
					p[4]++;
					x--;
				}
				t+=5;
			}
			else{
				t+=2;
				if(y==2)
					p[2]++;
			}
			N3-=x;
			if(N3==0){
				t+=2;
				x=0;
				break;
			}
			if(N3<0){
				t+=5;
				N3+=x;
				x-=N3;
				N3=0;
				a[i]=x*3;
				break;
			}
			x=0;
		}
		t+=6;
		y=x*3;
		N2-=((y/2)+(y%2));
		if(N2<0)
			flag=0;
		for(i=i+1;i<m;i++){
			t+=6;
			y=a[i];
			N2-=((y/2)+(y%2));
			if(N2<0){
				t+=2;
				flag=0;
				break;
			}
		}
		t+=4;
		if(p[2]<=N2){
			N2-=p[2];
			p[2]=0;
		}
		else{
			p[2]-=N2;
			N2=0;
			N3-=p[2];
			if(N3<0)
				flag=0;
			t+=2;
		}
		t+=4;
		if(N2>=p[4]*2){
			N2-=(p[4]*2);
			p[4]=0;
		}
		else{
			p[4]-=(N2/2);
			if(N2%2==1){
				p[4]--;
				N3--;
				t+=2;
			}
			N2=0;
		}
		t+=11;
		p[1]+=p[4];
		N3-=p[4];
		p[1]-=N2;
		N2=0;
		if(p[1]<0)
			p[1]=0;
		N3-=((p[1]/2)+(p[1]%2));
		if(N2<0 || N3<0)
			flag=0;	


		fprintf(worst, "%d\t%d\n", m, t);
		t2=t;
		t=0;
		flag=1;
		for(i=0;i<5;i++)
			p[i]=0;

		n=m/2;

		t+=12;
		t+=(2*m+2);
		for(i=0;i<m;i++){
			a[i]=rand()%10;
		}

		N3=n;N2=n;
		t+=2;
		for(i=0;i<m;i++){
			t+=4;
			x=a[i]/3;y=a[i]%3;
			if(y==1){
				if(a[i]==1)
					p[1]++;
				else{
					p[4]++;
					x--;
				}
				t+=5;
			}
			else{
				t+=2;
				if(y==2)
					p[2]++;
			}
			N3-=x;
			if(N3==0){
				t+=2;
				x=0;
				break;
			}
			if(N3<0){
				t+=5;
				N3+=x;
				x-=N3;
				N3=0;
				a[i]=x*3;
				break;
			}
			x=0;
		}
		t+=6;
		y=x*3;
		N2-=((y/2)+(y%2));
		if(N2<0)
			flag=0;
		for(i=i+1;i<m;i++){
			t+=6;
			y=a[i];
			N2-=((y/2)+(y%2));
			if(N2<0){
				t+=2;
				flag=0;
				break;
			}
		}
		t+=4;
		if(p[2]<=N2){
			N2-=p[2];
			p[2]=0;
		}
		else{
			p[2]-=N2;
			N2=0;
			N3-=p[2];
			if(N3<0)
				flag=0;
			t+=2;
		}
		t+=4;
		if(N2>=p[4]*2){
			N2-=(p[4]*2);
			p[4]=0;
		}
		else{
			p[4]-=(N2/2);
			if(N2%2==1){
				p[4]--;
				N3--;
				t+=2;
			}
			N2=0;
		}
		t+=11;
		p[1]+=p[4];
		N3-=p[4];
		p[1]-=N2;
		N2=0;
		if(p[1]<0)
			p[1]=0;
		N3-=((p[1]/2)+(p[1]%2));
		if(N2<0 || N3<0)
			flag=0;	

		fprintf(average, "%d\t%d\n", m, t);
		m-=10;
	}
	fclose(average);
	fclose(worst);
	fclose(best);

	system("gnuplot -p sort.gnp");
	return 0;
}










