#ifndef __SLL_H
#define __SLL_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* the ADT(abstract data type) implementation of the singly linked list
 * WITHOUT HEAD NODE version, data index from 1
 * NOTE: *LNode is equal to Linklist through, but the former represent a node
 * and the latter represent a whole list
 */

typedef int ElemType; // abstract element type

typedef struct LNode {
  ElemType data;
  struct LNode *next;
} LNode, *Linklist;

// create a new empty linked list without head node
bool init_sll(Linklist list);

/* Prerequisties: list already exists
 * Result: free the list space
 */
void destroy_sll(Linklist list);

/* Prerequisties: list already exists
 * Result: reset list to empty
 */
void clear_sll(Linklist list);

/* check if the sll is empty
 *@return true->empty, false->not empty
 */
bool sll_is_empty(Linklist list);

/* Prerequisties: list already exists
 * Result: return the number of data in the list
 */
int ListLength(Linklist list);

/* Prerequisties: list already exists, i-(1,Listlength)
 * @param index the index of the data in the listEmpty
 * @param data the returned element data
 * @return the index node in the sll
 */
LNode *get_sll_elem(Linklist list, int index);

/* Prerequisties: list already exists
 * @param list the list to be manipulated with
 * @param data the data need to be located
 * @param the compare function used to compare the element data
 * @return the index of the data or -1 if not found
 */
int locate_sll_elem(Linklist list, ElemType *data, void (*compare)());

/* Prerequisties: list already exists
 * @param list the list to be manipulated with
 * @param index the index/position of the list needs to be inserted
 * @param data  the data need to be inserted
 */
bool sll_insert(register LNode **listp, int index, ElemType *data);

/* Prerequisties: list already exists
 * @param list the list to be manipulated with
 * @param index the index/position of data in list needs to be deleted
 * @param data  the returned deleted data
 */
void sll_delete(Linklist list, int index, ElemType *data);

/* Prerequisties: list already exists
 * apply visit function on each node in list
 * @param list the list to be manipulated with
 * @param visit the function need to be applied
 */
void sll_traverse(Linklist list, void (*visit)());

/* Prerequisties: list already exists
 * @param list the list to be manipulated with
 * @param cur_data the input data
 * @param pre_data the output data, which should be the previous node of the
 * input data
 */
int PriorElem(Linklist list, ElemType *cur_data, ElemType *pre_data);

/* Prerequisties: list already exists
 * @param list the list to be manipulated with
 * @param cur_data the input data
 * @param next_data the output data, which should be the next node of the
 * input data
 */
void NextElem(Linklist list, ElemType *cur_data, ElemType *next_data);

#endif // __SLL_H