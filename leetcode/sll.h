#ifndef __SLL_H
#define __SLL_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* the singly linkedlist here, we create a head node for store the head and
 * never store a value in the head node
 * FRIST_INDEX 1
 *  HEAD NODE(0st) -> 1st node -> 2st node
 * ...
 * FRIST_INDEX 0  //leet code sll
 *  HEAD NODE -> 0st node -> 1st node
 */

typedef struct NODE {
  int value;
  struct NODE *next;
} MyLinkedList;

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/

MyLinkedList *myLinkedListCreate(void);
int myLinkedListGet(MyLinkedList *obj, int index);
void myLinkedListAddAtHead(MyLinkedList *linkp, int val);
void myLinkedListAddAtTail(MyLinkedList *linkp, int val);
void myLinkedListAddAtIndex(MyLinkedList *linkp, int index, int val);
void myLinkedListDeleteAtIndex(MyLinkedList *linkp, int index);
void myLinkedListFree(MyLinkedList *linkp);
void myLinkedListShow(MyLinkedList *linkp);

#endif // __SLL_H