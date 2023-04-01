#include <stdio.h>
#include <stdlib.h>
// 구조체 제작
typedef int element;
typedef struct AVL_Node{
  //key 위치, 높이, 왼쪽, 오른쪽
  int key;
  int height;
  struct AVL_Node *left, *right;
}AVL_Node;

//new 노드 선언
AVL_Node* new_node(AVL_Node* node, element key){
  AVL_Node* temp = (AVL_Node*)malloc(sizeof(AVL_Node));
  temp->key = key;
  temp->height = 1;
  temp->left = NULL;
  temp-> right = NULL;
  return temp;
}

// 최댓값 확인
int max(int left, int right){
  return (left > right) ? left : right; 
}

void print_node2(AVL_Node* node){
  if(node!=NULL){
    printf("%d(%d) -> ",node->key,node->height);
    print_node2(node->left);
    print_node2(node->right);
  }
}

// // 왼쪽 회전
// AVL_Node* left_rotate(AVL_Node* node){
//   // if (node->left ==NULL || node->right == NULL) return node;

//   AVL_Node* y = node->right;
  
//   AVL_Node* T2 = y->left;

//   y->left = node;
//   node->right = T2;
  
//   if (node->left==NULL && node->right ==NULL) node->height = 1;
//   else node->height = 1+max(node->left->height,node->right->height);
//   y-> height = 1+max(y->left->height,y->right->height);

//   return y;
// }

// // 오른쪽 회전
// AVL_Node* right_rotate(AVL_Node* node){
//   // if (node->left == NULL || node->right == NULL) return node;
//   AVL_Node* y = node->left;
//   // print_node2(y);
//   AVL_Node* T2 = y->right;
//   // print_node2(T2);
//   // printf("%d",y->right->key);
//   y->right = node;
  
//   // printf("%d",y->right->key);

//   // printf("%d",y->right->key);
//   node->left = T2;
  
//   // printf("%d",node->left->key);
//   // printf("%d",node->left->height);
//   // printf("%d",y->right->height);
//   // printf("%d",y->right->height);
//   if (node->left==NULL && node->right ==NULL) node->height = 1;
//   else node->height = 1+max(node->left->height,node->right->height);
//   y-> height = 1+max(y->left->height,y->right->height);
  
  // print_node2(y);
//   return y;
// }

AVL_Node* left_rotate(AVL_Node* parent) { //LL회전(오른쪽으로 회전한다)
	AVL_Node* child = parent->left;
	parent->left = child->right; //부모의 왼쪽 노드=자식 오른쪽 노드(부모에게는 NULL값이 왼/오에 달림)
	child->right = parent; //부모를 자식의 오른쪽 노드로(자식 오른쪽에다가 부모 트리 연결)
	return child;
}

AVL_Node* right_rotate(AVL_Node* parent) { //RR회전(왼쪽으로 회전한다)
	AVL_Node* child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;
}

// BF(BalanceFactor)값을 가져오는 함수.
int BalanceFactor(AVL_Node* node){
  if (node==NULL) return 0;
  if (node->right == NULL) return node->left->height-0;
  else if (node->left == NULL) return 0-node->right->height;
  else return node->right->height-node->right->height;
}

// 트리의 높이 균형을 유지하는 함수.
// 4가지 케이스를 가지고 rotate를 수행함.
AVL_Node* Balance(AVL_Node* node){
  int BF = BalanceFactor(node);
  // printf("%d",BF);

  //LL
  if (BF > 1 && node->key > node->left->key){
    node = right_rotate(node);
    return node;
  }
  
  //RR
  if (BF < -1 && node->key < node->right->key){
    node = left_rotate(node);
    
    // printf("%d",node->left->key);
    return node;
  }

  // LR
  // if (BF > 1 && node->key > node->left->key && node->left->key < node->left->right->key){
  //   node = left_rotate(node);
  //   return right_rotate(node);
  // }

  //RL
  // if (BF < -1 && ){

  // }

  return node;
}
// AVL_Node* Balance(AVL_Node* node){
//   int BF = BalanceFactor(node);
//   printf("%d",BF);

//   //LL
//   if (BF > 1) {
//     if (Balance(node->left) > 0) { //왼쪽 노드가 더 크면
// 			//printf("LL\n");
// 			node = right_rotate(node); //오른쪽으로 돌림
//     }
// 		else {
// 			//printf("LR\n");
//       node = right_rotate(node);
// 			node = left_rotate(node);
            

//        //아니면 오른쪽-왼쪽으로
// 		}
//   }
// 	else if (BF < -1) { //오른쪽 서브트리 균형을 맞춤
// 		if (Balance(node->right) < 0) { //오른쪽 노드가 더 크면
// 			//printf("RR\n");
// 			node = left_rotate(node); //왼쪽으로 돌림
// 		}
// 		else {
// 			//printf("RL\n");
// 			node = right_rotate(node);
//         node = left_rotate(node);

//        //아니면 왼쪽-오른쪽으로
// 		}
// 	}

//   return node;
// }
// 삽입 함수.
AVL_Node* insert_node(AVL_Node* node, element key){
  if (node==NULL) return new_node(node,key);
  else if (key < node->key) {
    node->left = insert_node(node->left,key);
  }
  else if (key > node->key) {
    node->right =  insert_node(node->right,key);
    // node->height = node->right->height;
  }

  if (node->left ==NULL){
    node->height = 1+max(0,node->right->height);
  }

  else if (node->right==NULL){
    node->height = 1+max(node->left->height,0);
  }

  else {
    node->height = 1+max(node->left->height,node->right->height);
  }

  node = Balance(node);
  // print_node2(node);
  // printf("\n");

  return node;
}

// 출력 함수
AVL_Node* root = NULL;
void print_node(AVL_Node* node,int height){
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



int main(){
  AVL_Node* node = NULL;
  node=insert_node(node,30);
  node=insert_node(node,40);
  // print_node2(node);
  node=insert_node(node,35);
  // insert_node(node,25);
  print_node2(node);
  // print_node(node);
  return 1;
}
