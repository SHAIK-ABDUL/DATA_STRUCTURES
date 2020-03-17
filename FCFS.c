#include<stdio.h>
#include<stdlib.h>
struct node
{
	int pno;
	int at;
	int bt;
	struct node*left;
	struct node*right;
};
typedef struct node node;
node *head=NULL;


void del(node *,node *);
void fcfs(node *,int*);
void create();
struct node *getnode(int,int,int);


int main()
{
	printf("Entering into creation..\n");
	create();
	int count=0;
	fcfs(head,&count);
	printf("\n");
}

struct node *getnode(int pno,int at,int bt)
{
	node *newnode=(node*)malloc(sizeof(node));
	newnode->pno=pno;
	newnode->at=at;
	newnode->bt=bt;
	newnode->left=newnode->right=NULL;
	return newnode;
}

void create()
{
		//BINARY SEARCH TREE
	int i;
	printf("1->create\n2->discard\nEnter:");
	scanf("%d",&i);
	if(i==2) return;
	else
	{
		int pno,at,bt;
		printf("Enter the process id:");
		scanf("%d",&pno);
		printf("Enter the Arrival time:");
		scanf("%d",&at);
		printf("Enter the Burst time:");
		scanf("%d",&bt);
		if(head==NULL) head=getnode(pno,at,bt);
		else
		{
			node*temp=head;
			while(1)
			{
				if(temp->at > at && temp->left!=NULL) temp=temp->left;
				else if((temp->at < at || temp->at==at)&& temp->right!=NULL)
				temp=temp->right;
				else break;
			}
			if(temp->at > at) temp->left=getnode(pno,at,bt);
			else temp->right=getnode(pno,at,bt);
		}
		create();
	}
}

void fcfs(node *root,int *count)
{
	if(root!=NULL)
	{
		node*temp=root;
		while(root->left!=NULL)
		{
			temp=root;
			root=root->left;
		}
		if((*count)==root->at || (*count) > root->at);
		else
		{
			printf("\n\ncpu is idle for:%d",*count);
			*count=root->at;
			printf(" to %d time slot",*count);
		}
		printf("\nTime for process:%d is from %d",root->pno,*count);
		*count=*count+(root->bt);
		printf(" to %d",*count);
		del(root,temp);
		fcfs(head,count);
	}
}

void del(node *root,node *parent)
{
	if(root==parent && root->right==NULL) head=NULL;
	else if(root==parent && root->right!=NULL) head=root->right;
	else
	{
		if(root->left==NULL && root->right==NULL) parent->left=NULL;
		else parent->left=root->right;
	}
	free(root);
}
