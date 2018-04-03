#include <stdio.h>
#include <stdlib.h>

#define s(x) scanf("%d",&x)

typedef struct node
{
	int val;
	struct node *left, *right, *parent;
}node;
typedef struct node *list;

int n,ar[100005],count,lc;
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
int lca(list root, int a, int b)
{
	if(count==2)
		return 0;
	if(root==NULL)
		return 0;
	if(root->val==a || root->val==b)
		count++;
	int ans1=lca(root->left,a,b),ans2=lca(root->right,a,b);
	if(root->val==a || root->val==b)
	{
		if(root->val==a)
			node1=root;
		else 
			node2=root;
		if(ans1+ans2==1 && lc==-1)
			lc=root->val;
		return ans1+ans2+1;
	}
	
	if(ans1+ans2>=2 && lc==-1)
		lc=root->val;
	return ans1+ans2;
}

int search(list root, int n1){
	if(root==NULL)
		return 0;
	if(root->val==n1)
		return 1;
	return search(root->left,n1)+search(root->right,n1);
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
	s(n);
	int i, j, k;
	int n1, n2;
	for(i=1;i<=n;i++)
		ar[i]=i;//s(ar[i]);
	root=build_tree(root, 1, NULL);
	s(n1);s(n2);
	if(n1==n2){
		if(search(root,n1))
			printf("%d",n1);
		else
			printf("element not found");
		return 0;
	}	
	lc=-1;count=0;
	node1=NULL;node2=NULL;
	lca(root,n1,n2);
	if(node1==NULL || node2==NULL){
		printf("element not found");
		return 0;
	}
	print_first(node1);
	printf("%d",lc);
	print_last(node2);
	free_mem(root);
	return 0;
}
