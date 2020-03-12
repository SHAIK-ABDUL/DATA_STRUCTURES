#include<stdio.h>
#include<stdlib.h>
void vertex(int b[][6],int,int);

int main()
{
	int i,j,n,sv,ev;
	printf("Enter the no of inputs:");
	scanf("%d",&n);
	int a[n];
	int b[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++) b[i][j]=0;
	}
	for(i=0;i<n;i++)
	{
		printf("Enter the %d input:",i+1);
		scanf("%d",&a[i]);
	}
	printf("1->Create vertex\n2->Discard\nEnter:");
	scanf("%d",&i);
	while(i==1)
	{
	printf("Enter the starting vertex:");
	scanf("%d",&sv);
	printf("Enter the ending vertex:");
	scanf("%d",&ev);
	for(j=0;j<n;j++)
	{
		if(a[j]==sv) sv=j;
		else if(a[j]==ev) ev=j;
	}
	b[sv][ev]=1;
	b[ev][sv]=1;
	printf("1->Create vertex\n2->Discard\nEnter:");
	scanf("%d",&i);
	}
	printf("Displaying\n");
	for(i=0;i<n;i++)
	{
		printf("%d-> ",a[i]);
		for(j=0;j<n;j++) printf("%d ",b[i][j]);
		printf("\n");
	}
}

void vertex(int b[][6],int sv,int ev)
{
		b[sv][ev]=1;
		b[ev][sv]=1;
}
