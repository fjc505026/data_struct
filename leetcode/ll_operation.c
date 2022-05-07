#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
struct ListNode {
  int val;
  struct ListNode *next;
};
// assume the lists already in ascending order
struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {

  if (!list1)
    return list2;
  if (!list2)
    return list1;

  // new list point to the small list head
  struct ListNode *small_list = (list1->val > list2->val) ? list2 : list1;
  struct ListNode *big_list = (list1->val > list2->val) ? list1 : list2;
  struct ListNode *combined_list = small_list;
  // loop until small list hit the end or big list has been fully merged
  while (small_list->next != NULL && big_list) {
    if ((small_list->next)->val <= big_list->val) {
      small_list = small_list->next;
    } else {
      struct ListNode *add_node = big_list;
      big_list = big_list->next;
      add_node->next = small_list->next;
      small_list->next = add_node;
      small_list = small_list->next;
    }
  }
  // loop over the small list and concatenate the big list
  if (small_list->next == NULL && big_list != NULL) {
    small_list->next = big_list;
  }

  return combined_list;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {

  if (!l1)
    return l2;

  if (!l2)
    return l1;

  struct ListNode *new_list =
      (struct ListNode *)malloc(sizeof(struct ListNode));
  new_list->next = NULL;
  struct ListNode *new_node = new_list;

  int carry = 0;
  while (1) {
    int val1 = l1 ? l1->val : 0;
    int val2 = l2 ? l2->val : 0;

    new_node->val = (val1 + val2 + carry) % 10;
    carry = (val1 + val2 + carry) / 10;

    if (l1 != NULL) {
      l1 = l1->next;
    }
    if (l2 != NULL) {
      l2 = l2->next;
    }
    if (!l1 && !l2 && !carry) {
      new_node->next = NULL;
      break;
    }
    new_node->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (new_node->next)
      new_node = new_node->next;
  }

  return new_list;
}

struct Node {
  int val;
  struct Node *next;
  struct Node *random;
};

struct Node *copyRandomList(struct Node *head) {

  struct Node *old_list = head;
  struct Node *new_list = (struct Node *)malloc(sizeof(struct Node));
  struct Node *new_node = new_list;

  while (1) {
    new_node->val = head->val;
    new_node->random = NULL;

    head = head->next;
    if (!head) {
      new_node->next = NULL;
      break;
    }
    new_node->next = (struct Node *)malloc(sizeof(struct Node));
    new_node = new_node->next;
  }

  struct Node *old_head = old_list;
  while (1) {
    struct Node *rnd_node = old_head->random;

    while (old_head) {
    }
  }
}

struct ListNode *rotateRight(struct ListNode *head, int k) {
  if (!head) {
    return NULL;
  }

  if (k == 0 || head->next == NULL) { // no shift or only one node
    return head;
  }

  struct ListNode *original_ll = head;
  struct ListNode *slow_p = head;
  struct ListNode *fast_p = head;

  int len = 1;
  for (int i = 0; i < k; i++) {
    fast_p = fast_p->next;
    len++;
    if (fast_p->next == NULL) { // fast pointer hit the end
      fast_p = head;
      for (int i = 0; i < k % len; i++) {
        fast_p = fast_p->next;
      }
      break;
    }
  }

  if (fast_p == slow_p) { // K is integer times of len
    return head;
  }

  while (fast_p->next != NULL) {
    fast_p = fast_p->next;
    slow_p = slow_p->next;
  }

  struct ListNode *new_head = slow_p->next;
  slow_p->next = NULL;
  fast_p->next = original_ll;

  return new_head;
}