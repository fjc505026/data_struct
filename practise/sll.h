#ifndef __SLL_H
#define __SLL_H
#include <stdlib.h>
#include <stdio.h>
#include<stdbool.h> 

/* the singly linkedlist here, we create a head node for store the head and never store a value in the head node
 * HEAD NODE -> 0st node -> 1st node ...
 */

typedef struct NODE {
    int          value;
    struct NODE *next;
} Node;

void printf_sll(register Node *linkp);

Node *sll_new(void);
int   sll_get(register Node *linkp, int index);
void  sll_add_at_head(register Node *linkp, int new_value);
void  sll_add_at_tail(register Node *linkp, int new_value);
void  sll_add_at_index(register Node *linkp, int index, int val);
bool  sll_insert(register Node **linkp, int new_value);
void  sll_delete_at_index(register Node *linkp, int index);
void  sll_free(register Node *linkp);

/*detect_loop() - detect if has a cycle in the linked list
 *use a slow pointer and fast pointer looping the linked list to see if they
 *can meet
 *@return true if found a loop, false if could not.
 */
bool detect_loop(register Node *linkp);

#endif // __SLL_H