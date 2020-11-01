#include <iostream>
#include <utility> // swap
#include "limits.h" // ULLONG_MAX, UINT_MAX
#include <cstdlib> // getchar

#define ull unsigned long long

static ull previous_;
static ull current_;
static unsigned index_;

void fibonacci_init(const ull a, const ull b)
{
	index_ = 0;
	current_ = a;
	previous_ = b;
}

bool fibonacci_next()
{
	if ((ULLONG_MAX - previous_ < current_) || (UINT_MAX == index_))
		return false;

	if (index_ > 0)
		previous_ += current_;

	std::swap(current_, previous_);
	++index_;

	return true;
}

ull fibonacci_current()
{
	return current_;
}

unsigned fibonacci_index()
{
	return index_;
}

int main()
{
	fibonacci_init(1, 1);

	do {
		std::cout << fibonacci_index() << ": "
			<< fibonacci_current() << std::endl;
	} while (fibonacci_next());

	std::cout << fibonacci_index() + 1 <<
		" Fibonacci sequence values fit in an " <<
		"unsigned 64-bit integer." << std::endl;

	std::getchar();
	return 0;
}