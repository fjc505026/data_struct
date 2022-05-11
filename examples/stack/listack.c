#include "listack.h"

// with head node version
bool init_listack(listack *s) {
  *s = (listack_node *)malloc(sizeof(listack_node));
  if (*s == NULL)
    return false;
  (*s)->next == NULL;

  return true;
}

bool listack_is_empty(listack s) { return s->next == NULL; }

// similar with sll_ex_insert_next_node to head node
bool listack_push(listack *s, int data) {
  listack_node *new_node = (listack_node *)malloc(sizeof(listack_node));
  if (new_node == NULL)
    return false;
  new_node->data = data;

  new_node->next = (*s)->next;
  (*s)->next = new_node;

  return true;
}

// similar with sll_ex_delete_node to first node
bool listack_pop(listack *s, int *data) {
  if (listack_is_empty(*s))
    return false;

  listack_node *del_node = (*s)->next;
  *data = del_node->data;
  (*s)->next = del_node->next;

  free(del_node);
  return true;
}

bool listack_get_top(listack *s, int *data) {
  if (listack_is_empty(*s))
    return false;

  *data = (*s)->next->data;

  return true;
}

// without head node version
void init_listack1(listack *s) { *s = NULL; }

bool listack1_is_empty(listack *s) { return *s == NULL; }

bool listack1_push(listack *s, int data) {
  listack_node *new_node = (listack_node *)malloc(sizeof(listack_node));
  if (new_node == NULL)
    return false;
  new_node->data = data;

  new_node->next = (*s);
  *s = new_node;

  return true;
}

bool listack1_pop(listack *s, int *data) {
  if (listack_is_empty(*s))
    return false;

  listack_node *del_node = (*s);
  *data = del_node->data;
  *s = (*s)->next;

  free(del_node);
  return true;
}

bool listack1_get_top(listack *s, int *data) {
  if (listack_is_empty(*s))
    return false;

  *data = (*s)->data;

  return true;
}