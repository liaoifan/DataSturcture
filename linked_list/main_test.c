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

int main(int argc, char* argv[]) {
  NODE_POINTER head = NULL;
  NODE_POINTER temp = NULL;
  int nums[1] = {0};
  int index = 0, input = 0;
  bool execution = true;
  bool success_delete = true;

  /*
  //臨時測試createLinkedList：將 nums1[] 和 nums2[] 轉成 linked list
  後，判斷2者內容是否相同 int nums1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; int
  nums2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9}; NODE_POINTER head1 = NULL, head2 =
  NULL; head1 = createLinkedList(nums1, sizeof(nums1) / sizeof(nums1[0])); head2
  = createLinkedList(nums2, sizeof(nums2) / sizeof(nums2[0]));
  if(compareLinkedList(&head1, &head2)){
    printf("2組linked list資料相同\n");
  } else {
    printf("2組linked list資料不同\n");
  }
  */

  //  /*
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
          printf("請先創建Linked List\n\n");
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
        if (head == NULL) {
          printf("請先創建Linked List\n\n");
          break;
        }
        printf("請輸入要查詢資料的index：");
        scanf("%d", &index);
        temp = getAtIndex(&head, index);
        if (temp != NULL) {
          printf("index[%d]的值是%d\n\n", index, temp->data);
        } else {
          printf("請輸入正確的index值\n\n");
        }
        break;
      case CHOICE_DeleteAtIndex:
        if (head == NULL) {
          printf("請先創建Linked List\n\n");
          break;
        }
        printf("請輸入要刪除資料的index：");
        scanf("%d", &index);
        success_delete = deleteAtIndex(&head, index);
        if (success_delete) {
          printf("已將原index[%d]資料刪除\n", index);
          printLinkedList(head);
        } else {
          printf("請輸入正確的index值\n\n");
        }
        break;
      case CHOICE_ReleaseLinkedList:
        if (head == NULL) {
          printf("請先創建Linked List\n\n");
          break;
        }
        releaseLinkedList(&head);
        printf("已將Linked List刪除\n\n");
        break;
      case CHOICE_PrintLinkedList:
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
  //  */
  return 0;
}
