#include "share_stack.h"

void init_shstack(shstack *s) {
  s->top0 = -1;
  s->top1 = SHARE_STACK_MAX_SZ;
}

bool shstack_is_full(shstack *s) { return (s->top0 + 1 == s->top1); }

bool shstack_is_empty(shstack *s);

bool shstack_push(shstack *s, int data);

bool shstack_pop(shstack *s, int *data);

bool shstack_get_top(shstack *s, int *data);