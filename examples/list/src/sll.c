
#include "sll.h"
#include <string.h>
// create a new empty linked list without head node
bool init_sll(Linklist list) {
  list = NULL;
  return true;
}

/* Prerequisties: list already exists
 * Result: free the list space
 */
void destroy_sll(Linklist list);

/* Prerequisties: list already exists
 * Result: reset list to empty
 */
void clear_sll(Linklist list);

bool sll_is_empty(Linklist list) { return (list == NULL); }

/* Prerequisties: list already exists
 * Result: return the number of data in the list
 */
int ListLength(Linklist list);

LNode *get_sll_elem(Linklist list, int index) {
  if (index < 0) {
    return NULL;
  }
  for (int i = 0; i < index; i++) {
    if (!list) {
      return NULL;
    }
    list = list->next;
  }

  return list;
}

int locate_sll_elem(Linklist list, ElemType *data, void (*compare)());

bool sll_insert(register LNode **listp, int index, ElemType *data) {
  if (index < 1) {
    printf("please give an index >=1\r\n");
    return false;
  }

  if (index = 1) { // insert before current 1st node
    LNode *new_node = (LNode *)malloc(sizeof(LNode));
    // new_node->data=data? risk?
    memcpy(&(new_node->data), data, sizeof(new_node->data));
    new_node->next = *listp; // new node points to current list(1st node)
    *listp = new_node;       // change the new 1st node as the list
    return true;
  }
  register LNode *p = *listp;

  for (int i = 1; i < index - 1; i++) { // loop to index-1 node
    if (p == NULL) {
      printf("index hit the end\r\n");
      return false;
    }
    p = p->next;
  }
  /*create new node*/
  LNode *new_node = (LNode *)malloc(sizeof(LNode));
  if (new_node == NULL) {
    return false;
  }
  // new_node->data=data? risk?
  memcpy(&(new_node->data), data, sizeof(new_node->data));

  new_node->next = p->next; // new node points to current index node
  p->next = new_node;       // index-1 node points to new node

  return true;
}
#if 0
bool sll_insert(Linklist list, int index, ElemType *data) {
  if (index < 1) {
    printf("please give an index >=1\r\n");
    return false;
  }

  if (index = 1) { // insert before current 1st node
    LNode *new_node = (LNode *)malloc(sizeof(LNode));
    // new_node->data=data? risk?
    memcpy(new_node->data, data, sizeof(new_node->data));
    new_node->next = list; // new node points to current list(1st node)
    list = new_node;       // change the new 1st node as the list
    return true;
  }

  LNode *p = list;

  for (int i = 1; i < index - 1; i++) { // loop to index-1 node
    if (p == NULL) {
      printf("index hit the end\r\n");
      return false;
    }
    p = p->next;
  }

  LNode *new_node = (LNode *)malloc(sizeof(LNode));
  // new_node->data=data? risk?
  memcpy(new_node->data, data, sizeof(new_node->data));
  new_node->next = p->next; // new node points to current index node
  p->next = new_node;       // index-1 node points to new node
  return true;
}
#endif

void sll_delete(Linklist list, int index, ElemType *data);

void sll_traverse(Linklist list, void (*visit)());
