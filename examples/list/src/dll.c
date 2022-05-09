#include "dll.h"

bool init_dll(DLinklist *L) {

  *L = (DNode *)malloc(sizeof(DNode));
  if (*L == NULL)
    return false;

  (*L)->prior = NULL;
  (*L)->next = NULL;

  return true;
}

bool dll_is_empty(DLinklist L) { return (L->next != NULL); }

bool dll_insert_next_node(DNode *node, DNode *new_node) {

  if (node == NULL || new_node == NULL)
    return false;

  new_node->next = node->next;
  // if the node is not the tail node
  if (node->next != NULL)
    node->next->prior = new_node;

  new_node->prior = node;
  node->next = new_node;
  return true;
}

bool dll_insert_prior_node(DNode *node, DNode *new_node) {
  if (node == NULL || node->prior == NULL) {
    return false;
  }

  node = node->prior;

  return dll_insert_next_node(node, new_node);
}

bool dll_insert_next_node_by_index(DNode *node, DNode *new_node, int index) {

  if (node == NULL || new_node == NULL)
    return false;

  for (int i = 0; i < index; i++) { // loop until index-1 node
    if (new_node->next == NULL)     // exceeds the end
      return false;
    node = node->next;
  }

  return dll_insert_next_node(node, new_node);
}

bool dll_delete_next_node(DNode *node) {

  if (node == NULL)
    return false;

  DNode *del_node = node->next;
  if (del_node == NULL) // node is the tail node
    return false;

  node->next = del_node->next; // disconnect del_node from list
  if (del_node->next != NULL)  // del node is not the tail node
    del_node->next->prior = node;

  free(del_node);

  return true;
}

void dll_destroy_list(DLinklist L) {
  while (L->next != NULL)
    dll_delete_next_node(L);
  free(L); // release head node
  L = NULL;
}