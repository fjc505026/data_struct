
#include "sll.h"

/*static functions*/


Node *sll_new(void) {
    Node *new_sll = NULL;

    new_sll = (Node *)malloc(sizeof(Node));

    if (new_sll == NULL) {
        return NULL;
    }
new_sll->value=99;
    new_sll->next = NULL;

    return new_sll;
}

void sll_add_at_head(register Node *linkp, int new_value) {
    /*new a node*/
    Node *new_node  = (Node *)malloc(sizeof(Node));
    new_node->value = new_value;

    /*new node points to the original 0st node*/
    new_node->next = linkp->next;

    /* head node point to the new node*/
    linkp->next = new_node;
}

void sll_add_at_tail(register Node *linkp, int new_value) {
    /*new a tail node*/
    Node *new_node  = (Node *)malloc(sizeof(Node));
    new_node->value = new_value;
    new_node->next  = NULL;

    /*traverse the sll to find its tail*/
    while (linkp->next != NULL) {
        linkp = linkp->next;
    }
    /*the original tail node points to the new tail node*/
    linkp->next = new_node;
}

void sll_add_at_index(register Node *linkp, int index, int val) {
    int  cur_idx = -1;
    bool found   = false;

    /*traverse the sll to find the desired index*/
    while (linkp != NULL) { // *** check current node, not linkp->next
        if (cur_idx == index - 1) { // *** need put before linkp=link->next
            found = true;
            break;
        }
        linkp = linkp->next;
        cur_idx++;
    }
    /*current the linkp is the pre_node*/
    if (found) {
        Node *new_node  = (Node *)malloc(sizeof(Node));
        new_node->value = val;

        new_node->next = linkp->next;
        linkp->next    = new_node;
    } else {
        printf("[error], couldn't find index in sll_add\r\n");
    }
}

int sll_get(register Node *linkp, int index) {
    int cur_idx = -1;

    /*traverse the sll to find the desired index*/
    while (linkp->next != NULL) {
        linkp = linkp->next;
        cur_idx++;
        if (cur_idx == index) {
            return linkp->value;
        }
    }

    return -1;
}

void sll_delete_at_index(register Node *linkp, int index) {
    int  cur_idx = -1;
    bool found   = false;

    /*traverse the sll to find the desired index*/
    while (linkp->next != NULL) {
        if (cur_idx == index - 1) {
            found = true;
            break;
        }
        linkp = linkp->next;
        cur_idx++;
    }
    /*current the linkp is the pre_node*/
    if (found) {
        Node *del_node = linkp->next;
        linkp->next    = del_node->next;
        free(del_node);
    } else {
        printf("[error], couldn't find index in sll_delete\r\n");
    }
}

void sll_free(register Node *linkp) {
    while (linkp != NULL) {
        Node *cur_node = linkp;
        linkp          = linkp->next;
        free(cur_node);
    }
}

void printf_sll(register Node *linkp) {
    int cur_idx = -1;
    printf("\r\n");
    while (linkp->next != NULL) {
        linkp = linkp->next;
        cur_idx++;
        printf("[%d]%d  ", cur_idx, linkp->value);
    }
    printf("\r\n");
}

/*insert a node based on its value, in ascending order */
bool sll_insert(register Node **linkp, int new_value) {
    register Node *current;
    register Node *new;

    *linkp = (*linkp)->next; // skip head node

    /*find the position to insert the node*/
    while ((current = *linkp) != NULL && current->value < new_value) {
        linkp = &current->next;
    }

    /*create new node*/
    new = (Node *)malloc(sizeof(Node));
    if (new == NULL) {
        return false;
    }
    new->value = new_value;

    /*insert*/
    new = current;
    *linkp     = new;

    return true;
}

bool detect_loop(register Node *linkp) {
    Node *slow_p = linkp, *fast_p = linkp;

    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            return 1;
        }
    }

    return 0;
}

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *fast_p=head,*slow_p=head;

    int i=n;
    //fast_p forward n step
    while(i){
        i--;
        fast_p=fast_p->next;
      
    }
     //if fast_p not hit the tail, fast_p and slow_p keep forward
    while(fast_p && fast_p->next){
        fast_p=fast_p->next;
        slow_p=slow_p->next;
    }
 

   if(fast_p==NULL){//fast_p step over the tail,delete head
        return head->next;
    }else {//fast_p just hit the tail,slow_p->next
        slow_p->next=(slow_p->next)->next;
        return head;
    }
}


