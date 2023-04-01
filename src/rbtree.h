// ifndef : 헤더 파일이 겹치는 것을 막기 위한 메크로 예를 들어 다른 파일에서 stdio.h 헤더 파일을 사용하고 있는데 또 불러오면 에러가 나기 때문에 이를 막기 위한 메크로
#ifndef _RBTREE_H_
// define : 해당 상수 값 예약
#define _RBTREE_H_
// stddef.h :  포인터,변수,유형을 선언하는 헤더
#include <stddef.h>
// 메모리를 사용하지 않고 별칭을 붙여주는 개념
// color_t라는 이름의 열거형 구조체를 선언한다.
typedef enum { RBTREE_RED, RBTREE_BLACK } color_t;
// 타입 이름 대신 사용하는 별칭 : key_t를 int 자료형의 별칭으로 정의한다.
typedef int key_t; 
// node_t 구조체 선언
typedef struct node_t {
  color_t color; // 현재 색깔
  key_t key; // int형 key 변수
  struct node_t *parent, *left, *right; // 자기 참조 구조체
} node_t;
// rbtree 구조체 
typedef struct {
  node_t *root; // 실 데이터 구조체
  node_t *nil;  // 센티넬 노드로 값이 없는 nill 노드를 구현하기 위한 구조체
} rbtree;

// rbtree 구조체 시작
rbtree *new_rbtree(void);
// rbtree 구조체 전체 변수 가져오기?
// void delete_rbtree(rbtree *);
// // 반환 값 node_t 형태
node_t *rbtree_insert(rbtree *, const key_t);
// node_t *rbtree_find(const rbtree *, const key_t);
// node_t *rbtree_min(const rbtree *);
// node_t *rbtree_max(const rbtree *);

// int rbtree_erase(rbtree *, node_t *);

// int rbtree_to_array(const rbtree *, key_t *, const size_t);

#endif  // _RBTREE_H_
