#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
	int weight;
};
typedef struct node node; 
void directededge(node **,int,int);
void undirectededge(node**,int,int);
node *getnode(int,int);

int main()
{
	int data,data1,n,i,j,k;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	node *a[n],*temp;
	for(i=0;i<n;i++)
	{
		printf("Enter the data:");
		scanf("%d",&data);
		a[i]=(node*)malloc(sizeof(node));
		a[i]->data=data;
		a[i]->weight=0;
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
	int sm[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			temp=a[i]->next;
			data1=0;
			while(temp!=NULL)
			{
				if(temp->data==a[j]->data)
				{
					sm[i][j]=temp->weight;
					data1=1;
					break;
				}
				temp=temp->next;
			}
			if(data1==0 && i!=j) sm[i][j]=999;
			else if(data1==0 && i==j) sm[i][j]=0;
		}
	}


	
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(k==j || k==i || i==j);
				else 
				{
					if(sm[i][k] + sm[k][j] < sm[i][j]) sm[i][j]=sm[i][k] + sm[k][j];
				}			
			}
		}
	}
	printf("DISPLAYING UPDATED MATRIX\n");
	for(i=0;i<n;i++) printf("\t%d",a[i]->data);
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t",a[i]->data);
		for(j=0;j<n;j++)
		{
			printf("%d\t",sm[i][j]);
		}
	}
	printf("\n");
}

void undirectededge(node **a,int sv,int ev)
{
	node *temp1=NULL,*temp2=NULL;
	int i,weight;
	for(i=0;temp1==NULL || temp2==NULL;i++)
	{
		if((a[i]->data)==sv) temp1=a[i];
		else if((a[i]->data)==ev) temp2=a[i];
	}
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
	int i,weight;
	for(i=0;temp1==NULL;i++)
	{
		if((a[i]->data)==sv) temp1=a[i];
	}
	printf("Enter the weight:");
	scanf("%d",&weight);
	while(temp1->next!=NULL) temp1=temp1->next;
	temp1->next=getnode(ev,weight);
}

node *getnode(int data,int weight)
{
	node*newnode;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=NULL;
	newnode->weight=weight;
	return newnode;
}
