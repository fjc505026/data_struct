
#include "sll_ex.h"
#include <string.h>
bool init_sll_ex(Linklist *list) {
  *list = (LNode *)malloc(sizeof(LNode));
  if (*list == NULL) {
    return false;
  }
  (*list)->next = NULL;
  return true;
}

/*******************Attribute APIs*****************************/

bool sll_ex_is_empty(Linklist list) {
  if (list->next == NULL)
    return true;
  else
    return false;
}

int sll_ex_length(Linklist list) {
  int i = 0;

  LNode *p = list;
  while (p->next != NULL) {
    p = p->next;
    i++;
  }
  return i;
}

/*******************Find or locate APIs*****************************/
LNode *get_sll_ex_elem(Linklist list, int index) {
  if (index < 0) {
    return NULL;
  }
  for (int i = 0; i < index; i++) {
    if (!list) {
      printf("index hit the end\r\n");
      return NULL;
    }
    list = list->next;
  }

  return list;
}

LNode *locate_sll_ex_elem(Linklist list, ElemType *data) {
  LNode *p = list->next;
  // compare data in each node from the 1st node
  while (p != NULL && !memcmp(&(p->data), data, sizeof(p->data))) {
    p = p->next;
  }
  return p;
}

/*******************Insert APIs*****************************/

bool sll_ex_insert(Linklist list, int index, ElemType *data) {
  if (index < 1) {
    printf("please give an index >=1\r\n");
    return false;
  }
  LNode *p = get_sll_ex_elem(list, index - 1); // loop to index-1 node
  if (p == NULL)
    return false;

  return sll_ex_insert_next_node(p, data);
}

bool sll_ex_insert_next_node(LNode *node, ElemType *data) {
  if (node == NULL)
    return false;

  LNode *new_node = (LNode *)malloc(sizeof(LNode));
  if (new_node == NULL)
    return false;
  memcpy(&(new_node->data), data, sizeof(new_node->data));
  new_node->next = node->next;
  node->next = new_node;

  return true;
}

bool sll_ex_insert_prior_node(LNode *node, ElemType *data) {
  if (node == NULL)
    return false;

  LNode *new_node = (LNode *)malloc(sizeof(LNode));
  if (new_node == NULL)
    return false;
  // copy current node data to the new node
  memcpy(&(new_node->data), &(node->data), sizeof(new_node->data));
  new_node->next = node->next;
  node->next = new_node;
  // copy the new data to the current node
  memcpy(&(node->data), data, sizeof(node->data));

  return true;
}

/*******************Delete APIs*****************************/

void destroy_sll_ex(Linklist list) {
  if (!list)
    return;

  LNode *p;
  while ((p = list) != NULL) {
    LNode *q = p;
    p = p->next;
    free(q);
  }
}

void clear_sll_ex(Linklist list);

bool sll_ex_delete(Linklist *listp, int index, ElemType *data) {

  if (index < 1)
    return false;

  LNode *p = get_sll_ex_elem(*listp, index - 1); // loop to index-1 node
  if (p == NULL)
    return false;

  if (p->next == NULL) {
    printf("the index node is NULL\r\n");
    return false;
  }

  LNode *del_node = p->next;
  memcpy(data, &(del_node->data),
         sizeof(*data));    // assgin del_node data to data
  p->next = del_node->next; // delete the del_node from the Linklist
  free(del_node);

  return true;
}

// del_node can't be tail node, otherwise  p is NULL;
bool sll_ex_delete_node(LNode *del_node) {
  if (del_node == NULL)
    return false;

  LNode *p = del_node->next;
  if (p == NULL) {
    printf("can delete the tail node, this function has its shortage\r\n");
  }
  // copy the next node value to current node
  memcpy(&(del_node->data), &(p->data), sizeof(del_node->data));
  del_node->next = p->next; // disconnect the next node from the list
  free(p);                  // we actually delete the next node
  return true;
}

/*******************Other operation APIs*****************************/
void sll_ex_show(Linklist list) {
  LNode *node = list->next;
  int index = 1;
  while (node != NULL) {
    if (index == 1) {
      printf("[%d]%d", index++, node->data);
    } else {
      printf("->[%d]%d", index++, node->data);
    }
    node = node->next;
  }
  printf("\r\n");
}

void sll_ex_reverse(Linklist *listp) {
  if (!*listp || (*listp)->next == NULL) {
    return;
  }

  Linklist sll; // new a list
  if (init_sll_ex(&sll)) {
    printf("malloc failed\r\n");
  }

  ElemType data;

  while (1) { // delete 1st element from old list
    if (!sll_ex_delete(listp, 1, &data)) {
      break; // hit the end
    }
    printf("get data %d\r\n", data);
    // insert to the first node of new list
    if (!sll_ex_insert_next_node(sll, &data)) {
      printf("not enough memeroy\r\n");
      break;
    }
  }
  *listp = sll;
}