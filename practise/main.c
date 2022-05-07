
#include "sll.h"

Node *reverse_sll(register Node *linkp);
Node *reverseList(Node *head);

Node *generate_sll(void) {
  Node *sll = sll_new();

  sll_add_at_head(sll, 1);
  sll_add_at_head(sll, 2);
  sll_add_at_head(sll, 3);
  sll_add_at_tail(sll, 5);
  sll_add_at_tail(sll, 6);
  sll_add_at_index(sll, 1, 7);
  printf("original linkedlist:\r\n");
  printf_sll(sll);

  return sll;
}

int main() {

  Node *sll = generate_sll();

  // Node * reversed_sll=reverseList(sll->next);
  // printf_sll(reversed_sll);
  return 0;
}
