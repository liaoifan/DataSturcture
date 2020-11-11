#include <stdio.h>

#include "linked_list.h"

int main(int argc, char* argv[]) {
  NODE_POINTER head;
  int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  head = createLinkedList(nums, sizeof(nums) / sizeof(nums[0]));

  printf("原始資料：  ");
  printLinkedList(head);

  addAtHead(&head, 10);
  printf("在頭加上10：");
  printLinkedList(head);

  addAtHead(&head, 20);
  printf("在頭加上20：");
  printLinkedList(head);

  addAtHead(&head, 30);
  printf("在頭加上30：");
  printLinkedList(head);

  addAtTail(&head, 10);
  printf("在尾加上10：");
  printLinkedList(head);

  addAtTail(&head, 20);
  printf("在尾加上20：");
  printLinkedList(head);

  addAtTail(&head, 30);
  printf("在尾加上30：");
  printLinkedList(head);

  addAtIndex(&head, 0, 10);
  printf("在頭加上10：");
  printLinkedList(head);

  addAtIndex(&head, 17, 123);
  printf("在尾加上123：");
  printLinkedList(head);

  printf("原始：%p\n", head);
  releaseLinkedList(&head);
  head = NULL;
  printf("釋放：%p\n", head);

  return 0;
}
