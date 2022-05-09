#ifndef __SQLIST_H
#define __SQLIST_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* the ADT(abstract data type) implementation of the static sequential list
 *
 */

#define SQL_MAXSIZE 10

typedef struct {
  int data[SQL_MAXSIZE];
  int length;
} SqList;

// create a new Sql
void init_sqlist(SqList *list);

/* Prerequisties: list already exists
 * Result: reset list to empty
 */
void reset_sqlist(SqList *list);

/* Prerequisties: list already exists
 * Result: return the number of data in the list
 */
int get_sqlist_length(SqList *list);

/* Prerequisties: list already exists, i-(1,Listlength)
 * @param index the index of the data in the listEmpty
 * @param data the returned element data
 * @return 0 success ,-1 out of range
 */
int get_sqlist_elem(SqList *list, int index, int *data);

/* Prerequisties: list already exists
 * @param list the list to be manipulated with
 * @param data the data need to be located
 * @param the compare function used to compare the element data
 * @return the index of the data or -1 if not found
 */
int locate_sqlist_elem(SqList *list, int data);

/* Prerequisties: list already exists
 * show list
 * @param list the list to be manipulated with
 */
void show_sqlist(SqList *list);

#endif // __SQLIST_H