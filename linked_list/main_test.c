#include <stdio.h>
#include <unistd.h>

#include "linked_list.h"

enum choice {
  CHOICE_CreatLinkedList,
  CHOICE_AddAtHead,
  CHOICE_AddAtIndex,
  CHOICE_AddAtTail,
  CHOICE_GetAtIndex,
  CHOICE_DeleteAtIndex,
  CHOICE_ReleaseLinkedList,
  CHOICE_Exit,
};

int main(int argc, char* argv[]) {
  int nums[1] = {0};
  NODE_POINTER head = NULL;

  int input = 0;
  bool execution = true;

  while (execution) {
    printf(
        "請輸入數值以執行功能：\n0. Creat Linked List\n1. Add at Head\n2. Add "
        "at Index\n3. Add at Tail\n4. Get at Index\n5. Delete at Index\n6. "
        "Release Linked List\n7. Exit\n");
    scanf("%d", &input);
    switch (input) {
      case CHOICE_CreatLinkedList:
        if (head == NULL) {
          printf("請輸入Linked List的第1個數值：");
          scanf("%d", nums);
          head = createLinkedList(nums, sizeof(nums) / sizeof(nums[0]));
          printLinkedList(head);
        } else {
          printf("Linked List已經存在\n\n");
        }
        break;
      case CHOICE_AddAtHead:
        if (head != NULL) {
          printf("請輸入要加在頭端的值：");
          scanf("%d", &input);
          addAtHead(&head, input);
          printLinkedList(head);
        } else {
          printf("請先創建Linked List\n\n");
        }
        break;
      case CHOICE_AddAtIndex:
        if (head != NULL) {
          int index = 0;
          printf("請輸入要插入的index：");
          scanf("%d", &index);
          printf("請輸入要插入的值：");
          scanf("%d", &input);
          if (addAtIndex(&head, index, input) != NULL) {
            printLinkedList(head);
          } else {
            printf("請確定輸入的index是否有效\n\n");
          }
        } else {
          printf("請先創建Linked List\n\n");
        }
        break;
      case CHOICE_AddAtTail:
        if (head != NULL) {
          printf("請輸入要加在尾端的值：");
          scanf("%d", &input);
          addAtTail(&head, input);
          printLinkedList(head);
        } else {
          printf("請先創建Linked List\n\n");
        }
        break;
      case CHOICE_GetAtIndex:
        printf("功能開發中\n\n");
        break;
      case CHOICE_DeleteAtIndex:
        printf("功能開發中\n\n");
        break;
      case CHOICE_ReleaseLinkedList:
        releaseLinkedList(&head);
        printf("已將Linked List刪除\n\n");
        break;
      case CHOICE_Exit:
        printf("程式結束...\n\n");
        execution = false;
        break;
      default:
        printf("請輸入有效的值\n\n");
    }
  }
  return 0;
}
