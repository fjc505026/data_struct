#ifndef __STATIC_LL_H
#define __STATIC_LL_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* the implementation of static linked list
 *  0st node is the head node
 *  tail node: next value -1;
 *  un_init node: next value -2;
 *
 *
 * Pros: list operation like add, delete no need to move lot of nodes
 * Cons: can't randomly access, it has fixed space
 */

#define STATIC_LL_MAX_SZ 10

typedef struct Node {
  int data;
  int next; // the next node position
} SLinkList[STATIC_LL_MAX_SZ];

#endif //__STATIC_LL_H
