/* http://www.geeksforgeeks.org/reverse-alternate-k-nodes-in-a-singly-linked-list/ */

#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef struct node {
    int val;
    struct node *next;
} Node;

Node *createList (int);
void reverseKnodes (Node *first, int K, Node **begin, Node **end, Node **nextNode);
void printList (Node *nd);

int main()
{
    Node *first = createList (10);
    printList (first); //d

    Node *temp = NULL, *temp2 = NULL, *begin = NULL, *end = NULL, *nextNode = NULL;
    int i, K;

    K = 6;			/* size of sub-segment */

    temp = first;

    while (temp)
    {
        reverseKnodes (temp, K, &begin, &end, &nextNode);

        /* rejoin end of sub-linked list */
        end->next = nextNode;

        if (temp2)
            temp2->next = begin;
        else
            first = begin;	    /* will be executed in the very first
				       iteration of this loop, so as to mark the
				       beginning of the reversed list */

        temp2 = temp;		/* temp2 marks the node previous to temp
				   (which is the current node) */
        temp = nextNode;


        /* move forward K nodes, as only alternate
           K-node blocks need to be reversed */
        for (i = 0; i < K && temp; i++)
        {
            temp2 = temp;
            temp = temp->next;
        }
    }
    printList (first);

    return 0;
}

void reverseKnodes (Node *first, int K, Node **begin, Node **end, Node **nextNode)
{
    Node *temp = first, *temp2 = NULL, *temp3 = NULL;
    *end = first;		/* first node will be last
				   in reversed list */
    int i = 0;

    while (temp)
    {
        *begin = temp;

        temp3 = temp->next;
        temp->next = temp2;

        temp2 = temp;
        temp = temp3;

        if (++i == K)
            break;
    }

    *nextNode = temp;

    //printList(*begin);//d
}

Node *createList (int count)
{
    Node *temp = NULL, *newNode = NULL, *first = NULL;
    int i;

    for (i = 0; i < count; i++)
    {
        newNode = (Node *) malloc (sizeof (Node));
        newNode->val = i + 1;
        newNode->next = NULL;

        if (i == 0)
            first = newNode;

        if (temp)
            temp->next = newNode;

        temp = newNode;
    }

    return first;
}

void printList (Node *nd)
{
    Node *temp = nd;

    while (temp)
    {
        printf ("%d -> ", temp->val);
        temp = temp->next;
    }

    printf ("NULL\n");
}
