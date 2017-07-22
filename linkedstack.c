/*
 ============================================================================
 Name        : linkedstack.c
 Author      : abhinav
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct stack{
	int data;
	struct stack *next;
};
struct stack *top=NULL;
struct stack *add(struct stack *);
struct stack *pop(struct stack *);
void display(struct stack *);
void main()
{
	int ch;int t=1;
	while(t)
	{
		printf("1.add\n2.pop\n3.display\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:top=add(top);
				break;
		case 2:top=pop(top);
				break;
		case 3:display(top);
				break;
		default:printf("Wrong choice\n");
		}
		printf("continue 1\n");
		scanf("%d",&t);
	}
}
struct stack *add(struct stack *top)
{
	struct stack *new;
	new=(struct stack *)malloc(sizeof(struct stack));
	int val;
	printf("Enter the value\n");
	scanf("%d",&val);
	new->data=val;
	if(top==NULL)
	{
		new->next=NULL;
		top=new;
	}
	else
	{
		new->next=top;
		top=new;
	}
	return top;
}
struct stack *pop(struct stack *top)
{
	struct stack *ptr;
	if(top==NULL)
		printf("Underflow");
	else
	{
		ptr=top;
		top=ptr->next;
		free(ptr);
	}
		return top;
}
void display(struct stack *top)
{
	struct stack *ptr;
	ptr=top;
	while(ptr->next!=NULL)
	{
		printf("%d",ptr->data);
		ptr=ptr->next;
	}
	printf("%d",ptr->data);
}
