#include "arith.h"

int arith_max(int x, int y) {
	return x > y ? x : y;
}

int arith_min(int x, int y) {
	return x > y ? y : x;
}

int arith_div(int x, int y) {
	if (DIV_TRUNCATES_TO_0(x, y) &&
		DIFF_SIGN(x, y) &&
		x % y != 0) {
		return x / y - 1;
	} else {
		return x / y;
	}
}

int arith_mod(int x, int y) {
	if (DIV_TRUNCATES_TO_0(x, y) &&
		DIFF_SIGN(x, y) &&
		x % y != 0) {
		return x % y + y;
		} else {
		return x % y;
		}
}

int arith_floor(int x, int y) {
	return arith_div(x, y);
}

/* arith_ceil is arith_div + 1, unless y divides x evenly */
int arith_ceil(int x, int y) {
	return arith_div(x, y) + (x % y != 0);
}
