#include <stdio.h>

#include "linked_list.h"

int main(int argc, char* argv[]) {
  NODE_POINTER head;
  int nums[] = {1, 2, 3, 4};

  head = createLinkedList(nums, sizeof(nums) / sizeof(nums[0]));
  printLinkedList(head);

  printf("原始：%p\n", head);
  releaseLinkedList(&head);
  head = NULL;
  printf("釋放：%p\n", head);

  return 0;
}
