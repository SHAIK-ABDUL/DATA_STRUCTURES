#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
	int time;
};
typedef struct node node; 
void directededge(node **,int,int);
void undirectededge(node**,int,int);
node *getnode(int);
void display(node **,int);
void bfs(node**,int*,int);
int ismem(int *,int,int);
void dfs(node**,int*,int,int,int*);
void dfswithtime(node**,int *,int,int,int*,int*);
void ts(node**,int);
node*del(node*temp);

int main()
{
	int data,data1,n,i;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	node *a[n];
	for(i=0;i<n;i++)
	{
		printf("Enter the data:");
		scanf("%d",&data);
		a[i]=(node*)malloc(sizeof(node));
		a[i]->data=data;
		a[i]->time=0;
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
	int b[n],p[n],q[n];	
	for(i=0;i<n;i++)
	{
		b[i]=0;p[i]=0;q[i]=0;
	}
	int k=0,j=0,l=0;
	printf("\nDISPLAYING(BREATH FIRST SEARCH)\n");
	bfs(a,b,n);
	printf("\nDisplaying(DEPTH FIRST SEARCH)\n");
	dfs(a,p,a[0]->data,n,&k);
	printf("\nDFS WITH TIME");
	dfswithtime(a,q,a[0]->data,n,&j,&l);
	printf("\nDisplaying\n");
	display(a,n);
	printf("TOPLOGICAL SORTING\n");
	ts(a,n);
	printf("\n");

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
	newnode->time=0;
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
			printf("%d(%d) ",temp->data,temp->time);
			temp=temp->next;
		}
	}
	printf("\n");	
}

void bfs(node **a,int *b,int n)
{
	node *temp;
	int j=0,i=0,k=0;
	if(n==0) return;
	else b[0]=a[0]->data;
	while(i!=n)
	{
		for(k=0;k<n;k++)
		{
			if(b[i]==a[k]->data)
			{
				temp=a[k];
				break;
			}
		}

		while(temp!=NULL)
		{

			if(temp->data!=ismem(b,j,temp->data))
			{
				b[j]=temp->data;
				j++;
				printf("%d ",temp->data);
			}
			temp=temp->next;
		}
		i++;		
	}
}

int ismem(int *a,int j,int data)
{
	int i;
	for(i=0;i<j;i++)
	{
		if(a[i]==data) return data;
	}
	return data-1;
}

void dfs(node**a,int *b,int data,int n,int*j)
{
	int i;
	node*temp=NULL;
	for(i=0;i<n;i++)
	{
		temp=a[i];
		if(temp->data==data) break;
	}
	if(temp->data!=ismem(b,*j,temp->data))
	{
			b[*j]=temp->data;
			(*j)++;
			printf("%d ",temp->data);
	}
	while(1)
	{
		temp=temp->next;
		if(temp!=NULL&&temp->data!=ismem(b,*j,temp->data)) dfs(a,b,temp->data,n,j);
		else if(temp!=NULL);
		else break;
	}
}
		
void dfswithtime(node**a,int *b,int data,int n,int*j,int *k)
{
	int i;
	node*temp=NULL,*s=NULL;
	for(i=0;i<n;i++)
	{
		temp=a[i];
		if(temp->data==data) break;
	}
	s=temp;
	if(temp->data!=ismem(b,*j,temp->data))
	{
			b[*j]=temp->data;
			(*j)++;
			(*k)++;
	}
	while(1)
	{
		temp=temp->next;
		if(temp!=NULL&&temp->data!=ismem(b,*j,temp->data))
	    	dfswithtime(a,b,temp->data,n,j,k);
		else if(temp!=NULL);
		else
		{
			(*k)++;
			s->time=*k;
			break;
		}			
	}
	
}

void ts(node**a,int n)
{
	int i=0,j=0,count=0,s=-123;
	node*temp;
	for(i=0;i<n;i++)
	{
		if(a[i]==NULL);
		else
		{
			count=0;
			for(j=0;j<n;j++)
			{
				if(i==j || a[j]==NULL);
				else
				{
					temp=a[j]->next;
					while(temp!=NULL)
					{
						if(a[i]->data==temp->data) count++;
						temp=temp->next;
					}
				}
			}
			if(count==0)
			{
				s=i;
				break;
			}
		}
	}
	if(s!=-123)
	{
		printf("%d ",a[s]->data);
		a[s]=del(a[s]);
		ts(a,n);
	}
}

node*del(node*temp)
{
	if(temp->next!=NULL) temp->next=del(temp->next);
	free(temp);
	return NULL;
}
