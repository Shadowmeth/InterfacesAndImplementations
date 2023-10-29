#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define __ALIGN_SIZE (__WORDSIZE / 8)
#define isBadPtr(ptr) ((size_t)(ptr) % __ALIGN_SIZE != 0)

int main(int argc, char *argv[]) {
	int *n = (int *)malloc(sizeof(int));
	char *c = (char *)n;
	c++;
	printf("%d\n", isBadPtr(n));
	printf("%d\n", isBadPtr(c));	
	
	return EXIT_SUCCESS;
}
