#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
	int weight;
	int dis;
	int visit;
};
typedef struct node node; 
void directededge(node **,int,int);
void undirectededge(node **,int,int);
node *getnode(int,int);
void display(node **,int);
void update(node**,int,int,int);
void dfs(node**,int *,int,int,int *);
int ismem(int*,int *,int);
node *makevisit(node **,int,int);


int main()
{
	int data,data1,n,i,j,dis,s;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	node *a[n],*b[n-1];
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
		a[i]->visit=-1;
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
	makevisit(a,n,a[0]->data);
	temp=a[0];
	temp1=temp->next;
	while(temp1!=NULL)
		{
			s=(temp->dis)+(temp1->weight);
			if(s < temp1->dis && temp1->visit==-1) update(a,temp1->data,n,s);
			temp1=temp1->next;
		}
		
	while(1)
	{
		temp=NULL;
		dis=999;
		for(i=0;i<n;i++)
		{
			temp1=a[i]->next;
			while(temp1!=NULL)
			{
				if(temp1->visit==-1 && (dis > temp1->dis) )
				{
					temp=temp1;
					dis=temp1->dis;
				}
				temp1=temp1->next;
			}
		}
		if(temp!=NULL)
		{
			temp=makevisit(a,n,temp->data);
			temp1=temp->next;
			while(temp1!=NULL)
			{
				s=(temp->dis)+(temp1->weight);
				if(s < temp1->dis && temp1->visit==-1) update(a,temp1->data,n,s);
				temp1=temp1->next;
			}
		}
		else
		{
			printf("AFTER CALCULATING WEIGHT(DIJIKSTRA)");
			printf("SOURCE:%d\n\n",a[0]->data);
			for(i=0;i<n;i++) printf("DESTINATION:%d && ITS WEIGHT:%d\n",a[i]->data,a[i]->dis);
			break;
		}
	}

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
	int weight;
	printf("Enter the weight:");
	scanf("%d",&weight);
	while(temp1->next!=NULL) temp1=temp1->next;
	temp1->next=getnode(ev,weight);
	while(temp2->next!=NULL) temp2=temp2->next;
	temp2->next=getnode(sv,weight);
}

void directededge(node **a,int sv,int ev)
{
	node *temp1=NULL;
	int i;
	for(i=0;temp1==NULL;i++)
	{
		if((a[i]->data)==sv) temp1=a[i];
	}
	int weight;
	printf("Enter the weight:");
	scanf("%d",&weight);
	while(temp1->next!=NULL) temp1=temp1->next;
	temp1->next=getnode(ev,weight);
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
node *makevisit(node **a,int n,int data)
{
	int i;
	node *temp,*temp1;
	for(i=0;i<n;i++)
	{
		temp1=a[i];
		if(a[i]->data==data) temp=a[i];
		while(temp1!=NULL)
		{
			if(temp1->data == data)
			{
				temp1->visit=0;
			}
			temp1=temp1->next;
		}
	}
	return temp;
}



node *getnode(int data,int weight)
{
	node*newnode;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=NULL;
	newnode->weight=weight;
	newnode->dis=999;
	newnode->visit=-1;
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
			printf("%d(%d)(%d) ",temp->data,temp->dis,temp->visit);
			temp=temp->next;
		}
	}
	printf("\n");	
}
