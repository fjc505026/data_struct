#ifndef __SEQLIST_H
#define __SEQLIST_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* the ADT(abstract data type) implementation of the dynamic sequential list
 *
 */

#define SEQ_MAX_SZ 10

typedef struct {
  int *data;
  int maxsz;
  int length;
} SeqList;

// create a new dynamic sequential list
void init_seqlist(SeqList *list);

/* Prerequisties: list already exists
 * Result: reset list to empty
 */
void reset_seqlist(SeqList *list);

/* Prerequisties: list already exists
 * Result: return the number of data in the list
 */
int get_seqlist_length(SeqList *list);

/* Prerequisties: list already exists, i-(1,Listlength)
 * @param index the index of the data in the listEmpty
 * @param data the returned element data
 * @return 0 success ,-1 out of range
 */
int get_seqlist_elem(SeqList *list, int index, int *data);

/* Prerequisties: list already exists
 * @param list the list to be manipulated with
 * @param data the data need to be located
 * @param the compare function used to compare the element data
 * @return the index of the data or -1 if not found
 */
int locate_seqlist_elem(SeqList *list, int data);

/* Prerequisties: list already exists
 * increase the maxsize of the list, apply for more memeory space
 * @param list the list to be manipulated with
 * @param len the length to add on the maxsize
 */
void increase_seqlist_size(SeqList *list, int len);

/* Prerequisties: list already exists
 * release the space
 * @param list the list to be manipulated with
 */
void del_seqlist(SeqList *list);

/* Prerequisties: list already exists
 * show list
 * @param list the list to be manipulated with
 */
void show_seqlist(SeqList *list);

#endif // __SEQLIST_H