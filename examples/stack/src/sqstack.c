#include "sqstack.h"

void init_sqstack(sqstack *stk) { stk->top = -1; }

bool sqstack_is_empty(sqstack *stk) { return (stk->top == -1); }

bool sqstack_is_full(sqstack *stk) { return (stk->top == SQSTACK_MAX_SZ - 1); }

bool sqstack_push(sqstack *stk, int data) {
  if (sqstack_is_full(stk)) {
    return false;
  }
  printf("%c has been pushed\r\n", data);

  stk->data[++(stk->top)] = data;

  return true;
}
//*data can't use char.cast will across memeory boundary
bool sqstack_pop(sqstack *stk, int *data) {
  if (sqstack_is_empty(stk)) {
    return false;
  }

  *data = stk->data[(stk->top)--];
  printf("%c has been poped\r\n", (char)*data);
  return true;
}

bool sqstack_get_top(sqstack *stk, int *data) {
  if (sqstack_is_empty(stk)) {
    return false;
  }

  *data = stk->data[stk->top];

  return true;
}