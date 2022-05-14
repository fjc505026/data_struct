#include "listack.h"

#define DEBUG_PRINT(...) // printf(...)
// with head node version
bool init_listack(listack *s) {
  listack_node *new_node = (listack_node *)malloc(sizeof(listack_node));
  if (new_node == NULL)
    return false;
  new_node->next = NULL;

  *s = new_node;

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
  DEBUG_PRINT("%c has been pushed\r\n", data);
  return true;
}

// similar with sll_ex_delete_node to first node
bool listack_pop(listack *s, int *data) {
  if (listack_is_empty(*s))
    return false;

  listack_node *del_node = (*s)->next;
  *data = del_node->data;
  (*s)->next = del_node->next;
  DEBUG_PRINT("%c has been poped\r\n", (char)*data);
  free(del_node);
  return true;
}

bool listack_get_top(listack *s, int *data) {
  if (listack_is_empty(*s))
    return false;

  *data = (*s)->next->data;

  return true;
}

void listack_reverse(listack *s) {
  if (!*s || (*s)->next == NULL) {
    return;
  }

  listack s_reversed;
  int data;
  if (!init_listack(&s_reversed)) {
    printf("malloc failed\r\n");
  }

  while (!listack_is_empty(*s)) {
    listack_pop(s, &data);
    listack_push(&s_reversed, data);
  }
  *s = s_reversed;
}

void show_stack_content(listack s) {
  if (!s || !(s->next)) {
    return;
  }
  int index = 1;
  while ((s = s->next)) {
    if (index == 1) {
      printf("[TOP]%d ", s->data);
    } else {
      printf("[%d]%d ", index, s->data);
    }
    index++;
  }
  printf("\r\n");
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