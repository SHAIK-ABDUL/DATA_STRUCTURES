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
node *getnode(int);
void display(node **,int);
void print(node**,node**,int*,int,int,int*);
void prim(node**,int);
void rem(node**,int,int,node*);

int main()
{
	int data,data1,n,i,weight;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	node *a[n];
	for(i=0;i<n;i++)
	{
		printf("Enter the data:");
		scanf("%d",&data);
		a[i]=(node*)malloc(sizeof(node));
		a[i]->data=data;
		a[i]->weight=0;
		a[i]->next=NULL;
	}
	printf("1->create link(DIRECTED)\n2->Discard\nEnter:");
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
	prim(a,n);
	printf("\n");

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
	int weight;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=NULL;
	printf("Enter the weight:");
	scanf("%d",&weight);
	newnode->weight=weight;
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

void prim(node**a,int n)
{
	node *del,*temp,*temp1;
	int i,j,sm;
	for(i=0;i<n;i++)
	{
		temp=a[i];
		while(temp->next!=NULL)
		{
			if(temp->next!=NULL&&temp->next->data==a[i]->data)
			{
				node*del=temp->next;
				temp->next=del->next;
				free(del);
				break;
			}
			temp=temp->next;
		}
	}
	
	for(i=0;i<n;i++)
	{
		if(a[i]==NULL);
		else
		{
			temp=a[i];
			while(temp->next!=NULL)
			{
				rem(a,i,n,temp);
				temp=temp->next;
			}
		}
	} 	
	printf("After removing heighest weight\n");			
	display(a,n);
	int count=0,jk=0;
	node *weight[n-1];
	printf("\n");		
	print(a,weight,&count,n,a[0]->data,&jk);
}

void print(node**a,node **weight,int *count,int n,int data,int *j)
{
	int k=0,i,basic;
	node*temp;
	printf("%d ",data);
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
		weight[*j]=temp;
		temp=temp->next;	
		(*j)++;		
	}
	basic=weight[0]->weight;
	for(i=0;i<(*j);i++)
	{
		if(weight[i]->weight < basic)
		{
			basic=weight[i]->weight;
			k=i;
		}
	}
	weight[k]->weight=9999999;
	(*count)++;
	if(n!=(*count)) print(a,weight,count,n,weight[k]->data,j);

}

void rem(node**a,int i,int n,node*temp)
{
	node *temp1,*del;
	int j=i;
	for(i=i+1;i<n;i++)
	{
		if(a[i]==NULL);
		else if(a[i]->data==temp->next->data)
		{
			temp1=a[i];
			while(temp1->next!=NULL)
			{
				if(temp1->next->data==a[j]->data)
				{
					if(temp1->next->weight > temp->next->weight)
					{
						del=temp1->next;
						temp1->next=del->next;
					}
					else
					{
						del=temp->next;
						temp->next=del->next;
					}
					free(del);
					break;
				}
				temp1=temp1->next;
			}
			break;
		}
		else;
	}
}
