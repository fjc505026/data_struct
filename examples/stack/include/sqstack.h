#ifndef __SQSTACK_H
#define __SQSTACK_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SQSTACK_MAX_SZ 10

typedef struct {
  int data[SQSTACK_MAX_SZ];
  int top;
} sqstack;

void init_sqstack(sqstack *stk);

bool sqstack_is_empty(sqstack *stk);

bool sqstack_is_full(sqstack *stk);

// push a new data into stack
bool sqstack_push(sqstack *stk, int data);

// pop out a data and return by data
bool sqstack_pop(sqstack *stk, int *data);

bool sqstack_get_top(sqstack *stk, int *data);

#endif //__SQSTACK_H
