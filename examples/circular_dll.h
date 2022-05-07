#ifndef __CIRCULAR_DLL_H
#define __CIRCULAR_DLL_H
#include "dll.h"

/* the ADT(abstract data type) implementation of the circular double linked
 * list(cdll) with HEAD NODE verision: head node index->0, data index from 1
 * NOTE: *LNode is equal to Linklist through, but the former represent a node
 * and the latter represent a whole list
 */

/*  //shared the definition from sll.h
typedef struct DNode {
  int data;
  struct DNode *prior, *next;
} DNode, *DLinklist;
*/

bool init_cdll(DLinklist *L);

bool cdll_is_empty(DLinklist L);
bool cdll_is_tail_node(DLinklist L, DNode *p);

void cdll_insert_next_node(DNode *node, DNode *new_node);

void cdll_delete_next_node(DNode *node);

#endif //__STATIC_LL_H
