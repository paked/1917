#define STACK_SIZE 100

typedef struct _stack * Stack;
Stack newStack(void);
Stack pop(Stack);
Stack push(Stack, int);
int top(Stack);
