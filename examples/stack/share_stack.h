#ifndef __SHARE_STACK_H
#define __SHARE_STACK_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SHARE_STACK_MAX_SZ 10

typedef struct {
  int data[SHARE_STACK_MAX_SZ];
  int top0;
  int top1;
} shstack;

void init_shstack(shstack *s);

bool shstack_is_full(shstack *s);

// need consider stack1 and stack 2 separately

bool shstack_is_empty(shstack *s);

bool shstack_push(shstack *s, int data);

bool shstack_pop(shstack *s, int *data);

bool shstack_get_top(shstack *s, int *data);

#endif //__SQSTACK_H
