#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int space=0,t=0,t;

struct element{
	struct node* head;
	struct node* tail;
};
struct node{
	int pos;
	struct node* link;
};

void print(struct element e){
	struct node* temp=e.head;
	while(temp!=NULL){
		printf("\t%d ",temp->pos);
		temp=temp->link;
	}
	printf("\n");
}

void free_node(struct node* head){
	struct node* temp=head;
	while(temp!=NULL){
		head=temp;
		temp=temp->link;
		free(head);
	}
}

void insert_node(struct element * arr,int i,int value){
	space++;
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->pos=value;
	temp->link=NULL;
	arr[i].tail->link=temp;
	arr[i].tail=temp;
}

void free_mem(struct element * pos_arr,struct element * ele,int * a,int n){
	for(int i=0;i<n;i++){
		free_node(pos_arr[i].head);
		free_node(ele[i].head);
	}
	free(pos_arr);
	free(ele);
	free(a);
}

void swap(struct element * pos_arr,struct element * ele,int *a,int x,int y){
	t+=3;
	int z;
	z=a[x];
	a[x]=a[y];
	a[y]=z;
	struct element temp;
	temp=ele[x];
	ele[x]=ele[y];
	ele[y]=temp;
	insert_node(ele,x,x);
	insert_node(ele,y,y);
	insert_node(pos_arr,x,a[x]);
	insert_node(pos_arr,y,a[y]);
}

void max_heapify(struct element * pos_arr,struct element * ele,int *a,int i, int n){
	t+=10;
	int max = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	if( l<n && a[max]<a[l] ) max = l;
	if( r<n && a[max]<a[r] ) max = r;
	if( max != i ){
		swap(pos_arr,ele,a,i,max);
		max_heapify(pos_arr,ele,a,max,n);
	}
}

void build_heap(struct element * pos_arr,struct element * ele,int *a, int n){
	int i;
	for(i=n/2-1;i>=0;i--){
		t++;
		max_heapify(pos_arr,ele,a,i,n);
	}
	//printf("\n%d",space);
}

void delete(struct element * pos_arr,struct element * ele,int *a, int n){
	t+=2;
	swap(pos_arr,ele,a,0,n-1);
	max_heapify(pos_arr,ele,a,0,n-1);
}


int main()
{
	int n=1000,i,k;
	srand(time(0));
	struct element * ele;
	struct element	* pos_arr;
	int *a;
	FILE *average = fopen("./average.dat", "w");
	FILE *best = fopen("./best.dat", "w");
	FILE *worst = fopen("./worst.dat", "w");
	while(n>=10){
		space = 0;t=0;//2*n;
		ele =(struct element*)malloc(n*sizeof(struct element));
		pos_arr =(struct element*)malloc(n*sizeof(struct element));
		a=(int *)malloc(n*sizeof(int));
		for(i=0;i<n;i++){
			a[i]=rand()%100;
			//scanf("%d",&a[i]);
			ele[i].head=(struct node *)malloc(sizeof(struct node));
			ele[i].head->pos=i;
			ele[i].head->link=NULL;
			ele[i].tail=ele[i].head;

			pos_arr[i].head=(struct node *)malloc(sizeof(struct node));
			pos_arr[i].head->pos=a[i];
			pos_arr[i].head->link=NULL;
			pos_arr[i].tail=pos_arr[i].head;
		}
		build_heap(pos_arr,ele,a,n);
		k=rand()%n;//space=0;
		//t=0;
		for(i=0;i<k-2;i++)
			delete(ele,pos_arr,a,n-i);	

		free_mem(ele,pos_arr,a,n);
		fprintf(average, "%d\t%d\n", n, t);
		space =0;// 2*n;
		t=0;
		ele =(struct element*)malloc(n*sizeof(struct element));
		pos_arr =(struct element*)malloc(n*sizeof(struct element));
		a=(int *)malloc(n*sizeof(int));
		for(i=0;i<n;i++){
			a[i]=n-i;
			//scanf("%d",&a[i]);
			ele[i].head=(struct node *)malloc(sizeof(struct node));
			ele[i].head->pos=i;
			ele[i].head->link=NULL;
			ele[i].tail=ele[i].head;

			pos_arr[i].head=(struct node *)malloc(sizeof(struct node));
			pos_arr[i].head->pos=a[i];
			pos_arr[i].head->link=NULL;
			pos_arr[i].tail=pos_arr[i].head;
		}
		build_heap(pos_arr,ele,a,n);
		k=1;
		//t=0;
		//space=0;
		for(i=0;i<k-2;i++)
			delete(ele,pos_arr,a,n-i);	


		free_mem(ele,pos_arr,a,n);
		fprintf(best, "%d\t%d\n", n, t);
		space =0;// 2*n;
		t=0;
		ele =(struct element*)malloc(n*sizeof(struct element));
		pos_arr =(struct element*)malloc(n*sizeof(struct element));
		a=(int *)malloc(n*sizeof(int));
		for(i=0;i<n;i++){
			a[i]=i+1;
			ele[i].head=(struct node *)malloc(sizeof(struct node));
			ele[i].head->pos=i;
			ele[i].head->link=NULL;
			ele[i].tail=ele[i].head;

			pos_arr[i].head=(struct node *)malloc(sizeof(struct node));
			pos_arr[i].head->pos=a[i];
			pos_arr[i].head->link=NULL;
			pos_arr[i].tail=pos_arr[i].head;
		}
		build_heap(pos_arr,ele,a,n);
		k=n;
		//space=0;
		//t=0;
		for(i=0;i<k-2;i++)
			delete(ele,pos_arr,a,n-i);	

		free_mem(ele,pos_arr,a,n);
		fprintf(worst, "%d\t%d\n", n, t);
		n-=5;
	}
	fclose(average);
	fclose(worst);
	fclose(best);

	system("gnuplot -p sort.gnp");
	return 0;
}
