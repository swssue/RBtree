#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "LinkedList.h"

// insert_first
LinkedNode* insert_first(LinkedNode* head, element value){
    LinkedNode* p = (LinkedNode*)malloc(sizeof(LinkedNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

LinkedNode* insert_pre(LinkedNode* head, LinkedNode* pre, element value){
    LinkedNode* p = (LinkedNode*)malloc(sizeof(LinkedNode));
    p->data = value;
    p->link = pre;
    head->link = p;
    return head;
}

// delete_pre
LinkedNode* delete_pre(LinkedNode* head, LinkedNode* pre){
    LinkedNode* removed = pre;
    head->link = pre->link;
    free(removed);
    return head;
}

// delete_first
LinkedNode* delete_first(LinkedNode* head){
    LinkedNode* removed = head;
    head = head->link;
    free(removed);
    return head;
}

// print_node
void print_node(LinkedNode* head){
    LinkedNode* p = head;
    while(p!=NULL){
        printf("%d->",p->data);
        p = p->link;
    }
    printf("NULL\n");
}

LinkedNode* find_value(LinkedNode* head,element x){
    LinkedNode* p = head;
    while(p!=NULL){
        if (p->data==x) return p;
        p = p->link;
    }
    return NULL;
}

// 최댓값 구하기
int max_value(LinkedNode* head){
    LinkedNode* p = head;
    int max_v = 0;
    while(p!=NULL){
        if (p->data > max_v ){
            max_v = p->data;
        }
        p = p->link;
    }
    return max_v;
}

//main
// int main(){
//     LinkedNode *head = NULL;
    
//     for (int i=0;i<5;i++){
//         head = insert_first(head,i);
//         print_node(head);
//     }

//     LinkedNode* temp = find_value(head,1);
//     if (temp == NULL) printf("찾는 값이 없습니다.\n");
//     else printf("값을 찾았습니다.\n");
    
//     LinkedNode* pre = head->link;
//     head = insert_pre(head,pre,10);
//     print_node(head);

//     pre = head->link;
//     head = delete_pre(head,pre);
//     print_node(head);

//     int max_v = 0;
//     max_v = max_value(head);
//     printf("%d\n",max_v);

//     for(int i=0;i<5;i++){
//         head = delete_first(head);
//         print_node(head);
//     }

    

//     return 1;

// }