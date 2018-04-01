#ifndef _NAT_H
#define _NAT_H

#define MY_SIZEOF(TYPE) ((char *)(&TYPE+1)-(char *)(&TYPE))

#define MY_OFFSETOF(TYPE, MEMBER) ((size_t)&(((TYPE *)0)->MEMBER))

#define CRASH()				\
	({				\
		((void(*)())0)();	\
	})

//
#define SWAP(a, b) 				\
	({ 					\
		__typeof__(a) temp = a; 	\
		a = b; 				\
		b = temp; 			\
	})
#define swap_nat SWAP

#define MAX(a, b) 				\
	({ 					\
		__typeof__(a) _a = (a); 	\
		__typeof__(b) _b = (b); 	\
		_a > _b ? _a : _b; 		\
	})
#define max_nat MAX

#define MIN(a, b)				\
	({					\
		__typeof__(a) _a = (a); 	\
		__typeof__(b) _b = (b); 	\
		_a < _b ? _a : _b;		\
	})
#define min_nat MIN
//

#endif
