#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
	int weight;
};

struct sorting
{
	int a;
	int b;
	int weight;
};

struct arr
{
	int val;
	int parent;
};

typedef struct sorting sort;
typedef struct arr arr;
typedef struct node node;
 
void directededge(node **,int,int);
node *getnode(int);
void display(node **,int);
void heighest(node**,int);
void kruskal(node **,arr *,int);
void rem(node**,int,int,node*);
void print(arr *,int,int,int);

int main()
{
	int data,data1,n,i,weight,sm=0;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	node *a[n];
	arr r[n];
	for(i=0;i<n;i++)
	{
		printf("Enter the data:");
		scanf("%d",&data);
		a[i]=(node*)malloc(sizeof(node));
		a[i]->data=data;
		a[i]->weight=0;
		a[i]->next=NULL;
	  	r[i].val=data;
		r[i].parent=-1;
	}
	printf("1->create link(DIRECTED)\n2->Discard\nEnter:");
	scanf("%d",&i);
	while(i==1)
	{
		sm++;
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
	heighest(a,n);	
	kruskal(a,r,n);
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

void heighest(node**a,int n)
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

void kruskal(node **a,arr *b,int n)
{
	sort r[n*(n-1)],key;
	node *temp;
	int m=0,j=0,i=0;
	for(i=0;i<n;i++)
	{
		temp=a[i]->next;
		while(temp!=NULL)
		{
			r[m].a=a[i]->data;
			r[m].b=temp->data;
		  	r[m].weight=temp->weight;
			m++;
			temp=temp->next;
		}
	}
	for(i=0;i<m-1;i++)
	{
		key=r[i+1];
		j=i;
		while(j>=0 && (key.weight <= r[j].weight))
		{
			r[j+1]=r[j];
			r[j]=key;
			j--;
		}
	}
	printf("After sorting\n");
	for(i=0;i<m;i++)
	{
		printf("src %d des %d weight %d\n",r[i].a,r[i].b,r[i].weight);
	}
	printf("\nDISPLAYING BY KRUSKAL ALGORITHM\n");
	for(i=0;i<m;i++)
	{
		print(b,r[i].a,r[i].b,n);
	}
}

void print(arr *s,int a,int b,int n)
{
	int temp1=-123,temp2=-123,i=0,j=0;
	for(i=0;temp1==-123 || temp2==-123;i++)
	{
		if(s[i].val==a) temp1=i;
		else if(s[i].val==b) temp2=i;
	}
	if((s[temp1].parent==-1) && (s[temp2].parent==-1))
	{
		printf("%d %d ",s[temp1].val,s[temp2].val);
		s[temp1].parent=-2;
		s[temp2].parent=temp1;
	}
	else
	{
		if(s[temp1].parent==-1) printf("%d ",s[temp1].val);
		else if (s[temp2].parent==-1) printf("%d ",s[temp2].val);
		i=temp1;
		j=temp2;
		temp1=s[temp1].parent;
		temp2=s[temp2].parent;
		while(temp1>=0)
		{
			i=temp1;
			temp1=s[temp1].parent;
		}
		while(temp2>=0)
		{
			j=temp2;
			temp2=s[temp2].parent;
		}
		if(temp1==temp2);
		else
		{
			if(temp2>temp1)
			{
				s[j].parent=i;
				s[i].parent+=-2;
			}
			else
			{
				s[i].parent=j;
				s[j].parent+=-2;
			}
		}
	}
}
