/*
 ============================================================================
 Name        : sortlinkedlist.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;
void add();
void sort();
void display();
void main()
{
	int t=1,ch;
	while(t)
	{
		printf("1.add 2.sort 3.delete\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1: add();
				break;
		case 2: sort();
				break;
		case 3: display();
				break;
		default: printf("Wrong choice");
		}
		printf("Continue 1\n");
		scanf("%d",&t);
	}
}
void add()
{
	struct node *ptr;
	int val;
	printf("Enter value\n");
	scanf("%d",&val);
	struct node *new;
	new=(struct node *)malloc(sizeof(struct node));
	new->data=val;
	if(start==NULL)
	{
		start=new;
		new->next=NULL;}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=new;
		new->next=NULL;
	}
}
void sort()
{
	int temp=0;
	struct node *ptr,*preptr;
	ptr=preptr=start;
	while(ptr->next!=NULL)
	{
		preptr=ptr;
		ptr=ptr->next;
		if(preptr->data>ptr->data)
		{
			temp=preptr->data;
			preptr->data=ptr->data;
			ptr->data=temp;
			ptr=preptr=start;
		}
		else
			continue;

	}
}
void display(){
	struct node *ptr;
	ptr=start;
	while(ptr->next!=NULL){
		printf("%d",ptr->data);
		ptr=ptr->next;
	}
	printf("%d",ptr->data);
}
