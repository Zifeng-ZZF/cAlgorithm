#include <iostream>
#include "node.h"

void displayList(struct Node *node)
{
    while (node != NULL)
    {
        std::cout << node->data << "-->";
        node = node->next;
    }

    if (node == NULL)
        std::cout << "null\n";
}

//insert a new node in front of the list
void push(struct Node **headPtr, int node_data)
{
    struct Node *newNode = new Node;
    newNode->data = node_data;
    newNode->next = *headPtr;
    *headPtr = newNode;
}

//insert new node after a given node
void insertAfter(struct Node *prev_node, int node_data)
{
    if (prev_node == NULL)
    {
        std::cout << "the given previous node is required,cannot be NULL";
        return;
    }
    struct Node *newNode = new Node;
    newNode->data = node_data;
    newNode->next = prev_node->next;
    prev_node->next = newNode;
}

/* insert new node at the end of the linked list */
void append(struct Node **head, int node_data)
{
    struct Node *newNode = new Node;
    struct Node *last = *head;
    newNode->data = node_data;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = newNode;
    return;
}


/*
reversing linked list: recurssion & iteration
*/
struct Node* reverse(struct Node* headPtr)
{
    if (headPtr == NULL || headPtr->next == NULL)
    {
        return headPtr;
    }
    struct Node* newHead = reverse(headPtr->next); 
    headPtr->next->next = headPtr;
    headPtr->next = NULL;
    // Once new header was found, it will be returned to the previous case until reach the first
    return newHead;
}

struct Node* reverse2(struct Node *headPtr)
{
    if(headPtr == NULL || headPtr->next == NULL)
    {
        return headPtr;
    }
    //Two pointers, one save the previous, one modified current head
    struct Node* previ = NULL; // previous of the first one is null
    struct Node* temp = headPtr; // align head and temp
    while (headPtr != NULL)
    {
        headPtr = headPtr->next; // move head forward
        temp->next = previ; // head is safe, temp turns next to previous
        previ = temp; // previous is safe, move previ forward
        temp = headPtr; // align temp and head (or locate head)
    }
    return previ;   
}

// remove all val from a linked list
struct Node* removeElements(struct Node *head, int val)
{
    if (head == NULL)
    {
            return head;
    }
    struct Node* curr = head;
    struct Node* prev = NULL;
    while (curr != NULL)
    {
        if (curr->data == val)
        {
            if (prev == NULL)
            {
                curr = curr->next;
                head = curr;
            }
            else
            {
                prev->next = curr->next;
                curr = curr->next;
            }
        }
        else
        {
            prev = curr;
            curr = curr->next;  
        }
    }
    return head;
}

int main()
{
    struct Node *head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);

    // displayList(head);

    // head = reverse(head);

    // displayList(head);

    // head = reverse2(head);

    // displayList(head);

    struct Node* temp = head;
    std::cout << temp->data << std::endl;
    head = head->next;
    std::cout << temp->data << std::endl;
}