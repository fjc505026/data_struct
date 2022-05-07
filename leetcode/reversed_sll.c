
#include "sll.h"

#if 0

Node*  reverse_sll(register Node *linkp){
    if(linkp==NULL||linkp->next==NULL) {
        return linkp;
    }

    Node* original_sll=linkp;
    Node* reversed_sll=sll_new();

    Node* del_node=original_sll->next;
    
    original_sll->next=(original_sll->next)->next; //del from original_sll
    del_node->next=NULL;//create first node for reversed_sll
    reversed_sll->next=del_node; //trunct to reversed_sll
   

    

    while(original_sll->next){
        del_node=original_sll->next;
        original_sll->next=(original_sll->next)->next;
        //insert to start of reversed_sll
        del_node->next=reversed_sll->next;
        reversed_sll->next=del_node;
        printf("traverse original_sll\r\n");
    }

    return reversed_sll;

}

//used for no head node
Node* reverseList(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;
    Node* reverse = reverseList(head->next);
    (head->next)->next = head;
    head->next = NULL;
    return reverse;
}


Node* removeElements(Node* head, int val){
 
    while(head&&head->value==val){
        head=head->next;
    }

    if(!head){
        return head;
    }

    Node* linked_list=head;
    Node* pre_node=head;

    while(head->next){ 
        head=head->next;
         if(head->value==val){
            pre_node->next=head->next;
        }else{
           pre_node=head; 
        }
      
    }
    return linked_list; 
}



struct ListNode* delete_next_and_return(struct ListNode* node){
    if(!node||node->next==NULL){
        return NULL;
    }

    struct ListNode* tmp_node=node->next;
    if(tmp_node->next){
        node->next=tmp_node->next;
    }else{ //tmp_node is the tail
        node->next=NULL;
    }

    return tmp_node;

}

struct ListNode* oddEvenList(struct ListNode* head){

     if(!head||head->next==NULL){
        return head;
    }
    struct ListNode* odd_node=head;
    struct ListNode* even_node=delete_next_and_return(odd_node);
    struct ListNode* even_list=even_node;
    while(odd_node->next){
         odd_node=odd_node->next;
         even_node->next=delete_next_and_return(odd_node);
         if(!even_node->next){
             break;
         }
         even_node=even_node->next;
    }
    even_node->next=NULL;

    odd_node->next=even_list;

    return head;

}
#endif