#ifndef __LISTACK_H
#define __LISTACK_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Linknode {
  int data;
  struct Linknode *next;
} listack_node, *listack;

// with head node version
bool init_listack(listack *s);

bool listack_is_empty(listack s);

bool listack_push(listack *s, int data);

bool listack_pop(listack *s, int *data);

bool listack_get_top(listack *s, int *data);

void show_stack_content(listack s);

// without head node version
void init_listack1(listack *s);

bool listack1_is_empty(listack *s);

bool listack1_push(listack *s, int data);

bool listack1_pop(listack *s, int *data);

bool listack1_get_top(listack *s, int *data);

#endif //__LISTACK_H
