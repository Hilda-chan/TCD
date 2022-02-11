#ifndef stack_H_
#define stack_H_


// A structure to represent a stack
struct Stack {
	int top;
	int capacity;
	char* array;
};
struct Stack* createStack(int capacity);
int isFull(struct Stack* stack);
int isEmpty(struct Stack* stack);
void push(struct Stack* stack, char item);
char pop(struct Stack* stack);
char peek(struct Stack* stack);


#endif
