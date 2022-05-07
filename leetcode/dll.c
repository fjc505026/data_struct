#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
  int value;
  struct NODE *pre;
  struct NODE *next;
} MyLinkedList;

/**index start from 0
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/

MyLinkedList *myLinkedListCreate();

int myLinkedListGet(MyLinkedList *obj, int index);

void myLinkedListAddAtHead(MyLinkedList *obj, int val);

void myLinkedListAddAtTail(MyLinkedList *obj, int val);

void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val);

void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index);

void myLinkedListFree(MyLinkedList *obj);

MyLinkedList *myLinkedListCreate(void) {

  MyLinkedList *head = (MyLinkedList *)malloc(sizeof(MyLinkedList));
  if (head == NULL) {
    return NULL;
  }
  head->pre = NULL;
  head->next = NULL;

  return head;
}

int myLinkedListGet(MyLinkedList *obj, int index) {

  if (!obj || !obj->next)
    return -1;

  obj = obj->next; // skip first node

  for (int i = 0; i < index; i++) { // loop till index node
    if (obj->next == NULL) {
      return -1;
    }
    obj = obj->next;
  }

  return obj->value;
}

void myLinkedListAddAtHead(MyLinkedList *obj, int val) {

  MyLinkedList *new_node = (MyLinkedList *)malloc(sizeof(MyLinkedList));

  if (!new_node) {
    return;
  }
  new_node->value = val;

  if (obj->next == NULL) {
    new_node->next = NULL;
    new_node->pre = obj;
    obj->next = new_node;
  } else {
    new_node->next = obj->next;
    new_node->pre = obj;
    (obj->next)->pre = new_node;
    obj->next = new_node;
  }
}

void myLinkedListAddAtTail(MyLinkedList *obj, int val) {

  MyLinkedList *new_node = (MyLinkedList *)malloc(sizeof(MyLinkedList));

  if (!new_node) {
    return;
  }
  new_node->value = val;
  new_node->next = NULL;

  while (obj->next) {
    obj = obj->next;
  }
  new_node->pre = obj;
  obj->next = new_node;
}

void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val) {
  MyLinkedList *new_node = (MyLinkedList *)malloc(sizeof(MyLinkedList));
  if (!new_node) {
    return;
  }
  new_node->value = val;

  if (index == 0) {
    myLinkedListAddAtHead(obj, val);
  } else {

    for (int i = -1; i < (index - 1); i++) {
      if (obj->next == NULL)
        return;
      obj = obj->next;
    }

    if (obj->next == NULL) {
      new_node->next = NULL;
      new_node->pre = obj;
      obj->next = new_node;
    } else {
      new_node->next = obj->next;
      new_node->pre = obj;
      (obj->next)->pre = new_node;
      obj->next = new_node;
    }
  }
}

void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index) {

  if (!obj || !obj->next)
    return;

  for (int i = -1; i < (index - 1); i++) {
    if (obj->next == NULL) // if obj is tail node
      return;
    obj = obj->next;
  }

  MyLinkedList *del_node = obj->next;
  if (del_node == NULL) {
    return;
  } else {
    if (del_node->next == NULL) {
      obj->next = NULL;
    } else {
      obj->next = del_node->next;
      (del_node->next)->pre = obj;
    }
    free(del_node);
  }
}

void myLinkedListFree(MyLinkedList *obj) {

  while (obj->next) {
    MyLinkedList *del_node = obj;
    obj = obj->next;
    free(del_node);
  }
}