#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
};

typedef struct node node;
void directededge(node **,int,int);
node *getnode(int);
void display(node **,int);
int ismem(int*,int *,int);
void dfs(node**,int *,int,int,int *);
void undirectededge(node **,int,int);

int main()
{
	int data,data1,n,i,count=0;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	node *a[n];
	int b[n],j=0,k=0;
	for(i=0;i<n;i++)
	{
		printf("Enter the data:");
		scanf("%d",&data);
		a[i]=(node*)malloc(sizeof(node));
		a[i]->data=data;
		a[i]->next=NULL;
	}
	printf("1->create link(UNDIRECTED)\n2->create link(DIRECTED)\n3->discard\nEnter:");
	scanf("%d",&i);
if(i==1)
{
	while(i==1)
	{
		printf("Enter the starting vertex:");
		scanf("%d",&data);
		printf("Enter the ending vertex:");
		scanf("%d",&data1);
		undirectededge(a,data,data1);
		printf("1->create link\n2->discard\nEnter:");
		scanf("%d",&i);
	}
}
else if(i==2)
{
	i=1;
	while(i==1)
	{
		printf("Enter the starting vertex:");
		scanf("%d",&data);
		printf("Enter the ending vertex:");
		scanf("%d",&data1);
		directededge(a,data,data1);
		printf("1->create link\n2->discard\nEnter:");
		scanf("%d",&i);
	}
}
	printf("Displaying(Adjecancy list)\n");
	display(a,n);
	printf("\nDisplaying(data)\n");
	for(i=0;i<n;i++)
	{
		for(k=0;k<j;k++)
		{
			if(b[k]==a[i]->data) break;
		}
		if(k==j)
		{
			count++;
			dfs(a,b,a[i]->data,n,&j);
		}
	}
	printf("\nNO OF CONNECTED COMPONENETS:%d",count);
	printf("\n");
}

void dfs(node**a,int *b,int data,int n,int *j)
{
	printf("%d ",data);
	b[*j]=data;
	(*j)++;
	int i;
	node *temp;
	for(i=0;i<n;i++)
	{
		if(a[i]->data==data)
		{
			temp=a[i];
			break;
		}
	}
	temp=temp->next;
	while(temp!=NULL)
	{
		if(1!=ismem(b,j,temp->data)) dfs(a,b,temp->data,n,j);
		temp=temp->next;
	}
}

int ismem(int*b,int *j,int data)
{
	int i;
	for(i=0;i<(*j);i++)
	{
		if(b[i]==data) return 1;
	}
	return 0;
}

void directededge(node **a,int sv,int ev)
{
	node *temp1=NULL;
	int i;
	for(i=0;temp1==NULL;i++)
	{
		if((a[i]->data)==sv) temp1=a[i];
	}
	while(temp1->next!=NULL) temp1=temp1->next;
	temp1->next=getnode(ev);
}

node *getnode(int data)
{
	node*newnode;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
}

void undirectededge(node **a,int sv,int ev)
{
	node *temp1=NULL,*temp2=NULL;
	int i;
	for(i=0;temp1==NULL || temp2==NULL;i++)
	{
		if((a[i]->data)==sv) temp1=a[i];
		else if((a[i]->data)==ev) temp2=a[i];
	}
	while(temp1->next!=NULL) temp1=temp1->next;
	temp1->next=getnode(ev);
	while(temp2->next!=NULL) temp2=temp2->next;
	temp2->next=getnode(sv);
}


void display(node **a,int n)
{
	int i;
	node *temp=NULL;
	for(i=0;i<n;i++)
	{	
		printf("\n");
		temp=a[i];
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
	printf("\n");	
}
