#ifndef __STACK_STACK_H
#define __STACK_STACK_H

typedef struct stack *stack_t;

extern stack_t stack_new(void);
extern int stack_empty(stack_t stack);
extern void stack_push(stack_t stack, void *item);
extern void *stack_pop(stack_t stack);
extern void stack_free(stack_t *stack);

#endif