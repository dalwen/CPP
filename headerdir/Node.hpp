#include <iostream>
class Node {
public:
    int data;
    Node* next;

    Node() {}

    // A constructor is called here
    Node(int value)
    {
 
        // It automatically assigns the
        // value to the data
        data = value;
 
        // Next pointer is pointed to NULL
        next = NULL;
    }
};

// Given a reference (pointer to pointer)
// to the head of a list and an int, inserts
// a new node on the front of the list.
void push(Node** head_ref, int new_data);

// Given a node prev_node, insert a new 
// node after the given prev_node
void insertAfter(Node* prev_node, int new_data);

// Given a reference (pointer to pointer) 
// to the head of a list and an int,
// appends a new node at the end
void append(Node** head_ref, int new_data);

void NodeTest();

void NodeTest1();
