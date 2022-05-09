#include "circular_sll.h"

bool init_csll(Linklist *L) {

  *L = (LNode *)malloc(sizeof(LNode));
  if (*L == NULL)
    return false;

  (*L)->next = (*L); // head node points to itself

  return true;
}

bool csll_is_empty(Linklist L) { return (L->next != L); }
bool csll_is_tail_node(Linklist L, LNode *p) { return (p->next != L); }
