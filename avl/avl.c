#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct Node{
  int key;
  int height;
  struct Node *left,*right;
} Node;

int max(Node* l, Node* r){
  if (l == NULL && r == NULL) return 0;
  else if (l==NULL) return r->height;
  else if (r==NULL) return l->height;
  else return l->height > r->height ? l->height: r->height;
}

int Balance_cal(Node* node){
  if(node == NULL) return 0;
  if (node->left == NULL) return 0-node->right->height;
  else if (node->right == NULL) return node->left->height-0;
  else return node->left->height - node->right->height;
}


Node* leftRotate(Node* node){
  Node* y = node->right;
  Node* T2 = y->left;


  y->left = node;
  node->right = T2;

  node->height = 1+max(node->left,node->right);
  y->height =  1+max(y->left,y->right);
  
  return y;
}

Node* rightRotate(Node* node){
  Node* y = node->left;
  Node* T2 = y->right;

  y->right = node;
  node->left = T2;

  node->height = 1+max(node->left,node->right);
  y->height =  1+max(y->left,y->right);
  
  return y;
}

Node* Balance (Node* node){
  int BF = Balance_cal(node);
  // printf("!!%d",BF);
  //ll
  if (BF > 1 && Balance_cal(node->left) > 0 ){
    return rightRotate(node);
  }
  //rr
  else if (BF < -1 && Balance_cal(node->right) < 0){
    return leftRotate(node);
  }
  //lr
  else if (BF > 1 && Balance_cal(node->left) < 0){
    node->left = leftRotate(node->left);
    // return node;
    return rightRotate(node);
  }

  //lr
  else if (BF < -1 && Balance_cal(node->right) > 0){
    node->right = rightRotate(node->right);
    // return node;
    return leftRotate(node);
  }

  return node;
}


Node* insert(Node* node,element key){
  if (node==NULL) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->key = key;
    temp->height = 1;
    temp->left,temp->right =NULL;
    return temp;
  }
  
  if (node->key > key) node->left = insert(node->left,key);    
  else if (node->key < key) node->right = insert(node->right,key);
  
  if (node->left == NULL) node->height = 1+node->right->height;
  else if (node->right==NULL) node->height = 1+node->left->height;
  else node->height = 1+max(node->left,node->right);

  node = Balance(node);

  return node;
}

// 출력 함수
Node* root = NULL;
void print_node(Node* node,int height){
  if(node!=NULL){
    print_node(node->right,height+1);
    printf("\n");
    if (node == root)
      printf("Root : ");
    for (int i=0;i<height && node!=root;i++)
      printf("    ");
    printf("%d(%d)",node->key,node->height);
    print_node(node->left,height+1);
  }
}

void pf(Node* node){
  if (node!=NULL){
    printf("%d(%d)->",node->key,node->height);
    pf(node->left);
    pf(node->right);
  }
}

int main(){
  Node* node = NULL;
  node = insert(node,30);
  // printf("%d->",node->height);
  // printf("%d->",node->key);
  node=insert(node,40);
  node=insert(node,35);
  node=insert(node,50);
  node=insert(node,60);
  node=insert(node,50);
  node=insert(node,25);
  node=insert(node,20);
  node=insert(node,31);
  node=insert(node,32);
  node=insert(node,33);
  node=insert(node,19);

  // pf(node);
  print_node(node,node->height);
  return 1;
}