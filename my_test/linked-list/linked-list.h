// int 자료형 선언
typedef int element;

// 구조체 구성
typedef struct LinkedNode{
    // 값을 담는 공간
    element data;
    // 주소를 담는 공간
    struct LinkedNode* link;
}LinkedNode;

LinkedNode* insert_first(LinkedNode* head, element value);
int max_value(LinkedNode* head);
LinkedNode* find_value(LinkedNode* head,element x);
void print_node(LinkedNode* head);
LinkedNode* delete_first(LinkedNode* head);
LinkedNode* delete_pre(LinkedNode* head, LinkedNode* pre);
LinkedNode* insert_pre(LinkedNode* head, LinkedNode* pre, element value);
