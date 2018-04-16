#include <stdio.h>
int a[1000000];
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
    int n,m,flag=1;
    printf("ENTER NUMBER OF ROWS:");
    scanf("%d",&n);
    int x,y,p[6],i,N3,N2,n1=0;
    for(i=0;i<5;i++)
        p[i]=0;
    printf("ENTER NUMBER OF FAMILY:");
    scanf("%d",&m);
    printf("ENTER NUMBER OF IN EACH FAMILY:\n");
    for(i=0;i<m;i++)
        scanf("%d",&a[i]);
	sort(a,m);
    N3=n;N2=n;
    for(i=0;i<m;i++){
        x=a[i]/3;y=a[i]%3;
        if(y==1){
            if(a[i]==1)
                p[1]++;
            else{
                p[4]++;
                x--;
            }
        }
        else{
            if(y==2)
                p[2]++;
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
            a[i]=x*3;
            break;
        }
        x=0;
    }
    y=x*3;
    N2-=((y/2)+(y%2));
    if(N2<0)
        flag=0;
    for(i=i+1;i<m;i++){
        y=a[i];
        N2-=((y/2)+(y%2));
        if(N2<0){
            flag=0;
            break;
        }
    }
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
    }
    if(N2>=p[4]*2){
        N2-=(p[4]*2);
        p[4]=0;
    }
    else{
        p[4]-=(N2/2);
        if(N2%2==1){
            p[4]--;
            N3--;
        }
        N2=0;
    }
    p[1]+=p[4];
    N3-=p[4];
    p[1]-=N2;
    N2=0;
    if(p[1]<0)
        p[1]=0;
    N3-=((p[1]/2)+(p[1]%2));
    if(N2<0 || N3<0)
        flag=0;
    if(flag)
        printf("YES\n");
    else
        printf("NO\n");
}










