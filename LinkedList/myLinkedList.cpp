// #include <iostream>


// using namespace std;

// // // A linked list node
// // struct Node
// // {
// //     int data;
// //     struct Node *next;
// // };

// struct Node
// {
//     int data;
//     struct Node *next;
// };

// void displayList(struct Node *node)
// {
//     while (node != NULL)
//     {
//         cout << node->data << "-->";
//         node = node->next;
//     }

//     if (node == NULL)
//         cout << "null";
// }

// //insert a new node in front of the list
// void push(struct Node **headPtr, int node_data)
// {
//     struct Node *newNode = new Node;
//     newNode->data = node_data;
//     newNode->next = *headPtr;

//     cout << "New node: " << endl; 
//     displayList(newNode);
//     cout << endl; 
//     *headPtr = newNode;
// }

// //insert new node after a given node
// void insertAfter(struct Node *prev_node, int node_data)
// {
//     /*1. check if the given prev_node is NULL */
//     if (prev_node == NULL)
//     {
//         cout << "the given previous node is required,cannot be NULL";
//         return;
//     }

//     /* 2. create and allocate new node */
//     struct Node *newNode = new Node;

//     /* 3. assign data to the node */
//     newNode->data = node_data;

//     /* 4. Make next of new node as next of prev_node */
//     newNode->next = prev_node->next;

//     /* 5. move the next of prev_node as new_node */
//     prev_node->next = newNode;
// }

// /* insert new node at the end of the linked list */
// void append(struct Node **head, int node_data)
// {
//     struct Node *newNode = new Node;
//     struct Node *last = *head;
//     newNode->data = node_data;
//     newNode->next = NULL;
//     if (*head == NULL)
//     {
//         *head = newNode;
//         return;
//     }
//     while (last->next != NULL)
//         last = last->next;

//     last->next = newNode;
//     return;
// }


// // int main()
// // {
// //     /* empty list */
// //     struct Node *head = NULL;

// //     // Insert 10.
// //     append(&head, 10);

// //     // Insert 20 at the beginning.
// //     push(&head, 20);

// //     // Insert 30 at the beginning.
// //     // push(head, 30);

// //     // Insert 40 at the end.
// //     // append(&head, 40); 

// //     // Insert 50, after 20. 
// //     // insertAfter(head->next, 50);

// //     cout << "Final linked list: " << endl;
// //     displayList(head);

// //     return 0;
// // }