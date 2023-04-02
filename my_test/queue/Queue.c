#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
// #define MAX_QUEUE_SIZE 5

// // int 자료형 선언
// typedef int element;

// // 구조체 선언
// typedef struct Queue{
//     int front;
//     int rear;
//     char arr[MAX_QUEUE_SIZE];
// }Queue;

// 선형 큐 초기화
void init_que(Queue* que){
    que->rear = -1;
    que->front =-1;
}
// 선형 큐 상태 출력
void print_que(Queue* que){
    for (int i=0;i<MAX_QUEUE_SIZE;i++){
        if(i<=que->front || i>que->rear){
            printf("   |");
        }
        else{
            printf("%d |",que->arr[i]);
        }
        
    }
    printf("\n");
}
// 선형 큐가 포화상태인가?
int is_full(Queue* que){
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
void enque(Queue* que, element val){
    if (is_full(que)){
        printf("큐가 포화상태 입니다.\n");
        exit(1);
    }

    que->arr[++(que->rear)] = val;
}
// 선형 큐에서 데이터 제거
void deque(Queue* que){
    if(is_none(que)){
        printf("제거할 데이터가 없습니다.\n");
        exit(1);
    }

    que->arr[++(que->front)];
}
// // 메인
// int main(){
//     Queue a;
//     // Queue* p = &a;
//     Queue p;

//     init_que(&p);

//     enque(&p,10); print_que(&p);
//     enque(&p,20); print_que(&p);
//     enque(&p,30); print_que(&p);
//     enque(&p,30); print_que(&p);
//     enque(&p,30); print_que(&p);

//     deque(&p); print_que(&p);
//     deque(&p); print_que(&p);
//     deque(&p); print_que(&p);

    
    
//     return 1;
// }
