#include "Queue.h"

// 메인
int main(){
    Queue a;
    // Queue* p = &a;
    Queue p;

    init_que(&p);

    enque(&p,10); print_que(&p);
    enque(&p,20); print_que(&p);
    enque(&p,30); print_que(&p);
    enque(&p,30); print_que(&p);
    enque(&p,30); print_que(&p);

    deque(&p); print_que(&p);
    deque(&p); print_que(&p);
    deque(&p); print_que(&p);

    
    
    return 1;
}