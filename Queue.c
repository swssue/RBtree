#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

// int 자료형 선언
typedef int element;

// 구조체 선언
typedef struct Queue{
    int front;
    int rear;
    char arr[MAX_QUEUE_SIZE];
}Queue;

// 오류 함수

// 선형 큐 초기화
void init_que(Queue* que){
    que->rear = -1;
    que->front =-1;
}
// 선형 큐 상태 출력

// 선형 큐가 포화상태인가?
int is_full (Queue* que){
    if (que->rear == MAX_QUEUE_SIZE-1){
        return 1;
    }
    return 0;
}
// 선형 큐가 공백상태인가?
int is_none(Queue* que){
    if (que->rear == que->front){
        return 1;
    }
    return 0;
}
// 선형 큐에 데이터 삽입
void enque()
// 선형 큐에서 데이터 제거

// 메인
int main(){
    Queue a;
    // Queue* p = &a;
    Queue p;

    init_que(&p);



    return 1;
}
