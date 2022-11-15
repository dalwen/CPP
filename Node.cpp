#include <iostream>
#include "Node.hpp"
using namespace std;

void push(Node **head_ref, int new_data)
{

    // 1. allocate node
    Node *new_node = new Node();

    // 2. put in the data
    new_node->data = new_data;

    // 3. Make next of new node as head
    new_node->next = (*head_ref);

    // 4. move the head to point
    // to the new node
    (*head_ref) = new_node;
}

void insertAfter(Node *prev_node, int new_data)
{
    // 1. check if the given prev_node
    // is NULL
    if (!prev_node)
    {
        cout << "The given previous node cannot be NULL";
        return;
    }

    // 2. allocate new node
    Node *new_node = new Node();

    // 3. put in the data
    new_node->data = new_data;

    // 4. Make next of new node
    // as next of prev_node
    new_node->next = prev_node->next;

    // 5. move the next of prev_node
    // as new_node
    prev_node->next = new_node;
}

void append(Node **head_ref, int new_data)
{

    // 1. allocate node
    Node *new_node = new Node();

    // 2. put in the data
    new_node->data = new_data;

    /* 3. This new node is going to be
    the last node, so make next of
    it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty,
    then make the new node as head */
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    // used in step 5
    Node *last = *head_ref;

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
    {
        last = last->next;
    }

    /* 6. Change the next of last node */
    last->next = new_node;
    return;
}

// Given a reference (pointer to pointer)
// to the head of a list and a key, deletes
// the first occurrence of key in linked list
void deleteNode(Node** head_ref, int key)
{
  
    // Store head node
    Node* temp = *head_ref;
    Node* prev = NULL;
  
    // If head node itself holds
    // the key to be deleted
    if (temp != NULL && temp->data == key) {
        
      // Changed head
        *head_ref = temp->next; 
        
      // free old head
        delete temp; 
        return;
    }
  
    // Else Search for the key to be 
    // deleted, keep track of the 
    // previous node as we need to 
    // change 'prev->next'
    else {
        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }
  
        // If key was not present in linked list
        if (temp == NULL)
            return;
  
        // Unlink the node from linked list
        prev->next = temp->next;
  
        // Free memory
        delete temp;
    }
}
  

// --------------------------- Different implemenation

// This function prints contents of
// linked list starting from head
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << " " << node->data;
        node = node->next;
    }
    cout << endl;
}

void NodeTest() 
{
    // Start with the empty list
    Node* head = NULL;
     
    // Insert 6. So linked list becomes 6->NULL
    append(&head, 6);
     
    // Insert 7 at the beginning.
    // So linked list becomes 7->6->NULL
    push(&head, 7);
     
    // Insert 1 at the beginning.
    // So linked list becomes 1->7->6->NULL
    push(&head, 1);
     
    // Insert 4 at the end. So
    // linked list becomes 1->7->6->4->NULL
    append(&head, 4);
     
    // Insert 8, after 7. So linked
    // list becomes 1->7->8->6->4->NULL
    insertAfter(head->next, 8);
     
    cout<<"Created Linked list is: ";
    printList(head);

    deleteNode(&head, 6);
    cout<<"After delete Linked list is: ";
    printList(head);

}

// Function to insert an element at head position. Pass reference to head pointer
void insertathead(Node*& head, int val)
{
    Node* n = new Node(val);
    n->next = head;
    head = n;
}
 
// Function to insert a element
// at a specified position
void insertafter(Node* head, int key, int val)
{
    Node* n = new Node(val);
    if (key == head->data) {
        n->next = head->next;
        head->next = n;
        return;
    }
 
    Node* temp = head;
    while (temp->data != key) {
        temp = temp->next;
        if (temp == NULL) {
            return;
        }
    }
    n->next = temp->next;
    temp->next = n;
}
 
// Function to insert an element at the end. Pass reference to head pointer
void insertattail(Node*& head, int val)
{
    Node* n = new Node(val);
    if (head == NULL) {
        head = n;
        return;
    }
 
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

// Deletes the node containing 'info'
// part as val and alter the head of
// the linked list (recursive method)
void deleteNode(Node*& head, int val)
{
  
    // Check if list is empty or we
    // reach at the end of the
    // list.
    if (head == NULL) {
        cout << "Element not present in the list\n";
        return;
    }
  
    // If current node is the
    // node to be deleted
    if (head->data == val) {
        Node* t = head;
  
        // If it's start of the node head
        // node points to second node
        head = head->next;
  
        // Else changes previous node's
        // link to current node's link
        delete (t);
        return;
    }
    deleteNode(head->next, val);
}
 
// Function to print the
// singly linked list
void print(Node*& head)
{
    Node* temp = head;
 
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void NodeTest1() 
{
    // Declaring an empty linked list
    Node* head = NULL;
 
    insertathead(head, 1);
    insertathead(head, 2);
    cout << "After insertion at head: ";
    print(head);
    cout << endl;
 
    insertattail(head, 4);
    insertattail(head, 5);
    cout << "After insertion at tail: ";
    print(head);
    cout << endl;
 
    insertafter(head, 1, 2);
    insertafter(head, 5, 6);
    cout << "After insertion at a given position: ";
    print(head);
    cout << endl;

    deleteNode(head, 4);
    cout << "After deletion at a given position: ";
    print(head);
    cout << endl;
}