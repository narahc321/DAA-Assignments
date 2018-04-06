#include <stdio.h>
#include <stdlib.h>

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
		max_heapify(pos_arr,ele,a,i,n);
	}	
}

void delete(struct element * pos_arr,struct element * ele,int *a, int n){
	swap(pos_arr,ele,a,0,n-1);
	max_heapify(pos_arr,ele,a,0,n-1);
}


int main()
{
	int n,i,k;
	scanf("%d",&n);
	struct element * ele =(struct element*)malloc(n*sizeof(struct element));
	struct element * pos_arr =(struct element*)malloc(n*sizeof(struct element));
	int *a=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		a[i]=i;
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
	scanf("%d",&k);
	for(i=0;i<k-2;i++){
		delete(ele,pos_arr,a,n-i);	
	}
	if(k==1)
		printf("%d",a[0]);
	else if(k==n || a[1]>a[2])
		printf("%d",a[1]);
	else
		printf("%d",a[2]);
	for(i=0;i<n;i++){
		printf("%d :",a[i]);
		print(ele[i]);
	}
	printf("\n");
	for(i=0;i<n;i++){
		printf("%d :",i);
		print(pos_arr[i]);
	}
	free_mem(ele,pos_arr,a,n);
	return 0;
}
