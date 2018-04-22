#ifndef _NAT_UTILITY_H
#define _NAT_UTILITY_H

typedef enum { false, true } bool;

#define offsetof(type, member) (size_t)&(((type *)0)->member)

#define container_of(ptr, type, member) ({			\
	const typeof( ((type *)0)->member ) *__mptr = (ptr);	\
	(type *)( (char *)__mptr - offsetof(type, member) );})

#endif
