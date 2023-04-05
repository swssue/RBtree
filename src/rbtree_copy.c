#include "rbtree.h"

#include <stdlib.h>
#include <stdio.h>

rbtree *new_rbtree(void) {
  rbtree *p = (rbtree *)calloc(1, sizeof(rbtree));
  // TODO: initialize struct if needed


  // NO Sentinel
  // node_t *root = (node_t *)calloc(1, sizeof(node_t));
  // p->root = NULL;

  // Yes Sentinel => 추후 예정
  node_t *nilNode = (node_t *)calloc(1, sizeof(node_t));
  
  nilNode->color = RBTREE_BLACK;
  p->nil = nilNode;
  p->root = nilNode;
  
  return p;
}

void right_rotation(rbtree * tree, node_t * x){
    // TODO!

    node_t *y;

    // 1. target의 left으로 y 설정
    y = x->left;
    // 2. y의 오른쪽 서브트리를 target의 왼쪽 서브트리로 옮김
    x->left = y->right;
    // 3. y의 오른쪽 노드가 NIL이 아니라면, y의 오른쪽 노드 부모를 target으로 설정
    if (y->right != tree->nil) {
        y->right->parent = x;
    }
    // 4. y의 부모 노드를 target의 부모 노드로 설정
    y->parent = x->parent;
    // 5. target의 부모 노드가 nil이라면, 트리 구조체의 root를 y로 설정
    if (x->parent == tree->nil)
        tree->root = y;
    // 6. target이 target 부모 노드의 왼쪽이면, target 부모의 왼쪽을 y로 설정
    else if (x == x->parent->left)
        x->parent->left = y;
    // 7. target이 target 부모 노드의 오른쪽이면, target 부모의 오른쪽을 y로 설정
    else
        x->parent->right = y;
    // 8. target을 y의 오른쪽으로 설정
    y->right = x;
    // 9. target의 부모를 y로 설정
    x->parent = y;
}

