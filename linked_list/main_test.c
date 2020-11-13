#include <stdbool.h>
#include <stdio.h>

#include "linked_list.h"

enum choice {
  CHOICE_CreatLinkedList,
  CHOICE_AddAtHead,
  CHOICE_AddAtIndex,
  CHOICE_AddAtTail,
  CHOICE_GetAtIndex,
  CHOICE_DeleteAtIndex,
  CHOICE_ReleaseLinkedList,
  CHOICE_PrintLinkedList,
  CHOICE_Exit,
};

void print_CheckIndex() { printf("請確定輸入的index是否有效\n\n"); }

void print_CreatLinkedList() { printf("請先創建Linked List\n\n"); }

int main(int argc, char* argv[]) {
  NODE_POINTER head = NULL;
  NODE_POINTER temp = NULL;
  int nums[1] = {0};
  int index = 0, input = 0;
  bool execution = true;
  bool success_delete = true;

  while (execution) {
    printf(
        "0. Creat Linked List\n1. Add at Head\n2. Add at Index\n3. Add at "
        "Tail\n4. Get at Index\n5. Delete at Index\n6. Release Linked List\n7. "
        "Print Linked List\n8. Exit\n請輸入數值以執行功能：");
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
          print_CreatLinkedList();
        }
        break;
      case CHOICE_AddAtIndex:
        if (head != NULL) {
          printf("請輸入要插入的index：");
          scanf("%d", &index);
          printf("請輸入要插入的值：");
          scanf("%d", &input);
          if (addAtIndex(&head, index, input) != NULL) {
            printLinkedList(head);
          } else {
            print_CheckIndex();
          }
        } else {
          print_CreatLinkedList();
        }
        break;
      case CHOICE_AddAtTail:
        if (head != NULL) {
          printf("請輸入要加在尾端的值：");
          scanf("%d", &input);
          addAtTail(&head, input);
          printLinkedList(head);
        } else {
          print_CreatLinkedList();
        }
        break;
      case CHOICE_GetAtIndex:
        if (head == NULL) {
          print_CreatLinkedList();
          break;
        }
        printf("請輸入要查詢資料的index：");
        scanf("%d", &index);
        temp = getAtIndex(&head, index);
        if (temp != NULL) {
          printf("index[%d]的值是%d\n\n", index, temp->data);
        } else {
          print_CheckIndex();
        }
        break;
      case CHOICE_DeleteAtIndex:
        if (head == NULL) {
          print_CreatLinkedList();
          break;
        }
        printf("請輸入要刪除資料的index：");
        scanf("%d", &index);
        success_delete = deleteAtIndex(&head, index);
        if (success_delete) {
          printf("已將原index[%d]資料刪除\n", index);
          printLinkedList(head);
        } else {
          print_CheckIndex();
        }
        break;
      case CHOICE_ReleaseLinkedList:
        if (head == NULL) {
          print_CreatLinkedList();
          break;
        }
        releaseLinkedList(&head);
        printf("已將Linked List刪除\n\n");
        break;
      case CHOICE_PrintLinkedList:
        if (head == NULL) {
          print_CreatLinkedList();
          break;
        }
        printLinkedList(head);
        break;
      case CHOICE_Exit:
        releaseLinkedList(&head);
        printf("程式結束...\n\n");
        execution = false;
        break;
      default:
        printf("請輸入有效的值\n\n");
    }
  }
  return 0;
}
