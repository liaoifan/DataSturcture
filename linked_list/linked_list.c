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
  int i = 0;
  if (head != NULL) {
    printf("head -> ");
  }
  while (head != NULL) {
    printf("[%d]%d -> ", i, head->data);
    head = head->next;
    i++;
  }
  printf("null\n\n");
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

  int linked_list_length = 1;
  NODE_POINTER temp;
  temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
    ++linked_list_length;
  }

  if (index == linked_list_length) {
    return addAtTail(head, val);
  } else if (index > 0 && index < linked_list_length) {
    NODE_POINTER insert = (NODE_POINTER)malloc(sizeof(NODE));
    insert->data = val;
    insert->next = NULL;

    NODE_POINTER find_new = *head;
    NODE_POINTER find_old = NULL;
    int counter = 0;
    while (counter != index) {
      find_old = find_new;
      find_new = find_new->next;
      counter++;
    }
    insert->next = find_new;
    find_old->next = insert;

    return *head;
  } else {
    return NULL;
  }
}

NODE_POINTER getAtIndex(NODE_POINTER head, int index) { return NULL; }

bool deleteAtIndex(NODE_POINTER *head, int index) { return NULL; }
