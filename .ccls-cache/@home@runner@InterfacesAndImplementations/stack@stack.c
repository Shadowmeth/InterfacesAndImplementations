#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include "stack.h"

typedef struct stack {
	int count;
	struct elem {
		void *item;
		struct elem *link;
	} *head;
} *stack_t;

stack_t stack_new(void) {
	stack_t stack = (struct stack *)malloc(sizeof(struct stack));
	if (stack == NULL) {
		return NULL;
	}
	stack->count = 0;
	stack->head = NULL;
	return stack;
}

int stack_empty(stack_t stack) {
	assert(stack && "null passed to stack_empty");	
	return stack->count == 0;
}

void stack_push(stack_t stack, void *item) {
	struct elem *t;
	assert (stack && "null passed to stack_push");
	t = (struct elem *)malloc(sizeof(struct elem));
	t->item = item;
	t->link = stack->head;
	stack->head = t;
	stack->count++;
}

void *stack_pop(stack_t stack) {
	void *item;
	struct elem *t;
	assert(stack && "null passed to stack_pop");
	assert(stack->count > 0 && "cannot pop from empty stack");
	t = stack->head;
	stack->head = t->link;
	stack->count--;
	item = t->item;
	free(t);
	t = NULL;
	return item;
}

void stack_free(stack_t *stack) {
	// notice this is a double pointer
	struct elem *t, *u;
	assert(stack && *stack && "null passed to stack_free");
	for (t = (*stack)->head; t; t = u) {
		u = t->link;
		free(t);
		t = NULL;
	}

	free(*stack);
	*stack = NULL;
}

