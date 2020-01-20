#include <iostream>



struct Node
{
    int data;
    struct Node *next;
};

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
    return newHead;
}

struct Node* reverse2(struct Node *headPtr)
{
    if(headPtr == NULL || headPtr->next == NULL)
    {
        return headPtr;
    }
    //Two pointers
    struct Node* previ = NULL;
    struct Node* temp = headPtr;
    while (headPtr != NULL)
    {
        headPtr = headPtr->next;
        temp->next = previ;
        previ = temp;
        temp = headPtr;
    }
    return previ;   
}

/*

*/
struct Node* sort(struct Node *headPrt)
{

    return NULL;
}

int main()
{
    struct Node *head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);

    displayList(head);

    head = reverse(head);

    displayList(head);

    head = reverse2(head);

    displayList(head);
}