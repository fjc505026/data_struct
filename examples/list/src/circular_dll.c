#include "circular_dll.h"

bool init_cdll(DLinklist *L) {

  *L = (DNode *)malloc(sizeof(DNode));
  if (*L == NULL)
    return false;

  (*L)->prior = (*L); // head node prior points to itself
  (*L)->next = (*L);  // head node next points to itself

  return true;
}

bool cdll_is_empty(DLinklist L) { return (L->next != L); }
bool cdll_is_tail_node(DLinklist L, DNode *p) { return (p->next != L); }

void cdll_insert_next_node(DNode *node, DNode *new_node) {
  new_node->next = node->next; // connect new node with node->next
  node->next->prior = new_node;
  new_node->prior = node; // connect new node with node
  node->next = new_node;
}

void cdll_delete_next_node(DNode *node) {
  DNode *del_node = node->next; // get del_node
  node->next = del_node->next;  // disconnect del_node from list
  del_node->next->prior = node;
  free(del_node);
}
