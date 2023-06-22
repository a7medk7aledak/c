#include<iostream>
using namespace std;
class Node
{
public:
	int data;
	Node * next;
};

void printList(Node* n)
{
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

void push(Node** head_ref, int new_data)
{
    /* 1. allocate node */
    Node* new_node = new Node();
 
    /* 2. put in the data */
    new_node->data = new_data;
 
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);
 
    /* 4. move the head to point to the new node */
    (*head_ref) = new_node;
}

bool search(Node* head, int x)
{
    Node* current = head; // Initialize current
    while (current != NULL)
    {
        if (current->data == x)
            return true;
        current = current->next;
    }
    return false;
}

main()
{
	Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
 
    // allocate 3 nodes in the heap
    head = new Node();
    second = new Node();
    third = new Node();
 
    /* Three blocks have been allocated dynamically.
    We have pointers to these three blocks as head,
    second and third    
    head         second         third
        |             |             |
        |             |             |
    +---+-----+     +----+----+     +----+----+
    | # | # |     | # | # |     | # | # |
    +---+-----+     +----+----+     +----+----+
     
# represents any random value.
Data is random because we haven’t assigned
anything yet */
 
    head->data = 1; // assign data in first node
    head->next = second; // Link first node with
    // the second node
 
    /* data has been assigned to the data part of first
    block (block pointed by the head). And next
    pointer of the first block points to second.
    So they both are linked.
 
    head         second         third
        |             |             |
        |             |             |
    +---+---+     +----+----+     +-----+----+
    | 1 | o----->| # | # |     | # | # |
    +---+---+     +----+----+     +-----+----+    
*/
 
    // assign data to second node
    second->data = 2;
 
    // Link second node with the third node
    second->next = third;
 
    /* data has been assigned to the data part of the second
    block (block pointed by second). And next
    pointer of the second block points to the third
    block. So all three blocks are linked.
     
    head         second         third
        |             |             |
        |             |             |
    +---+---+     +---+---+     +----+----+
    | 1 | o----->| 2 | o-----> | # | # |
    +---+---+     +---+---+     +----+----+     */
 
    third->data = 3; // assign data to third node
    third->next = NULL;
 
    /* data has been assigned to the data part of the third
    block (block pointed by third). And next pointer
    of the third block is made NULL to indicate
    that the linked list is terminated here.
 
    We have the linked list ready.
 
        head    
            |
            |
        +---+---+     +---+---+     +----+------+
        | 1 | o----->| 2 | o-----> | 3 | NULL |
        +---+---+     +---+---+     +----+------+    
     
     
    Note that only the head is sufficient to represent
    the whole list. We can traverse the complete
    list by following the next pointers. */
   printList(head); 
   cout<<endl;
   push(&head, 7);
   push(&head, 15);
   push(&head, 6);
   printList(head);
   cout<<endl;
   bool f=search(head,20);
  if(f==true)
  cout<<"found";
  else
   cout<<"not found";
}