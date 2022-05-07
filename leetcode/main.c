
#include "sll.h"

MyLinkedList *generate_sll(void) {

  MyLinkedList *sll = myLinkedListCreate();
  // add head
  myLinkedListAddAtHead(sll, 2);
  // delete index
  myLinkedListDeleteAtIndex(sll, 1);
  // add head
  myLinkedListAddAtHead(sll, 2);
  // add head
  myLinkedListAddAtHead(sll, 7);
  // add head
  myLinkedListAddAtHead(sll, 3);
  // add head
  myLinkedListAddAtHead(sll, 2);
  // add head
  myLinkedListAddAtHead(sll, 5);
  myLinkedListShow(sll);
  // add tail
  myLinkedListAddAtTail(sll, 5);
  myLinkedListShow(sll);
  // get
  int get_index = 5;
  printf("GET at index:%d ,val:%d\r\n", get_index,
         myLinkedListGet(sll, get_index));
  // delete index
  myLinkedListDeleteAtIndex(sll, 6);

  // get
  get_index = 4;
  printf("GET at index:%d ,val:%d\r\n", get_index,
         myLinkedListGet(sll, get_index));

  printf("original linkedlist:");
  myLinkedListShow(sll);

  return sll;
}

int main() {

  MyLinkedList *sll = generate_sll();

  // MyLinkedList * reversed_sll=reverse_sll(sll->next);
  // printf_sll(reversed_sll);
  return 0;
}

struct ListNode *temp;

// bool check(struct ListNode *node) {
//   if (node == NULL)
//     return true; //递归出口
//   bool res = check(node->next) && node->val == temp->val;
//   temp = temp->next;
//   return res;
// }

// bool isPalindrome(struct ListNode *head) {
//   temp = head;
//   return check(head);
// }