#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "stdbool.h"

NODE_POINTER createLinkedList(int nums[], int size) {
  NODE_POINTER head = (NODE_POINTER)malloc(sizeof(NODE));
  NODE_POINTER ptr_renew;

  ptr_renew = head;
  for (int i = 0; i < size; i++) {
    ptr_renew->data = nums[i];
    if (i == size - 1) {
      ptr_renew->next = NULL;
      break;
    }
    ptr_renew->next = (NODE_POINTER)malloc(sizeof(NODE));
    ptr_renew = ptr_renew->next;
  }
  return head;
}

void printLinkedList(NODE_POINTER head) {
  while (head != NULL) {
    printf("%d -> ", head->data);
    head = head->next;
  }
  printf("null\n");
}

void releaseLinkedList(NODE_POINTER *head) {
  NODE_POINTER release = *head;
  NODE_POINTER ptr_current_next;
  do {
    ptr_current_next = release->next;
    free(release);
    release = ptr_current_next;
  } while (ptr_current_next != NULL);

  *head = NULL;
}

NODE_POINTER addAtHead(NODE_POINTER *head, int val) {
  NODE_POINTER temp = (NODE_POINTER)malloc(sizeof(NODE));
  temp->data = val;
  temp->next = *head;
  *head = temp;
  return *head;
}

NODE_POINTER addAtTail(NODE_POINTER *head, int val) {
  NODE_POINTER temp = (NODE_POINTER)malloc(sizeof(NODE));
  temp->data = val;
  temp->next = NULL;

  NODE_POINTER find = *head;
  while (find->next != NULL) {
    find = find->next;
  }
  find->next = temp;

  return *head;
}

NODE_POINTER addAtIndex(NODE_POINTER *head, int index, int val) {
  if (index == 0) {
    return addAtHead(head, val);
  }

  int counter = 1;
  NODE_POINTER temp = (NODE_POINTER)malloc(sizeof(NODE));
  temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
    ++counter;
  }

  if (index == counter) {
    return addAtTail(head, val);
  } else if (index > 0 && index < counter) {
    //		temp->data = val;

  } else {
    return NULL;
  }
}

NODE_POINTER getAtIndex(NODE_POINTER head, int index) {}

bool deleteAtIndex(NODE_POINTER *head, int index) {}
