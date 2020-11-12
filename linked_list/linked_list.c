#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

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
  printf("head -> ");
  while (head != NULL) {
    printf("[%d]%d -> ", i, head->data);
    head = head->next;
    i++;
  }
  printf("NULL\n\n");
}

void releaseLinkedList(NODE_POINTER *head) {
  if (*head == NULL) {
    return;
  }

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

int LinkedList_Length(NODE_POINTER *head) {
  int length = 0;
  if (*head == NULL) {
    return length;
  }
  ++length;

  NODE_POINTER temp;
  temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
    ++length;
  }
  return length;
}

NODE_POINTER addAtIndex(NODE_POINTER *head, int index, int val) {
  if (index == 0) {
    return addAtHead(head, val);
  }

  int linked_list_length = LinkedList_Length(head);

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

NODE_POINTER getAtIndex(NODE_POINTER *head, int index) {
  int length = LinkedList_Length(head);
  if (index < 0 || index >= length) {
    return NULL;
  }
  NODE_POINTER search = *head;
  int search_index = 0;
  while (search_index != index) {
    search = search->next;
    search_index++;
  }
  return search;
}

bool deleteAtIndex(NODE_POINTER *head, int index) {
  int length = LinkedList_Length(head);
  if (index < 0 || index >= length) {
    return false;
  }

  NODE_POINTER temp = NULL;
  if (index == 0) {
    temp = (*head)->next;
    free(*head);
    *head = temp;
  } else if (index == length - 1) {
    temp = *head;
    NODE_POINTER temp_old = NULL;
    while (temp->next != NULL) {
      temp_old = temp;
      temp = temp->next;
    }
    free(temp);
    temp_old->next = NULL;
  } else {
    temp = *head;
    NODE_POINTER temp_old = NULL;
    for (int i = 0; i < index; i++) {
      temp_old = temp;
      temp = temp->next;
    }
    temp_old->next = temp->next;
    free(temp);
  }
  return true;
}

bool compareLinkedList(NODE_POINTER *head1, NODE_POINTER *head2) {
  NODE_POINTER nptr1 = *head1, nptr2 = *head2;

  if (nptr1 == NULL && nptr2 == NULL) {
    return true;
  } else if (nptr1 == NULL || nptr2 == NULL) {
    return false;
  }

  while ((nptr1 != NULL) && (nptr2 != NULL)) {
    if (nptr1->data != nptr2->data) {
      return false;
    }

    nptr1 = nptr1->next;
    nptr2 = nptr2->next;
    if ((nptr1 == NULL && nptr2 != NULL) || (nptr1 != NULL && nptr2 == NULL)) {
      return false;
    }
  }
  return true;
}