void left_rotation(rbtree * tree, node_t * x){
    // TODO!
    node_t *y;

    y = x->right;
    x->right = y->left;
    
    if (y->left != tree->nil) 
        y->left->parent = x;
    
    y->parent = x->parent;
    
    if (x->parent == tree->nil) 
        tree->root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else 
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void delete_for_postorder(rbtree *t, node_t *p){
  if (p!=t->nil){
    delete_for_postorder(t,p->left);
    delete_for_postorder(t,p->right);
    free(p);
    // NULL 값으로 초기화를 해줘야 불필요한 에러를 방지할 수 있따.
    p = NULL;
  }
}

void delete_rbtree(rbtree *t) {
  // TODO: reclaim the tree nodes's memory
  delete_for_postorder(t, t->root);
  free(t->nil);
  t->nil = NULL;
  free(t);
  t = NULL;
}

void rbtree_insert_fixup(rbtree *t, node_t *z) {
  node_t *y;
  
  while (z->parent->color == RBTREE_RED) {
    // z의 부모가 조부모의 왼쪽 서브 트리일 경우
    if (z->parent == z->parent->parent->left) {
      y = z->parent->parent->right;
      
      // CASE 1 : 노드 z의 삼촌 y가 적색인 경우
      if (y->color == RBTREE_RED) {
        z->parent->color = RBTREE_BLACK;
        y->color = RBTREE_BLACK;
        z->parent->parent->color = RBTREE_RED;
        z = z->parent->parent;
      }
      // CASE 2 : z의 삼촌 y가 흑색이며의 z가 오른쪽 자식인 경우
      else {
        if (z == z->parent->right) {
          z = z->parent;
          left_rotation(t, z);
        }
        // CASE 3 : z의 삼촌 y가 흑색이며의 z가 오른쪽 자식인 경우
        z->parent->color = RBTREE_BLACK;
        z->parent->parent->color = RBTREE_RED;
        right_rotation(t, z->parent->parent);
      }
    }
    // z의 부모가 조부모의 왼쪽 서브 트리일 경우
    else {
      y = z->parent->parent->left;

      // CASE 4 : 노드 z의 삼촌 y가 적색인 경우
      if (y->color == RBTREE_RED) {
        z->parent->color = RBTREE_BLACK;
        y->color = RBTREE_BLACK;
        z->parent->parent->color = RBTREE_RED;
        z = z->parent->parent;
      }
      // CASE 5 : z의 삼촌 y가 흑색이며의 z가 오른쪽 자식인 경우
      else {
        if (z == z->parent->left) {
          z = z->parent;
          right_rotation(t, z);
        }
        // CASE 6 : z의 삼촌 y가 흑색이며의 z가 오른쪽 자식인 경우
        z->parent->color = RBTREE_BLACK;
        z->parent->parent->color = RBTREE_RED;
        left_rotation(t, z->parent->parent);
      }
    }
  }
  t->root->color = RBTREE_BLACK;
}

node_t *rbtree_insert(rbtree *t, const key_t key) {
  // TODO: implement insert
  node_t *y = t->nil;
  node_t *x = t->root;
  node_t *z = (node_t *)calloc(1, sizeof(node_t));
  
  z->key = key;

  while (x != t->nil) {
    y = x;
    if (z->key < x->key)
      x = x->left;
    else
      x = x->right; 
  }

  z->parent = y;
  
  if (y == t->nil) {
    t->root = z;
  }
  else if (z->key < y->key) {
    y->left = z;
  }
  else {
    y->right = z;
  }

  z->left = t->nil;
  z->right = t->nil;
  z->color = RBTREE_RED;

  rbtree_insert_fixup(t, z);

  return z;
}

node_t *rbtree_find(const rbtree *t, const key_t key) {
  // TODO: implement find
  node_t *p = t->root;
  while(p!=t->nil){
    if (p->key==key) {
      // printf("키 값 : %d를 찾았습니다\n",p->key);
      return p;
    }
    else if (p->key > key) p = p->left;
    else if (p->key < key) p = p->right;
  }

  return NULL;
}

node_t *rbtree_min(const rbtree *t) {
  // // TODO: implement find
  node_t *p = t->root;
  while(p->left!=t->nil && p->right!=t->nil){
    p = p->left;
  }

  printf("최솟값은 : %d\n",p->key);
  return p;
}

node_t *rbtree_max(const rbtree *t) {
  // TODO: implement find
  node_t *p = t->root;
  while(p->left!=t->nil && p->right!=t->nil){
    p=p->right;
  }
  printf("최댓값은 : %d\n",p->key);
  return p;
}


node_t *min_value(rbtree *t, node_t* p) {
  // // TODO: implement find
  while(p->left!=t->nil && p->right!=t->nil){
    p = p->left;
  }

  return p;
}

void rbtree_delete_fixup(rbtree *t, node_t *x) {
  node_t *w;
  while ((x != t -> root) && (x -> color == RBTREE_BLACK))
  {
    if (x == x -> parent -> left)
    {
      w = x -> parent -> right;
      if (w -> color == RBTREE_RED)
      {
          w -> color = RBTREE_BLACK;
          x -> parent -> color = RBTREE_RED;
          left_rotation(t, x -> parent);
          w = x -> parent -> right;
      }
      if (w -> left -> color == RBTREE_BLACK && w -> right -> color == RBTREE_BLACK)
      {
          w -> color = RBTREE_RED;
          x = x -> parent;
      }
      else
      {
        if (w -> right -> color == RBTREE_BLACK)
        {
            w -> left -> color = RBTREE_BLACK;
            w -> color = RBTREE_RED;
            left_rotation(t, w);
            w = x -> parent -> right;
        }
        w -> color = x -> parent -> color;
        x -> parent -> color = RBTREE_BLACK;
        w -> right -> color = RBTREE_BLACK;
        left_rotation(t, x -> parent);
        x = t->root;
      }
    }
    else
    {
      w = x -> parent -> left;
      if (w -> color == RBTREE_RED)
      {
          w -> color = RBTREE_BLACK;
          x -> parent->color = RBTREE_RED;
          left_rotation(t, x -> parent);
          w = x -> parent->left;
      }
      if (w -> right -> color == RBTREE_BLACK && w -> left -> color == RBTREE_BLACK)
      {
          w -> color = RBTREE_RED;
          x = x -> parent;
      }
      else
      {
        if (w -> left -> color == RBTREE_BLACK)
        {
            w -> right -> color = RBTREE_BLACK;
            w -> color = RBTREE_RED;
            left_rotation(t, w);
            w = x -> parent -> left;
        }
        w -> color = x -> parent -> color;
        x -> parent -> color = RBTREE_BLACK;
        w -> left -> color = RBTREE_BLACK;
        right_rotation(t, x -> parent);
        x = t -> root;
      }
    }
  }
  x -> color = RBTREE_BLACK;
}

 node_t *delete_node(rbtree *t, node_t *p, node_t* node){
   
  color_t del_color = p->color;
  if (node->key > p->key) node->left = delete_node(t,p,node->left);
  else if (node->key < p->key) node-> right = delete_node(t,p,node->right);
  else{
    // 색깔이 Black인 경우
    if (del_color == RBTREE_BLACK){
        if (node->left == t->nil){
        node_t* temp = node->right; 
        rbtree_delete_fixup(t,node);
        free(node);
        node = NULL;
        return temp;
        }

      else if (node->right == t->nil){
        node_t* temp = node->left;
        rbtree_delete_fixup(t,node);
        free(node);
        node = NULL;
        return temp;
      }

      node_t* temp = min_value(t,node->right);
      node->key = temp->key;
      node->right = delete_node(t,temp,node->right);
    }
    //색깔이 Red인 경우
    else{
      if (node->left == t->nil){
      node_t* temp = node->right; 
      free(node);
      node = NULL;
      return temp;
      }

    else if (node->right == t->nil){
      node_t* temp = node->left;
      free(node);
      node = NULL;
      return temp;
    }

    node_t* temp = min_value(t,node->right);
    node->key = temp->key;
    node->right = delete_node(t,temp,node->right);
    }
  }

  return t->root;
 }

int rbtree_erase(rbtree *t, node_t *p) {
  // TODO: implement erase
  delete_node(t,p,t->root);
  
  return 0;
}

int inorder_for_array(rbtree *t, node_t *p, key_t *arr, const size_t n, int idx){
  if (idx>n) return 0;

  if (p->left!=t->nil) idx = inorder_for_array(t, p->left, arr, n, idx);

  arr[idx] = p->key; 
  
  if(p->right!=t->nil){
    inorder_for_array(t, p->right, arr, n, idx+1);
    return idx;
  }
  
  return idx+1;
}

int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n) {
  // TODO: implement to_array
  inorder_for_array(t, t->root, arr, n, 0);
  return 0;
}