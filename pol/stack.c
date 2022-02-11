// C program for array implementation of stack
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack* createStack(int capacity)
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (char*)malloc(stack->capacity * sizeof(char));
	return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{
	return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}

// Function to add an item to stack. It increases top by 1
void push(struct Stack* stack, char item)
{
	if (isFull(stack))
		return;
	stack->array[++stack->top] = item;
	//printf("%d pushed to stack\n", item);
}

// Function to remove an item from stack. It decreases top by 1
char pop(struct Stack* stack)
{
	if (isEmpty(stack))
		return EXIT_FAILURE;
	return stack->array[stack->top--];
}

// Function to return the top from stack without removing it
char peek(struct Stack* stack)
{
	if (isEmpty(stack))
		return EXIT_FAILURE;
	return stack->array[stack->top];
}

