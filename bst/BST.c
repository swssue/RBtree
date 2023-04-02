// BST.c 실행할 함수에 대한 상세한 내용이 있는 곳
#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
// 이진 검색 트리

// // 구조체 생성
// typedef int element;
// typedef struct TreeNode{
//     int data;
//     struct TreeNode *left, *right;
// }TreeNode;

//빈 노드 생성
TreeNode* new_node(TreeNode* root, element data){
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left, node->right = NULL;
    return node;
}

// 노드 삽입
TreeNode* insert_node(TreeNode* root, element data){
    if (root==NULL) return new_node(root,data);
    if (data > root->data) root->right = insert_node(root->right,data);
    else if (data < root->data) root->left = insert_node(root->left,data);

    return root;
}
// key 존재 여부 확인
// 반복적 탐색
int wh_find(TreeNode* root, element find_data){
    TreeNode* temp = root;
    while(temp!=NULL){
        if(temp->data == find_data){
            return 1;
        }
        if (find_data > temp->data) temp = temp->right;
        else temp = temp->left;
    }

    return 0;
}

// 순환적 탐색
TreeNode* re_find(TreeNode* root, element find_data){
    if (root==NULL) return NULL;
    if (find_data == root->data) return root;
    else if (find_data > root->data) return re_find(root->right,find_data);  
    else return re_find(root->left,find_data);
}

// 삭제 시 최솟값 찾기(반복)
TreeNode* min_value(TreeNode* root){
    TreeNode* p = root;
    while (p->left!=NULL){
        p = p->left;
    }
    return p;
}

// 노드 삭제
TreeNode* delete_node(TreeNode* root, element data){
    if (root==NULL) return root;
    // 키 찾기
    if (data > root->data){
        root-> right = delete_node(root->right,data);
    } 
    else if (data < root->data){
        root -> left = delete_node(root->left,data);
    }
    else{
        //// 단말 노드 or 노드 한 개 연결
        if (root->left == NULL){
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL){
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        //// 서브트리 존재
        TreeNode* temp = min_value(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right,temp->data);

    }

    return root;
    
}

// 노드 출력 순회
void print_node(TreeNode* node){
    if(node!=NULL){
        print_node(node->left);
        printf("%d->",node->data);
        print_node(node->right);
        
    }
}

// // 메인 함수
// int main(){
//     TreeNode* root = NULL;
//     root = insert_node(root,10);
//     insert_node(root,5);
//     insert_node(root,20);
    
//     insert_node(root,40);
//     print_node(root);
//     // printf("%d",re_find(root,10)==NULL? 0 : 1);
//     printf("\n");
//     delete_node(root,5);
//     print_node(root);
//     return 1;
// }