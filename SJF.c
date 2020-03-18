#include<stdio.h>
#include<stdlib.h>
struct node
{
	int pno;	
	int at;
	int bt;
	struct node *next;
	struct node *prev;
};
typedef struct node node;
node *head=NULL,*last=NULL;
void sjf(node*,int *);
struct node *getnode(int,int,int,node*);
void del(node *);
void create();

int main()
{
	printf("Enteering into creation...\n");
	create();
	int count=0;
	sjf(head,&count);
	printf("\n");
}

node *getnode(int pno,int at,int bt,node*prev)
{
		node*newnode=(node*)malloc(sizeof(node));
		newnode->at=at;
		newnode->bt=bt;
		newnode->pno=pno;
		newnode->prev=prev;
		newnode->next=NULL;
		return newnode;
}



void create()
{
	//LINKED LIST
	int i;
	printf("1->Enter\n2->Discard\nEnter:");
	scanf("%d",&i);
	if(i==2) return;
	else
	{
		int pno,at,bt;
		printf("Enter the pno:");
		scanf("%d",&pno);
		printf("Enter the at:");
		scanf("%d",&at);
		printf("Enter the bt:");
		scanf("%d",&bt);
		if(head==NULL)
		{
			head=(node*)malloc(sizeof(node));
			head->prev=head->next=NULL;
			head->pno=pno;
			head->at=at;
			head->bt=bt;
			last=head;
		}
		else
		{
			last->next=getnode(pno,at,bt,last);
			last=last->next;
		}
		create();
	}
}

void sjf(node*root,int *count)
{
	if(head!=NULL)
	{
		node*temp=head,*par=NULL,*par1=NULL;
		int abt=head->bt,time=999;
		while(temp!=NULL)
		{
			if(temp->bt <= abt && temp->at<=(*count))
			{
				if(par==NULL)	par=temp;
				else if(par->bt==temp->bt)
				{
					if(par->at > temp->at) par=temp;
				}
				else if(par->bt > temp->bt) par=temp;
				abt=temp->bt;
			}
			
			else if(temp->at < time && par==NULL)
			{
				par1=temp;
				time=temp->at;
			}
			temp=temp->next;
		}
		if(par==NULL)
		{
			printf("\ncpu is idle for:%d to %d",*count,par1->at);
			*count=par1->at;
			printf("\nTime for process:%d is from %d to %d",par1->pno,*count,*count+(par1->bt));
			*count=*count+(par1->bt);
			del(par1);
		}
		else
		{
			printf("\nTime for process:%d is from %d to %d",par->pno,*count,*count+(par->bt));
			*count=*count+(par->bt);
		  del(par);
		}
		sjf(head,count);
	}
}

void del(node *par)
{
	if(par==head && par->next==NULL) 	head=NULL;
	else if(par==head && par->next!=NULL) 
	{
		head=par->next;
		head->prev=NULL;	
	}
	else if(par->next==NULL)
	{
		par->prev->next=NULL;
	}
	else
	{
		par->next->prev=par->prev;
		par->prev->next=par->next;
	}
	free(par);
}
