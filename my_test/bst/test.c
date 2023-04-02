// test.c에서 만든 함수 실행 
#include "BST.h"
#include <stdio.h>

int main(){
    TreeNode* root = NULL;
    root = insert_node(root,10);
    insert_node(root,5);
    insert_node(root,20);
    
    insert_node(root,40);
    print_node(root);
    // printf("%d",re_find(root,10)==NULL? 0 : 1);
    printf("\n");
    delete_node(root,5);
    print_node(root);
    return 1;
}