#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "stack/stack.h"

int main(int argc, char *argv[]) {
	stack_t stack = stack_new();
	
	int *n1, *n2, *n3;
	n1 = (int *)malloc(sizeof(int));
	n2 = (int *)malloc(sizeof(int));
	n3 = (int *)malloc(sizeof(int));
	
	printf("Enter a number: ");
	scanf("%d", n1);
	stack_push(stack, (void *)n1);

	printf("Enter a number: ");
	scanf("%d", n2);
	stack_push(stack, (void *)n2);

	printf("Enter a number: ");
	scanf("%d", n3);
	stack_push(stack, (void *)n3);

	int *ptr = stack_pop(stack);
	printf("%d\n", *ptr); // should print n3
	
	return EXIT_SUCCESS;
}
