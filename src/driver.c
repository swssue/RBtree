#include "rbtree.h"
#include <stdio.h>


void inorder(rbtree* t,node_t* root)
{   
    if(root!=t->nil){
        inorder(t,root->left);
        printf("%d ", root->key);
        inorder(t,root->right);
    }
    
}

static void insert_arr(rbtree *t, const key_t *arr, const size_t n) {
//   rbtree *t = new_rbtree();
  for (size_t i = 0; i < n; i++) {
    rbtree_insert(t, arr[i]);
  }
}

int main(int argc, char *argv[]) {
   
    rbtree *t = new_rbtree();
    // rbtree_insert(t, 10);
    // rbtree_insert(t, 50);
    // rbtree_insert(t, 30);
    // rbtree_insert(t, 7);
    // rbtree_insert(t, 3);
    // inorder(p);
    // rbtree_find(t,3);
    
    // rbtree_max(t);
    // delete_rbtree(t);
    key_t arr1[] = {10, 5, -8, 34, 67, 0, -23, 156, 24, 2, -12, 26, 35};
    const size_t n1 = sizeof(arr1) / sizeof(arr1[0]);
    insert_arr(t,arr1,n1);
    node_t* p = t->root->right->right->right;
    rbtree_to_array(t,arr1,n1);
    // rbtree_erase(t,p);
    rbtree_min(t);
    // rbtree_erase(t,p);
    rbtree_max(t);
    // printf("%d",t->root->key);
    // for (int i=0; i<n1; i++){
    //     printf("%d =>", arr1[i]);
    // }
    // printf("\n");
    
    // for (int i=0; i<n1; i++){
    //     printf("%d =>", arr1[i]);
    // }
    
    
    // inorder(t,t->root);
    printf("Passed all tests!\n");
}