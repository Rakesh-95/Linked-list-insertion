#include<stdio.h>
#include<conio.h>
typedef struct linked_list
{
	int info;
	struct linked_list *link;
}node;
node *head,*last;
void empty()
{
	head=NULL;
}
void insert()
{
	node *ptr=(node*) malloc(sizeof(node));
	scanf("%d",&ptr->info);
	if(head==NULL)
		head=last=ptr;
	else
	{
		last->link=ptr;
		last=ptr;
	}
	ptr->link=NULL;
}
void traversal()
{
	node *ptr=head;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->info);
		ptr=ptr->link;
	}
}
void insert_beg(int item)
{
	node *ptr;
	ptr=(node*) malloc(sizeof(node));
	ptr->info=item;
	ptr->link=head;
	head=ptr;
}
void insert_end(int item)
{
	node *ptr,*loc;
	ptr=(node*) malloc(sizeof(node));
	ptr->info=item;
	if(head==NULL)
	{
		head=ptr;
		ptr->link=NULL;
	}
	else
	{
		loc=head;
		while(loc->link!=NULL)
		{
			loc=loc->link;
			loc->link=ptr;
			ptr->link=NULL;
		}
	}
}
node *search(int item)
{
	node *ptr=head;
	while(ptr!=NULL)
	{
		if(item==ptr->info)
		{
			return(ptr);
			ptr=ptr->link;
		 }
		 return(NULL);
	}
}
void main()
{
int i,st,end,item;
node *ptr;
clrscr();
empty();
for(i=1;i<=5;i++)
{
printf("\n enter the info of %d node : ",i);
insert();
}
printf("\nThe linked list is : ");
traversal();
printf("Enter the element to be added at start oflist : ");
scanf("%d",&st);
insert_beg(st);
printf("\n Insertion at begining of list : ");
traversal();
printf("Enter the elemnt to be added to lastof the list : ");
scanf("%d",&end);
insert_end(end);
printf("\n Insertion at end of list : ");
traversal();
printf("Enter the elemnt to be searched : ");
scanf("%d",item);
search(item);
printf("item found : %d",ptr->info);
getch();
}