#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>

using namespace std;

typedef struct node{
    int val;
    struct node *left;
    struct node *right;
}Node;

Node *createBinaryTree();

int main()
{
    Node *temp, *temp2, *temp3;
    
    /* create binary tree */
    Node *root=createBinaryTree();

    /* traversal */
    temp=root;

    stack <Node*> S;

    S.push(root);		/* push root onto S */

    while(!S.empty())
    {
	temp=S.top();
	S.pop();

	if(temp->left)
	    S.push(temp->left);

	if(temp->right)
	    S.push(temp->right);

	
    }
}

Node* creteNode(int val)
{
    Node *tmep;

    temp=(Node *)malloc(sizeof(Node));
    temp->left=NULL;
    temp->right=NULL;
    temp->val=val;

    return temp;
}

Node *createBinaryTree()
{
    Node *tmep, *root;

    root=createNode(0);
    root->left=createNode(1);
    root->right=createNode(2);

    root->left->left=createNode(3);
    root->left->right=createNode(4);
    root->left->right->left=createNode(6);
    root->left->right->left->left=createNode(7);

    root->right->left=createNode(5);

    return root;
}
