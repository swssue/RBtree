#include "rbtree.h"

#include <stdlib.h>

// rbtree 초기화
rbtree *new_rbtree(void) {
  // rbtree 1개 만큼 힙 메모리 할당
  rbtree *p = (rbtree *)calloc(1, sizeof(rbtree));
  // TODO: initialize struct if needed
  // nil에 node_t 1개 사이즈 만큼의 힙 메모리 할당
  p->nil = (node_t *)calloc(1,sizeof(node_t));
  //nill의 색깔은 검정색
  p->nil->color = RBTREE_BLACK;
  // 현재 root가 없으므로 nil을 root값으로 사용
  p->root = p->nil;

  return p;
}

// void delete_rbtree(rbtree *t) {
//   // TODO: reclaim the tree nodes's memory
//   free(t);
// }

node_t *rbtree_insert(rbtree *t, const key_t key) {
  // TODO: implement insert
  
  return t->root;
}

// node_t *rbtree_find(const rbtree *t, const key_t key) {
//   // TODO: implement find
//   return t->root;
// }

// node_t *rbtree_min(const rbtree *t) {
//   // TODO: implement find
//   return t->root;
// }

// node_t *rbtree_max(const rbtree *t) {
//   // TODO: implement find
//   return t->root;
// }

// int rbtree_erase(rbtree *t, node_t *p) {
//   // TODO: implement erase
//   return 0;
// }

// int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n) {
//   // TODO: implement to_array
//   return 0;
// }
