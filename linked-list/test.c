#include "LinkedList.h"
#include <stdio.h>
int main(){
    LinkedNode *head = NULL;
    
    for (int i=0;i<5;i++){
        head = insert_first(head,i);
        print_node(head);
    }

    LinkedNode* temp = find_value(head,1);
    if (temp == NULL) printf("찾는 값이 없습니다.\n");
    else printf("값을 찾았습니다.\n");
    
    LinkedNode* pre = head->link;
    head = insert_pre(head,pre,10);
    print_node(head);

    pre = head->link;
    head = delete_pre(head,pre);
    print_node(head);

    int max_v = 0;
    max_v = max_value(head);
    printf("%d\n",max_v);

    for(int i=0;i<5;i++){
        head = delete_first(head);
        print_node(head);
    }

    return 1;

}