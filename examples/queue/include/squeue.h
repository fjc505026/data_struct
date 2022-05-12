#ifndef __SQUEUE_H
#define __SQUEUE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SQUEUE_MAX_SZ 10

typedef struct {
  int data[SQUEUE_MAX_SZ];
  int front, rear;
  int size;
} squeue;

void init_squeue(squeue *q);

int squeue_len(squeue *q);

bool en_squeue(squeue *q, int data);

bool de_squeue(squeue *q, int *data);

bool squeue_get_head(squeue *q, int *data);

#endif //__SQUEUE_H
