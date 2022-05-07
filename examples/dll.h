#ifndef __DLL_H
#define __DLL_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* the implementation of double linked list
 *
 */

typedef struct DNode {
  int data;
  struct DNode *prior, *next;
} DNode, *DLinklist;

bool init_dll(DLinklist *L);

bool dll_is_empty(DLinklist L);

bool dll_insert_next_node(DNode *node, DNode *new_node);
bool dll_insert_prior_node(DNode *node, DNode *new_node);
//@brief insert a new node to current index-th node
bool dll_insert_next_node_by_index(DNode *node, DNode *new_node, int index);

bool dll_delete_next_node(DNode *node);

void dll_destroy_list(DLinklist L);

#endif //__STATIC_LL_H
