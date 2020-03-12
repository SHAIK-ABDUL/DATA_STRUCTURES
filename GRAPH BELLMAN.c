#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
	int weight;
	int dis;
};
typedef struct node node; 
void directededge(node **,int,int);
node *getnode(int);
void display(node **,int);
void update(node**,int,int,int);
void dfs(node**,int *,int,int,int *);
int ismem(int*,int *,int);

int main()
{
	int data,data1,n,i,s,j;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	node *a[n];
	node *temp,*temp1;
	for(i=0;i<n;i++)
	{
		printf("Enter the data:");
		scanf("%d",&data);
		a[i]=(node*)malloc(sizeof(node));
		a[i]->data=data;
		a[i]->weight=0;
		a[i]->next=NULL;
		a[i]->dis=0;
	}
	printf("1->create link(DIRECTED)\n2->discard\nEnter:");
	scanf("%d",&i);
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
	printf("Displaying(Adjecancy list)\n");
	display(a,n);
	printf("\n");
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n;j++)
		{
			temp=a[j];
			temp1=temp;
			while(temp->next!=NULL)
			{
				s=(temp1->dis)+(temp->next->weight);
				if(s< temp->next->dis) update(a,temp->next->data,n,s);
				temp=temp->next;
			}
		}
	}
	int sm=0;
	for(j=0;j<n;j++)
	{
		temp=a[j];
		temp1=temp;
		while(temp->next!=NULL)
		{
			s=(temp1->dis)+(temp->next->weight);
			if(s< temp->next->dis)
			{
				printf("BELLMAN FORD ALGORITHM WILL FAIL FOR THIS GRAPH\n");
				sm=1;
				break;		
			}
			temp=temp->next;
		}
		if(sm==1) break;
	}
	if(sm==0)
  {
	    	int b[n];
				j=0;
				printf("BELLMAN FORD ALGORITHM  WORKS PERFECTLY FOR THIS GRAPH\n");
				printf("SRC:%d\n\n",a[0]->data);
				dfs(a,b,a[0]->data,n,&j);
							
	}
}

void update(node**a,int data,int n,int s)
{
	int i;
	node *temp;
	for(i=0;i<n;i++)
	{
		temp=a[i];
		while(temp!=NULL)
		{
			if(temp->data==data) temp->dis=s;
			temp=temp->next;
		}
	}
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
	int weigh;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=NULL;
	printf("Enter the weight:");
	scanf("%d",&weigh);
	newnode->weight=weigh;
	newnode->dis=999;
	return newnode;
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

void dfs(node**a,int *b,int data,int n,int *j)
{
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
	printf("DESTINATION:%d  & ITS WEIGHT:%d\n",temp->data,temp->dis);
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

