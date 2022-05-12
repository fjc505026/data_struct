#ifndef __LINKQUEUE_H
#define __LINKQUEUE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
  int data;
  LinkNode *next;
} LinkNode;

typedef struct {
  LinkNode *front, *rear;
  int length;
} LinkQueue;

// with head node version
bool init_linkqueue(LinkQueue *q);

int linkqueue_len(LinkQueue *q);

bool linkqueue_is_empty(LinkQueue *q);

bool en_linkqueue(LinkQueue *q, int data);

bool de_linkqueue(LinkQueue *q, int *data);

bool linkqueue_get_head(LinkQueue *q, int *data);

// without head node version
bool init_linkqueue1(LinkQueue *q);

int linkqueue1_len(LinkQueue *q);

bool linkqueue1_is_empty(LinkQueue *q);

bool en_linkqueue1(LinkQueue *q, int data);

bool de_linkqueue1(LinkQueue *q, int *data);

bool linkqueue1_get_head(LinkQueue *q, int *data);

#endif //__LINKQUEUE_H
