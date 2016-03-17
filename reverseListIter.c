/* Reverse a Linked List using iteration */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int val;
    struct node *next;
} Node;

void printList (Node *root);
Node* reverseListIteration (Node *);

int main()
{
    int i;
    Node *temp = NULL, *temp2 = NULL, *root;

    /* create a linked list */
    for (i = 0; i < 4; i++)
    {
        temp2 = temp;
        temp = (Node *) malloc (sizeof (Node));

        if (i == 0)
            root = temp;

        temp->val = i + 1;
        temp->next = NULL;

        if (temp2)
            temp2->next = temp;
    }

    printList (root);

    root = reverseListIteration (root);

    printList (root);

    return 0;
}

Node* reverseListIteration (Node *head)
{
    Node *temp, *prev, *next;

    if (head == NULL)
        return NULL;

    prev = head;
    temp = prev->next;

    while (temp != NULL)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }

    return prev;
}
