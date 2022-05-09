
#include "seqlist.h"

// create a new Sql
void init_seqlist(SeqList *list) {
  list->data = (int *)malloc(SEQ_MAX_SZ * sizeof(int));
  list->length = 0;
  list->maxsz = SEQ_MAX_SZ;
}

/* Prerequisties: list already exists
 * Result: reset list to empty
 */
void reset_seqlist(SeqList *list) {

  for (int i = 0; i < list->maxsz; i++) {
    list->data[i] = 0;
  }
  list->length = 0;
  // list->maxsz  could be changed
}

/* Prerequisties: list already exists
 * Result: return the number of data in the list
 */
int get_seqlist_length(SeqList *list) { return list->length; }

/* Prerequisties: list already exists, i-(1,Listlength)
 * @param index the index of the data in the listEmpty
 * @param data the returned element data
 * @return 0 success ,-1 out of range
 */
int get_seqlist_elem(SeqList *list, int index, int *data) {

  if (index < 0 || index > list->length) {
    return -1;
  }

  *data = list->data[index];
};

/* Prerequisties: list already exists
 * @param list the list to be manipulated with
 * @param data the data need to be located
 * @param the compare function used to compare the element data
 * @return the index of the data(first happens) or -1 if not found
 */
int locate_seqlist_elem(SeqList *list, int data) {
  for (int i = 0; i < list->length; i++) {
    if (list->data[i] == data) {
      return i;
    }
  }
  return -1;
}

/* Prerequisties: list already exists
 * increase the maxsize of the list, apply for more memeory space
 * @param list the list to be manipulated with
 * @param len the length to add on the maxsize
 */
void increase_seqlist_size(SeqList *list, int len) {
  int *p = list->data; // keep the old data address

  /*malloc new space for data*/
  list->data = (int *)malloc((SEQ_MAX_SZ + len) * sizeof(int));
  for (int i = 0; i < list->length; i++) {
    list->data[i] = p[i];
  }
  list->maxsz = list->maxsz + len;
  free(p); // release space of the old data
}

/* Prerequisties: list already exists
 * release the space
 * @param list the list to be manipulated with
 */
void del_seqlist(SeqList *list) {
  free(list);
  list = NULL;
}

/* Prerequisties: list already exists
 * show list
 * @param list the list to be manipulated with
 */
void show_seqlist(SeqList *list) {
  for (int i = 0; i < list->length; i++) {
    printf("[%d]%d ", i, list->data[i]);
  }
  printf("\r\n");
}