#define MAX_QUEUE_SIZE 5
// int 자료형 선언
typedef int element;

// 구조체 선언
typedef struct Queue{
    int front;
    int rear;
    char arr[MAX_QUEUE_SIZE];
}Queue;

void init_que(Queue* que);
void print_que(Queue* que);
int is_full(Queue* que);
int is_none(Queue* que);
void enque(Queue* que, element val);
void deque(Queue* que);