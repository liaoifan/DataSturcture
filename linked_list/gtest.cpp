#include <time.h>

#include "gtest/gtest.h"
#include "linked_list.c"

TEST(createLinkedList, test) {
  int nums1[] = {1, 2, 3};
  int size1 = sizeof(nums1) / sizeof(nums1[0]);
  EXPECT_NE((NODE_POINTER)NULL, createLinkedList(nums1, size1));

  int nums2[] = {};
  int size2 = sizeof(nums2) / sizeof(nums2[0]);
  EXPECT_EQ((NODE_POINTER)NULL, createLinkedList(nums2, size2));

  int nums3[] = {1};
  int size3 = sizeof(nums3) / sizeof(nums3[0]);
  EXPECT_NE((NODE_POINTER)NULL, createLinkedList(nums3, size3));

  int nums4[] = {5, 6};
  int size4 = sizeof(nums4) / sizeof(nums4[0]);
  EXPECT_NE((NODE_POINTER)NULL, createLinkedList(nums4, size4));
}

TEST(printLinkedList, test) {
  //不知道要怎麼測印出來的值
}

TEST(releaseLinkedList, test) {
  int nums1[] = {1, 2, 3};
  int size1 = sizeof(nums1) / sizeof(nums1[0]);
  NODE_POINTER h1 = createLinkedList(nums1, size1);
  releaseLinkedList(&h1);
  EXPECT_EQ((NODE_POINTER)NULL, h1);

  int nums2[] = {};
  int size2 = sizeof(nums2) / sizeof(nums2[0]);
  NODE_POINTER h2 = createLinkedList(nums2, size2);
  releaseLinkedList(&h2);
  EXPECT_EQ((NODE_POINTER)NULL, h2);

  int nums3[] = {1};
  int size3 = sizeof(nums3) / sizeof(nums3[0]);
  NODE_POINTER h3 = createLinkedList(nums3, size3);
  releaseLinkedList(&h3);
  EXPECT_EQ((NODE_POINTER)NULL, h3);

  int nums4[] = {5, 6};
  int size4 = sizeof(nums4) / sizeof(nums4[0]);
  NODE_POINTER h4 = createLinkedList(nums4, size4);
  releaseLinkedList(&h4);
  EXPECT_EQ((NODE_POINTER)NULL, h4);
}

TEST(addAtHead, test) {
  int random_number = rand() % 10;  // create a random numeber 0~9

  int nums0[] = {};
  int size0 = sizeof(nums0) / sizeof(nums0[0]);
  NODE_POINTER h0 = createLinkedList(nums0, size0);
  addAtHead(&h0, random_number);
  EXPECT_EQ((NODE_POINTER)NULL, h0);

  int nums1[] = {1};
  int size1 = sizeof(nums1) / sizeof(nums1[0]);
  NODE_POINTER h1 = createLinkedList(nums1, size1);
  addAtHead(&h1, random_number);
  EXPECT_EQ(random_number, h1->data);

  int nums2[] = {5, 6};
  int size2 = sizeof(nums2) / sizeof(nums2[0]);
  NODE_POINTER h2 = createLinkedList(nums2, size2);
  addAtHead(&h2, random_number);
  EXPECT_EQ(random_number, h2->data);

  int nums3[] = {1, 2, 3};
  int size3 = sizeof(nums3) / sizeof(nums3[0]);
  NODE_POINTER h3 = createLinkedList(nums3, size3);
  addAtHead(&h3, random_number);
  EXPECT_EQ(random_number, h3->data);
}

TEST(addAtTail, test) {
  int random_number = rand() % 10;  // create a random numeber 0~9
  NODE_POINTER temp;

  int nums0[] = {};
  int size0 = sizeof(nums0) / sizeof(nums0[0]);
  NODE_POINTER h0 = createLinkedList(nums0, size0);
  addAtTail(&h0, random_number);
  EXPECT_EQ((NODE_POINTER)NULL, h0);

  int nums1[] = {1};
  int size1 = sizeof(nums1) / sizeof(nums1[0]);
  NODE_POINTER h1 = createLinkedList(nums1, size1);
  addAtTail(&h1, random_number);
  temp = h1;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  EXPECT_EQ(random_number, temp->data);

  int nums2[] = {5, 6};
  int size2 = sizeof(nums2) / sizeof(nums2[0]);
  NODE_POINTER h2 = createLinkedList(nums2, size2);
  addAtTail(&h2, random_number);
  temp = h2;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  EXPECT_EQ(random_number, temp->data);

  int nums3[] = {1, 2, 3};
  int size3 = sizeof(nums3) / sizeof(nums3[0]);
  NODE_POINTER h3 = createLinkedList(nums3, size3);
  addAtTail(&h3, random_number);
  temp = h3;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  EXPECT_EQ(random_number, temp->data);
}

TEST(LinkedList_Length, test) {
  int nums0[] = {};
  int size = sizeof(nums0) / sizeof(nums0[0]);
  NODE_POINTER h0 = createLinkedList(nums0, size);
  EXPECT_EQ(size, LinkedList_Length(&h0));

  int nums1[] = {1};
  size = sizeof(nums1) / sizeof(nums1[0]);
  NODE_POINTER h1 = createLinkedList(nums1, size);
  EXPECT_EQ(size, LinkedList_Length(&h1));

  int nums2[] = {5, 6};
  size = sizeof(nums2) / sizeof(nums2[0]);
  NODE_POINTER h2 = createLinkedList(nums2, size);
  EXPECT_EQ(size, LinkedList_Length(&h2));

  int nums3[] = {1, 2, 3};
  size = sizeof(nums3) / sizeof(nums3[0]);
  NODE_POINTER h3 = createLinkedList(nums3, size);
  EXPECT_EQ(size, LinkedList_Length(&h3));
}

