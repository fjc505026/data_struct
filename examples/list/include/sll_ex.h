#ifndef __SLL_EX_H
#define __SLL_EX_H
#include "sll.h"

/* the ADT(abstract data type) implementation of the singly linked list(sll)
 * with HEAD NODE verision: head node index->0, data index from 1
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

// @brief create a new empty linked list with head node
bool init_sll_ex(Linklist *list);

// all functions below have the prerequistie of the exsiting list

/*******************Attribute APIs*****************************/

/* @brief check if the sll is empty
 * @return true->empty, false->not empty
 */
bool sll_ex_is_empty(Linklist list);

// @brief return the number of data in the list
int sll_ex_length(Linklist list);

/*******************Find or locate APIs*****************************/
/*@brief get a index-th node
 *Prerequisties: index-(1,Listlength)
 * @return the index node in the sll
 */
LNode *get_sll_ex_elem(Linklist list, int index);

/* @brief find a node from its value
 * @param list the list to be manipulated with
 * @param data the data need to be located
 * @return the index of the data or -1 if not found
 */
LNode *locate_sll_ex_elem(Linklist list, ElemType *data);

/*******************Insert APIs*****************************/

/* @brief insert an new node by index
 * @param list the list to be manipulated with
 * @param index the index/position of the list needs to be inserted
 * @param data  the data need to be inserted
 */
bool sll_ex_insert(Linklist list, int index, ElemType *data);

/* @brief insert a node after the input node, a helper func of sll_ex_insert()
 * @param node the input node
 * @param data the pointer to the insert data
 */
bool sll_ex_insert_next_node(LNode *node, ElemType *data);

/* @brief insert a node before the input node.
 * improved version(->O(1)) of sll_ex_insert_prior_node(Linklist list,LNode
 * node, ElemType *data);->O(n)
 * implemented by insert to the next node,then swap the current node value and
 * the next node value.
 * @param node the input node
 * @param data the pointer to the insert data
 */
bool sll_ex_insert_prior_node(LNode *node, ElemType *data);

/*******************Delete APIs*****************************/

// release the memeory of the linkedlist
void destroy_sll_ex(Linklist list);

//
void clear_sll_ex(Linklist list);

/* @brief delete a index-th node and return
 * @param list the list to be manipulated with
 * @param index the index/position of data in list needs to be deleted
 * @param data the returned deleted data
 * @return true->success, false->fail
 */
bool sll_ex_delete(Linklist *listp, int index, ElemType *data);

/* @brief delete a desired node from its linked list
 * to avoid find it prior node, we actually delete the del_node->next node, and
 * copy  del_node->next->value tp del_node->value.
 * @risk This way can't delete the
 * tail node
 * @param node node needs to be deleted
 * @return true->success, false->fail
 */
bool sll_ex_delete_node(LNode *del_node);

/*******************Other operation APIs*****************************/
void sll_ex_show(Linklist list);

//@brief reverse a list
void sll_ex_reverse(Linklist *listp);

#endif // __SLL_H