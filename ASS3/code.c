#include <stdio.h>
#include <stdlib.h>

struct element{
    struct node* head;
    struct node* tail;
};
struct node{
    int it;
    int pos;
    struct node* link;
};

void print(struct element e){
    struct node* temp=e.head;
    while(temp!=NULL){
        printf("(%d,%d) ",temp->it,temp->pos);
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

void insert_node(struct element * arr,int index,int value,int iteration){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->it=iteration;
    temp->pos=value;
    temp->link=NULL;
    arr[index].tail->link=temp;
    arr[index].tail=temp;
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

void swap(struct element * pos_arr,struct element * ele,int *a,int x,int y,int iteration){
    int z;
    z=a[x];
    a[x]=a[y];
    a[y]=z;
    struct element temp;
    temp=ele[x];
    ele[x]=ele[y];
    ele[y]=temp;
    insert_node(ele,x,x,iteration);
    insert_node(ele,y,y,iteration);
    insert_node(pos_arr,x,a[x],iteration);
    insert_node(pos_arr,y,a[y],iteration);
}

void selection_sort(struct element * pos_arr,struct element * ele,int *a,int n){
    int min,max,i,j,mindex,madex,z;
    for(i=0;i<n/2;i++){
        min=a[i];
        mindex=i;
        for(j=i+1;j<n-i;j++){
            if(min>a[j]){
                min=a[j];
                mindex=j;
            }
        }
        if(mindex!=i)
            swap(pos_arr,ele,a,i,mindex,i+1);
        max=a[n-i-1];
        madex=n-i-1;
        for(j=i+1;j<n-i-1;j++){
            if(max<a[j]){
                max=a[j];
                madex=j;
            }
        }
        if(madex!=n-i-1)
            swap(pos_arr,ele,a,n-i-1,madex,i+1);
    }
}

int main()
{
    int n,i;
    scanf("%d",&n);
    struct element * ele =(struct element*)malloc(n*sizeof(struct element));
    struct element * pos_arr =(struct element*)malloc(n*sizeof(struct element));
    int *a=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        ele[i].head=(struct node *)malloc(sizeof(struct node));
        ele[i].head->pos=i;
        ele[i].head->it=0;
        ele[i].head->link=NULL;
        ele[i].tail=ele[i].head;
        
        pos_arr[i].head=(struct node *)malloc(sizeof(struct node));
        pos_arr[i].head->pos=a[i];
        pos_arr[i].head->it=0;
        pos_arr[i].head->link=NULL;
        pos_arr[i].tail=pos_arr[i].head;
    }
    selection_sort(pos_arr,ele,a,n);
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