TEST(addAtIndex, test) {
  int random_number = rand() % 10;  // create a random numeber 0~9
  int size = 0, index = 0;

  int nums1[] = {1};
  index = 0;
  size = sizeof(nums1) / sizeof(nums1[0]);
  NODE_POINTER h1 = createLinkedList(nums1, size);
  addAtIndex(&h1, index, random_number);
  EXPECT_EQ(random_number, getAtIndex(&h1, index)->data);

  int nums2[] = {5, 6};
  index = 1;
  size = sizeof(nums2) / sizeof(nums2[0]);
  NODE_POINTER h2 = createLinkedList(nums2, size);
  addAtIndex(&h2, index, random_number);
  EXPECT_EQ(random_number, getAtIndex(&h2, index)->data);

  int nums3[] = {1, 2, 3};
  index = 3;
  size = sizeof(nums3) / sizeof(nums3[0]);
  NODE_POINTER h3 = createLinkedList(nums3, size);
  addAtIndex(&h3, index, random_number);
  EXPECT_EQ(random_number, getAtIndex(&h3, index)->data);
}

TEST(getAtIndex, test) {
  int size = 0;
  int index = 0;

  int nums1[] = {1};
  index = 0;
  size = sizeof(nums1) / sizeof(nums1[0]);
  NODE_POINTER h1 = createLinkedList(nums1, size);
  EXPECT_EQ(nums1[index], getAtIndex(&h1, index)->data);

  int nums2[] = {5, 6};
  index = 1;
  size = sizeof(nums2) / sizeof(nums2[0]);
  NODE_POINTER h2 = createLinkedList(nums2, size);
  EXPECT_EQ(nums2[index], getAtIndex(&h2, index)->data);

  int nums3[] = {1, 2, 3};
  index = 1;
  size = sizeof(nums3) / sizeof(nums3[0]);
  NODE_POINTER h3 = createLinkedList(nums3, size);
  EXPECT_EQ(nums3[index], getAtIndex(&h3, index)->data);
}

TEST(deleteAtIndex, test) {
  int size = 0;

  int nums1[] = {1};
  size = sizeof(nums1) / sizeof(nums1[0]);
  NODE_POINTER h1 = createLinkedList(nums1, size);
  EXPECT_EQ(false, deleteAtIndex(&h1, -1));
  EXPECT_EQ(true, deleteAtIndex(&h1, 0));

  int nums2[] = {5, 6};
  size = sizeof(nums2) / sizeof(nums2[0]);
  NODE_POINTER h2 = createLinkedList(nums2, size);
  EXPECT_EQ(false, deleteAtIndex(&h2, -1));
  EXPECT_EQ(true, deleteAtIndex(&h2, 0));

  int nums3[] = {1, 2, 3};
  size = sizeof(nums3) / sizeof(nums3[0]);
  NODE_POINTER h3 = createLinkedList(nums3, size);
  EXPECT_EQ(false, deleteAtIndex(&h3, -1));
  EXPECT_EQ(true, deleteAtIndex(&h3, 2));

  int nums4[] = {1, 2, 3, 4, 5, 6, 7, 8};
  size = sizeof(nums4) / sizeof(nums4[0]);
  NODE_POINTER h4 = createLinkedList(nums4, size);
  EXPECT_EQ(false, deleteAtIndex(&h4, -1));
  EXPECT_EQ(true, deleteAtIndex(&h4, 7));
}

TEST(compareLinkedList, test) {
  int nums0[] = {1, 2, 3, 4, 5};
  int nums1[] = {1, 2, 3, 4, 5};
  int nums2[] = {1, 2, 3, 4};
  int nums3[] = {1};
  int nums4[] = {2};
  int nums5[] = {2};

  int size = 0;
  size = sizeof(nums0) / sizeof(nums0[0]);
  NODE_POINTER h0 = createLinkedList(nums0, size);

  size = sizeof(nums1) / sizeof(nums1[0]);
  NODE_POINTER h1 = createLinkedList(nums1, size);

  size = sizeof(nums2) / sizeof(nums2[0]);
  NODE_POINTER h2 = createLinkedList(nums2, size);

  size = sizeof(nums3) / sizeof(nums3[0]);
  NODE_POINTER h3 = createLinkedList(nums3, size);

  size = sizeof(nums4) / sizeof(nums4[0]);
  NODE_POINTER h4 = createLinkedList(nums4, size);

  size = sizeof(nums5) / sizeof(nums5[0]);
  NODE_POINTER h5 = createLinkedList(nums5, size);

  EXPECT_TRUE(compareLinkedList(&h0, &h1));
  EXPECT_FALSE(compareLinkedList(&h0, &h2));
  EXPECT_FALSE(compareLinkedList(&h0, &h3));
  EXPECT_FALSE(compareLinkedList(&h3, &h4));
  EXPECT_TRUE(compareLinkedList(&h4, &h5));
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
