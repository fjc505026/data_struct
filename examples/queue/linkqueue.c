#include "linkqueue.h"

// with head node version
bool init_linkqueue(LinkQueue *q) {
  q->front = q->rear = (LinkNode *)malloc(sizeof(LinkNode));
  if (q->front == NULL)
    return false;
  q->front->next = NULL;
  q->length = 0;

  return true;
}

int linkqueue_len(LinkQueue *q) { return q->length; }

bool linkqueue_is_empty(LinkQueue *q) { return q->front == q->rear; }

// =insert a tail node into a linkedlist
bool en_linkqueue(LinkQueue *q, int data) {
  LinkNode *new_node = (LinkNode *)malloc(sizeof(LinkNode));

  if (new_node == NULL)
    return false;

  new_node->data = data; // new a tail node
  new_node->next = NULL;
  q->rear->next = new_node; // queue rear node point to the new tail node
  q->rear = new_node;       // insert to queue rear node
  q->length++;
  return true;
}
// =delete current first node
bool de_linkqueue(LinkQueue *q, int *data) {
  if (linkqueue1_is_empty(q))
    return false;
  LinkNode *del_node = q->front->next;
  *data = del_node->data;

  q->front->next = del_node->next; // change front->next
  if (q->rear == del_node) {       // last node
    q->rear = q->front;
  }
  free(del_node);
  q->length--;
  return true;
}

bool linkqueue_get_head(LinkQueue *q, int *data) {
  if (linkqueue1_is_empty(q))
    return false;

  *data = q->front->next->data;
  return true;
}

/************************ without head node version************************/

bool init_linkqueue1(LinkQueue *q) {
  q->front = q->rear = NULL;
  q->length = 0;
  return true;
}

int linkqueue1_len(LinkQueue *q) { return q->length; }

bool linkqueue1_is_empty(LinkQueue *q) { return q->front == NULL; }

// =insert a tail node into a linkedlist
bool en_linkqueue1(LinkQueue *q, int data) {
  LinkNode *new_node = (LinkNode *)malloc(sizeof(LinkNode));
  if (new_node == NULL)
    return false;
  new_node->data = data; // new a tail node
  new_node->next = NULL;

  if (q->front == NULL) { // empty queue
    q->front = new_node;
    q->rear = new_node;
  } else {
    q->rear->next = new_node; // queue rear node point to the new tail node
    q->rear = new_node;       // insert to queue rear node
  }
  q->length++;
  return true;
}
// =delete current head node
bool de_linkqueue1(LinkQueue *q, int *data) {
  if (linkqueue1_is_empty(q))
    return false;
  LinkNode *del_node = q->front;
  *data = del_node->data;

  q->front = del_node->next; // change front->next
  if (q->rear == del_node) { // last node
    q->rear = NULL;
    q->front = NULL;
  }
  free(del_node);
  q->length--;
  return true;
}

bool linkqueue1_get_head(LinkQueue *q, int *data) {
  if (linkqueue1_is_empty(q))
    return false;

  *data = q->front->data;
  return true;
}