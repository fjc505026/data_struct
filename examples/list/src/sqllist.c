
#include "sqlist.h"

// create a new Sql
void InitList(SqList *list) {
  for (int i = 0; i < SQL_MAXSIZE; i++) {
    list->data[i] = 0;
  }
  list->length = 0;
}

/* Prerequisties: list already exists
 * Result: reset list to empty
 */
void reset_sqlist(SqList *list) { InitList(list); }

/* Prerequisties: list already exists
 * Result: return the number of data in the list
 */
int get_sqlist_length(SqList *list) { return list->length; }

/* Prerequisties: list already exists, i-(1,Listlength)
 * @param index the index of the data in the listEmpty
 * @param data the returned element data
 * @return 0 success ,-1 out of range
 */
int get_sqlist_elem(SqList *list, int index, int *data) {

  if (index < 0 || index > list->length) {
    return -1;
  }

  *data = list->data[index];

  return 0;
};

/* Prerequisties: list already exists
 * @param list the list to be manipulated with
 * @param data the data need to be located
 * @param the compare function used to compare the element data
 * @return the index of the data(first happens) or -1 if not found
 */
int locate_sqlist_elem(SqList *list, int data) {
  for (int i = 0; i < list->length; i++) {
    if (list->data[i] == data) {
      return i;
    }
  }
  return -1;
}

/* Prerequisties: list already exists
 * show list
 * @param list the list to be manipulated with
 */
void show_sqlist(SqList *list) {
  for (int i = 0; i < list->length; i++) {
    printf("[%d]%d ", i, list->data[i]);
  }
  printf("\r\n");
}