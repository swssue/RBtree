// BST.h c로 만든 함수에 대한 정보가 들어있는 메뉴판 느낌
typedef int element;
typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
}TreeNode;

TreeNode* new_node(TreeNode* root, element data);
TreeNode* insert_node(TreeNode* root, element data);
int wh_find(TreeNode* root, element find_data);
TreeNode* re_find(TreeNode* root, element find_data);
TreeNode* min_value(TreeNode* root);
TreeNode* delete_node(TreeNode* root, element data);
void print_node(TreeNode* node);