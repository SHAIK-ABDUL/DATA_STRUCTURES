#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	int color;
	struct node*left;
	struct node*right;
	struct node*parent;
};
typedef struct node node;

node *head=NULL;
void create();
void preorder(node*);
void rturn(node*);
void lturn(node*);
void rb(node*,node*);
void del(node*,int);
void cr(node*);
int rmin(node*);

int main()
{
  create();
  printf("DISPLAYING RED-BLACK TREE\n");
  printf("0->RED 1->BLACK\n");
  preorder(head);
  int n,i,data;
  printf("NO OF ELEMENTS DELETE:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
  	printf("Enter element to delete:");
  	scanf("%d",&data);
  	del(head,data);
  	preorder(head);
  }
}

void create()
{
    int data;
    printf("Enter the data(If not enter -123):");
    scanf("%d",&data);
    if(data==-123) return;
    node*newnode;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    newnode->color=0;
    
    if(head==NULL)
    {
        head=newnode;
        head->color=1;
        head->parent=NULL;
    }
    else
    {
        node*last=head,*sibling;
        while(1)
        {
            if(last->data>data && last->left!=NULL) last=last->left;
            else if(last->data<data && last->right!=NULL) last=last->right;
            else break;
        }
        newnode->parent=last;
        if(last->data > data) last->left=newnode;
        else last->right=newnode;
        
        if(last==head) sibling=NULL;
        else if(last->parent->right==last) sibling=last->parent->left;
        else sibling=last->parent->right;
	
				rb(newnode,sibling);
    }
    create();
}

void rb(node*root,node*sibling)
{
	if(root->parent->color==1);
	else if(sibling==NULL|| sibling->color==1)
	{
		int i=0;
		char s[2];
		for(i;i!=2;i++)
		{
			if(root->parent->right==root) s[i]='l';
			else s[i]='r';
			root=root->parent;
		}
		if(s[0]=='l' && s[1]=='r')
		{
			lturn(root->left);
			rturn(root);
		}
		else if(s[0]=='r' && s[1]=='l')
		{
			rturn(root->right);
			lturn(root);
		}
		else if(s[0]=='l' && s[1]=='l') lturn(root);
		else rturn(root); 
		
		if(root->color==0) root->color=1;
		else root->color=0;
		
		if(root->parent->color==0) root->parent->color=1;
		else root->parent->color=0;
	}
	else
	{
		root->parent->color=1;
		sibling->color=1;
		
		if(root->parent->parent!=head)
		{
			node*temp=root->parent->parent;
			if(temp->color==0) temp->color=1;
			else temp->color=0;
			if(temp->parent->color==0)
			{	
				if(temp->parent->parent->right==temp->parent) sibling=temp->parent->parent->left;
				else sibling=temp->parent->parent->right;
				rb(temp,sibling);
			}	
		}
		
	}
}

void preorder(node*root)
{
    if(root!=NULL)
    {
    		printf("%d %d\n",root->data,root->color);
        preorder(root->left);        
		//	printf("%d\n",root->data);
				preorder(root->right);
    }
}

void lturn(node*root)
{
	if(root->parent==NULL) head=root->right;
	else if(root->parent->left==root) root->parent->left=root->right;
	else root->parent->right=root->right;
	root->right->parent=root->parent;
	root->parent=root->right;
	node*x=root->right->left;
	root->right->left=root;
	root->right=x;
	if(x!=NULL) x->parent=root;
}

void rturn(node*root)
{
	if(root->parent==NULL) head=root->left;
	else if(root->parent->left==root) root->parent->left=root->left;
	else root->parent->right=root->left;
	root->left->parent=root->parent;
	root->parent=root->left;
	node*x=root->left->right;
	root->left->right=root;
	root->left=x;
	if(x!=NULL) x->parent=root;
	
}

void del(node*root,int data)
{
	while(root->data!=data)
	{
		if(root->data>data) root=root->left;
		else root=root->right;
	}
	if(root->left==NULL && root->right==NULL)
	{
		if(root==head)
		{
			free(root);
			root=NULL;
			head=root;
			return;
		}
		else if(root->color==1)
		{
			cr(root);
		}
		root=root->parent;
		if(root->data>data)
		{
			free(root->left);
			root->left=NULL;
		}
		else
		{
			free(root->right);
			root->right=NULL;
		}
		
			
	}
	else if(root->left==NULL && root->right!=NULL)
	{
		root->data=root->right->data;
		if(root->right->color==0)
		{
			free(root->right);
			root->right=NULL;
		}
		else
		{
			cr(root->right);
			free(root->right);
			root->right=NULL;
		}
	}
	else if(root->right==NULL && root->left!=NULL)
	{
		root->data=root->left->data;
		if(root->left->color==0)
		{
			free(root->left);
			root->left=NULL;
		}
		else
		{
			cr(root->left);
			free(root->left);
			root->left=NULL;
		}
	}
	else
	{
		if(root->right->right==NULL&&root->right->left==NULL)
		{
			root->data=root->right->data;
			if(root->right->color==1) cr(root->right);
			free(root->right);
			root->right=NULL;
		}
		else
		{
			root->data=rmin(root->right);
			del(root->right,root->data);
		}
	}
}

void cr(node*db)
{	
	node*sib=NULL;
	if(db==head);
	else if(db->parent->left==db) sib=db->parent->right;
	else sib=db->parent->left;
	if(db!=head)
	{
		if(sib->color==1&&
		(sib->left==NULL||sib->left->color==1)
	  &&(sib->right==NULL||sib->right->color==1))
		{
			if(db->parent->color==1) db=db->parent;
			else db->parent->color=1;
			sib->color=0;
			if(db==sib->parent) cr(db);
		}
		else if(sib->color==0)
		{
			sib->color=sib->parent->color;
			sib->parent=0;
			if(db->parent->left==db) lturn(db->parent);
			else rturn(db->parent);
			cr(db);
		}
		else
		{
			if(db->parent->left==db && sib->right->color==1 && sib->left->color==0)
			{
				sib->left->color=sib->color;
				rturn(sib);
			}
			else if(db->parent->right==db && sib->left->color==1 && sib->right->color==0)
			{
				sib->right->color=sib->color;
				lturn(sib);
			}
			sib->color=0;
					
			//case:6
			int s=0;
			if(db->parent->left==db)
			{
			 sib=db->parent->right;
			 if(sib->right->color==0) s=1;
			}
			else
			{
			 sib=db->parent->left;
			 if(sib->left->color==0) s=1;
			}
			if(s)
			{
				int temp=db->parent->color;
				db->parent->color=sib->color;
				sib->color=temp;
				if(db->parent->left==db)
				{
					sib->right->color=1;
					lturn(db->parent);
				}
				else
				{
					sib->left->color=1;
					rturn(db->parent);
				}
			}
		}
	}
}

int rmin(node* root)
{
	while(root->left!=NULL) root=root->left;
	return root->data;
}
