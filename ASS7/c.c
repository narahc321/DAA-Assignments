#include <stdio.h>
int heapify(int* a,int i,int n)
{
	int x=i,j=2*i+1,k=2*i+2;
	if(j<n && a[j]>a[i])
		x=j;
	if(k<n && a[k]>a[x])
		x=k;
	if(x!=i)
	{
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
	}
	for(i=n-1;i>=0;i--)
	{
		x=a[0];
		a[0]=a[i];
		a[i]=x;
		heapify(a,0,i);
	}
	return 0;
}

int main()
{
	int n,m,flag=1,i,N3,N2,ones=0,twos=0,threes=0,fours=0,x,y;
	printf("ENTER NUMBER OF ROWS:");
	scanf("%d",&n);
	printf("ENTER NUMBER OF FAMILY:");
	scanf("%d",&m);
	int a[m];
	printf("ENTER NUMBER OF IN EACH FAMILY:\n");
	for(i=0;i<m;i++)
		scanf("%d",&a[i]);
	sort(a,m);
	N3=n;N2=n,i=0;
	while(i<m && a[i]==1 && flag==1){
		ones++;
		i++;
	}
	x=ones/2;
	y=ones%2;
	if(x<=N3){
		N3-=x;
	}
	else{
		x-=N3;
		N3=0;
		y=y+(x*2);
		N2-=y;
		y=0;
		x=0;
	}
	ones=y;
	if(N2<0 || N3<0){
		//printf("1");
		flag=0;
	}
	while(i<m && a[i]==2 && flag==1){
		twos++;
		i++;
	}
	if(N2<=twos){
		N2-=twos;
		twos=0;
	}
	else{
		twos-=N2;
		N2=0;
		N3-=twos;
		twos=0;
	}
	if(N2<0 || N3<0){
		//printf("2");
		flag=0;
	}
	while(i<m && a[i]==3 && flag==1){
		threes++;
		i++;
	}
	if(N3<=threes){
		N3-=threes;
		threes=0;
	}
	else{
		threes-=N3;
		N3=0;
		N2-=(2*threes);
		threes;
	}
	if(N2<0 || N3<0){
		//printf("3");
		flag=0;
	}
	for(;i<m;i++){
		x=a[i]/3;y=a[i]%3;
		if(y==1){
			fours++;
			x--;
		}
		else if(y==2){
			if(N2>0)
				N2--;
			else
				N3--;
		}
		N3-=x;
		if(N3==0){
			x=0;
			break;
		}
		if(N3<0){
			N3+=x;
			x-=N3;
			N3=0;
			break;
		}
		x=0;
	}
	y=x*3;
	N2-=((y/2)+(y%2));
	if(N2<0 || N3<0){
		//printf("4");
		flag=0;
	}
	for(i=i+1;i<m;i++){
		y=a[i];
		N2-=((y/2)+(y%2));
		if(N2<0){
			flag=0;
			break;
		}
	}
	if(N2>=fours*2){
		N2-=(fours*2);
		fours=0;
	}
	else{
		fours-=(N2/2);
		if(N2%2==1){
			fours--;
			N3--;
		}
		N2=0;
	}
	ones+=fours;
	N3-=fours;
	ones-=N2;
	N2=0;
	if(ones<0)
		ones=0;
	N3-=((ones/2)+(ones%2));
	if(N2<0 || N3<0){
		//printf("5");
		flag=0;
	}
	if(flag)
		printf("YES\n");
	else
		printf("NO\n");
}












