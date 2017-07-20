
#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
int *start=NULL;
void create(struct node *,int);
struct node insertafter(struct node*,int,int);
void display();
void delete(int);
int main()
{
	int d,t=1,x,b,z;
	struct node *newnode;
	while(t)
	{
		scanf("%d",&d);
		newnode=(struct node *)malloc(sizeof(struct node));
		create(newnode,d);
		scanf("%d",&t);
	}
	display();
	printf("do you");
	scanf("%d",&x);
	while(x)
	{
		printf("Enter the value");
		scanf("%d",&b);
		printf("Enter data");
		scanf("%d",&d);
		struct node *newnode=(struct node*)malloc(sizeof(struct node));
		insertafter(newnode,b,d);
		printf("continue 1");
		scanf("%d",&x);
	}
	display();
	printf("wish to delete");
	scanf("%d",&z);
	if(z==1)
		scanf("%d",&z);
	delete(z);
	display();
}


void create(struct node *new,int value)
{
	new->data=value;
	if(start==NULL)
	{
		new->next=NULL;
		start=new;
	}
	else
	{
		struct node *ptr;
		ptr=start;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=new;
		new->next=NULL;

	}

}
void display()
{
	struct node *n;
	n=start;
	while(n->next!=NULL){
		printf("%d",n->data);
		n=n->next;

	}
	printf("%d",n->data);
}
struct node insertafter(struct node *new,int v1,int v2)
{
	new->data=v2;
	struct node *ptr;
	ptr=start;
	while(ptr->data!=v1)
		ptr=ptr->next;
	new->next=ptr->next;
	ptr->next=new;
}
void delete(int data){
	struct node *ptr;
	struct node *preptr;
	ptr=start;
	while(ptr->data!=data){
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
}










