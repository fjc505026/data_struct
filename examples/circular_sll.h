#ifndef __CIRCULAR_SLL_H
#define __CIRCULAR_SLL_H
#include "sll.h"

/* the ADT(abstract data type) implementation of the circular singly linked
 * list(csll) with HEAD NODE verision: head node index->0, data index from 1
 * NOTE: *LNode is equal to Linklist through, but the former represent a node
 * and the latter represent a whole list
 */

/*  //shared the definition from sll.h
typedef int ElemType;

typedef struct LNode {
  ElemType data;
  struct LNode *next;
} LNode, *Linklist;
*/

bool init_csll(Linklist *L);

bool csll_is_empty(Linklist L);
bool csll_is_tail_node(Linklist L, LNode *p);

#endif //__STATIC_LL_H
