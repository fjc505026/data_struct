#include "squeue.h"

void init_squeue(squeue *q) {
  q->rear = q->front = 0;
  q->size = 0;
}

int squeue_len(squeue *q) {
  // return (q->rear+SQUEUE_MAX_SZ-q->front)%SQUEUE_MAX_SZ
  return q->size;
}

bool en_squeue(squeue *q, int data) {
  if (squeue_len(q) == SQUEUE_MAX_SZ)
    return false;

  q->data[q->rear] = data;
  q->rear = (q->rear + 1) % SQUEUE_MAX_SZ;
  q->size++;

  return true;
}

bool de_squeue(squeue *q, int *data) {
  if (squeue_len(q) == 0)
    return false;

  *data = q->data[q->front];
  q->front = (q->front + 1) % SQUEUE_MAX_SZ;
  q->size--;

  return true;
}

bool squeue_get_head(squeue *q, int *data) {
  if (squeue_len(q) == 0)
    return false;

  *data = q->data[q->front];

  return true;
}