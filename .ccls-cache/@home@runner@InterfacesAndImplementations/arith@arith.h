#ifndef __ARITH_ARITH_H
#define __ARITH_ARITH_H

#define DIV_TRUNCATES_TO_0(x, y) 	(((x) / (y)) < 0)
#define DIFF_SIGN(x, y) 			(((x) < 0) != ((y) < 0))

extern int arith_max(int x, int y);
extern int arith_min(int x, int y);
extern int arith_div(int x, int y);
extern int arith_mod(int x, int y);
extern int arith_ceil(int x, int y);
extern int arith_floor(int x, int y);

#endif