#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

typedef struct _NODE *NODE_POINTER;

typedef struct _NODE {
  int data;
  NODE_POINTER next;
} NODE;

NODE_POINTER createLinkedList(int *, int);

void printLinkedList(NODE_POINTER);

void releaseLinkedList(NODE_POINTER *);

//
// Return the head pointer if success; Otherwise, return NULL;
//
// Add a node of value val before the first element of the linked list.
// After the insertion, the new node will be the first node of the linked list.
//
NODE_POINTER addAtHead(NODE_POINTER *head, int val);

//
// Return the head pointer if success; Otherwise, return NULL;
//
// Append a node of value val as the last element of the linked list.
//
NODE_POINTER addAtTail(NODE_POINTER *head, int val);

//
// Return the head pointer if success; Otherwise, return NULL;
//
// Add a node of value val before the indexth node in the linked list.
// If index equals the length of the linked list, the node will be appended to
// the end of the linked list. If index is greater than the length, the node
// will not be inserted.
//
NODE_POINTER addAtIndex(NODE_POINTER *head, int index, int val);

//
// Return the pointer at specific index if success; Otherwise, return NULL;
//
NODE_POINTER getAtIndex(NODE_POINTER head, int index);

//
// Return TRUE if success; Otherwise, return FALSE
// After deleting, update the head pointer to the correct value
//
bool deleteAtIndex(NODE_POINTER *head, int);

#endif
