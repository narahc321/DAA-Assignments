#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define s(x) scanf("%d",&x)

typedef struct node
{
	int val;
	struct node *left, *right, *parent;
}node;
typedef struct node *list;

int n,ar[100005],count,lc,t;
list node1, node2, root;

list insert(int val)
{
	list temp=(list)malloc(sizeof(node));
	temp->val=ar[val];
	temp->left=temp->right=NULL;
	return temp;
}
list build_tree(list root, int val, list pa)
{
	if(val>n)
		return NULL;
	root=insert(val);
	root->left=build_tree(root->left,2*val,root);
	root->right=build_tree(root->right,2*val+1,root);
	root->parent=pa;
	return root;

}


int search(list root, int n1){
	t+2;
	t++;
	if(root==NULL)
		return 0;
	t++;
	if(root->val==n1)
		return 1;
	return search(root->left,n1)+search(root->right,n1);
}



int lca(list root, int a, int b)
{
	t+=2;
	t++;
	if(count==2)
		return 0;
	t++;
	if(root==NULL)
		return 0;
	t+=2;
	if(root->val==a || root->val==b)
		count++;
	
	int ans1=lca(root->left,a,b),ans2=lca(root->right,a,b);
	t+=2;
	if(root->val==a || root->val==b)
	{
		t+=2;
		if(root->val==a)
			node1=root;
		else 
			node2=root;
		t+=4;
		if(ans1+ans2==1 && lc==-1)
			lc=root->val;
		return ans1+ans2+1;
	}
	
	if(ans1+ans2>=2 && lc==-1)
		lc=root->val;
	return ans1+ans2;
}

void print_first(list node1){
	if(node1->val!=lc){	
		printf("%d->",node1->val);
		print_first(node1->parent);
	}
}

void print_last(list node2){
	if(node2->val!=lc){	
		print_last(node2->parent);
		printf("->%d",node2->val);
	}
}
void free_mem(list root){
	if(root!=NULL){
		free_mem(root->left);
		free_mem(root->right);
		free(root);
	}
}
int main()
{
	n=0;srand(time(NULL));
	FILE* fpb=fopen("best.txt","w");
	FILE* fpa=fopen("average.txt","w");
	FILE* fpw=fopen("worst.txt","w");
	while(n<=100){
		int i, j, k, n1, n2,tw,ta;
		for(i=1;i<=n;i++)
			ar[i]=i;//s(ar[i]);
		root=build_tree(root, 1, NULL);

		t=0;
		n1=1;n2=1;
		t++;
		if(n1==n2){
			t+=2;
			if(search(root,n1))
				n1=n1;//printf("%d",n1);
			else
				n1=n1;//printf("element not found");
		}
		printf("%d %d\n",n,t);
		fprintf(fpb,"%d %d\n",n,t);


		t=0;
		n1=n+2;n2=n+5;
		lc=-1;count=0;
		node1=NULL;node2=NULL;
		lca(root,n1,n2);
		t++;
		t+=2;
		if(node1==NULL || node2==NULL){
			//printf("element not found");
			//continue;
		}
		printf("%d %d\n",n,t);
		fprintf(fpw,"%d %d\n",n,t);
		tw=t;


		t=0;
		n1=n/3;n2=n/4;
		t++;
		if(n1==n2){
			t+=2;
			if(search(root,n1))
				n1=n1;//printf("%d",n1);
			else
				n1=n1;//printf("element not found");
		}
		else{
			lc=-1;count=0;
			node1=NULL;node2=NULL;
			lca(root,n1,n2);
			t+=2;
			if(node1==NULL || node2==NULL){
				t=t;
			}
		}
		ta=t;
		printf("%d %d\n",n,t);
		fprintf(fpa,"%d %d\n",n,t-2);
		if(ta>tw){
		
	printf("\n\n\n %d %d %d    %d %d\n\n\n",n,ta,tw,n1,n2);

		}
		//print_first(node1);
		//printf("%d",lc);
		//print_last(node2);
		free_mem(root);
		n+=5;
	}
	system("gnuplot -p command" );
	return 0;
}
