
#include "sll.h"

/**
 * @brief create a linked list head node and return
 * @return the head node of the linked list
 */
MyLinkedList *myLinkedListCreate(void) {
  MyLinkedList *new_sll = (MyLinkedList *)malloc(sizeof(MyLinkedList));
  if (new_sll == NULL) {
    printf("malloc failed\r\n");
    return NULL;
  }
  new_sll->next = NULL;

  return new_sll;
}

/**
 * @brief add a new node to the 1st node
 * @param linkp the head node of the linked list
 * @param val the value of the new node
 */
void myLinkedListAddAtHead(MyLinkedList *linkp, int val) {
  /*new a node*/
  MyLinkedList *new_node = (MyLinkedList *)malloc(sizeof(MyLinkedList));
  new_node->value = val;

  /*new node points to the original 1st node*/
  new_node->next = linkp->next;
  /* head node point to the new node*/
  linkp->next = new_node;
}

/**
 * @brief add a new node to the tail node
 * @param linkp the head node of the linked list
 * @param val the value of the new node
 */
void myLinkedListAddAtTail(MyLinkedList *linkp, int val) {
  /*new a tail node*/
  MyLinkedList *new_node = (MyLinkedList *)malloc(sizeof(MyLinkedList));
  new_node->value = val;
  new_node->next = NULL;

  /*traverse the sll until hit the tail*/
  while (linkp->next != NULL) {
    linkp = linkp->next;
  }
  /*the original tail node points to the new tail node*/
  linkp->next = new_node;
}

/**
 * @brief insert a new node to a desired index node,the old node will move to
 * the next. if index <0, it will insert to 1st node. if index exceeds the tail
 * node, append it to the tail
 * @param linkp the head node of the linked list
 * @param index the index of the node about to insert
 * @param val the value of the new node
 */
void myLinkedListAddAtIndex(MyLinkedList *linkp, int index, int val) {

  if (index < 1) {
    printf("warnning, no change, please input any index >=1\r\n");
    return;
  }

  /*traverse the sll to find the previous node of the desired index node, if hit
   * tail, return*/
  MyLinkedList *new_node = (MyLinkedList *)malloc(sizeof(MyLinkedList));
  new_node->value = val;

  for (int i = 0; i < (index - 1); i++) {
    if (linkp->next == NULL) { // found tail and append the new node to tail
      linkp->next = new_node;
      new_node->next = NULL;
      return;
    }
    linkp = linkp->next;
  }

  new_node->next = linkp->next;
  linkp->next = new_node;
}

/**
 * @brief Delete an node based on its index
 * @param linkp the head node of the linked list
 * @param index the index of the node about to be deleted,start from 1
 */
void myLinkedListDeleteAtIndex(MyLinkedList *linkp, int index) {

  if (!linkp || linkp->next == NULL) {
    printf("no valid node could be deleted\r\n");
    return;
  }
  // loop to previous node of the target node
  for (int i = 0; i < (index - 1); i++) {
    if (linkp->next == NULL) {
      printf("error, the index excceeds the list length, can't delete\r\n");
      return;
    } else {
      linkp = linkp->next;
    }
  }
  MyLinkedList *del_node = linkp->next; // get the node needs to be deleted
  linkp->next = del_node->next;         // remove it from the linked list
  free(del_node);
}

/**
 * @brief get the value of the index node
 * @param obj the head node of the linked list
 * @param index the index of the target node
 */
int myLinkedListGet(MyLinkedList *obj, int index) {

  if (index < 0) {
    return -1;
  }
  MyLinkedList *node = obj;
  for (int i = 0; i < index; i++) {
    if (node->next == NULL) { // already in tail node, don't process to NULL
      printf("error, the index excceeds the list length, can't get\r\n");
      return -1;
    } else {
      node = node->next;
    }
  }
  return node->value;
}

/**
 * @brief free the space of the linked list
 * @param obj the head node of the linked list
 */
void myLinkedListFree(MyLinkedList *linkp) {
  while (linkp != NULL) {
    MyLinkedList *cur_node = linkp;
    linkp = linkp->next;
    free(cur_node);
  }
}

void myLinkedListShow(MyLinkedList *linkp) {
  int index = 0;
  // printf("\r\n");
  while (linkp) {
    if (index == 0) {
      printf("HEAD");
    }
    printf("[%d]%d ", index++, linkp->value);
    linkp = linkp->next;
  }
  printf("\r\n");
}