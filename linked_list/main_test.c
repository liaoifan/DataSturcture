#include <stdio.h>

#include "linked_list.h"

int main(int argc, char* argv[]) {
  NODE_POINTER head;
  int nums[] = {1, 2, 3, 4, 5};

  head = createLinkedList(nums, sizeof(nums) / sizeof(nums[0]));

  printf("原始資料：\n");
  printLinkedList(head);

  addAtHead(&head, 10);
  printf("在頭加上10：\n");
  printLinkedList(head);

  addAtHead(&head, 20);
  printf("在頭加上20：\n");
  printLinkedList(head);

  addAtTail(&head, 10);
  printf("在尾加上10：\n");
  printLinkedList(head);

  addAtTail(&head, 20);
  printf("在尾加上20：\n");
  printLinkedList(head);

  addAtIndex(&head, 3, 4);
  printf("在index[3]加上4：\n");
  printLinkedList(head);

  addAtIndex(&head, 1, 11);
  printf("在index[1]加上11：\n");
  printLinkedList(head);

  addAtIndex(&head, 11, 14);
  printf("在index[11]加上14：\n");
  printLinkedList(head);

  printf("原始：%p\n", head);
  releaseLinkedList(&head);
  head = NULL;
  printf("釋放：%p\n", head);

  return 0;
}
