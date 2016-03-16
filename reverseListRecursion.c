#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int val;
	struct node *next;
}Node;

void printList(Node *root);
Node* reverseList(Node *n);

int main()
{
	int i;
	Node *temp=NULL,*temp2=NULL, *root;
	
	for(i=0;i<4;i++)
	{
		temp2=temp;
		temp=(Node *)malloc(sizeof(Node));
		
		if(i==0)
			root=temp;
		
		temp->val=i+1;
		temp->next=NULL;
		
		if(temp2)
			temp2->next=temp;
	}
	
	printList(root);
	
	root=reverseList(root);
	printList(root);
	
	return 0;
}

void printList(Node *root)
{
	Node *temp=root;
	
	while(temp!=NULL)
	{
		printf("%d->",temp->val);
		temp=temp->next;
	}
	
	printf("NULL\n");
}

Node* reverseList(Node *n)
{
	//printf("-rList: %d\n",n->val);//d
	if(n->next==NULL)
		return n;
		
	Node *temp=reverseList(n->next);
	Node *temp2=temp;
	Node *h=temp;
	
	while(temp!=NULL)
	{
		temp2=temp;
		temp=temp->next;
	}
	
	//printf("-temp2:%d   n:%d   h:%d\n",temp2->val,n->val,h->val);//d
	temp2->next=n;
	n->next=NULL;
	
	return h;
}

