#include"../leetcodetest/head.h"

bool isPowerOfTwo(int n)
{
	return (n > 0) && !(n&(n - 1));
}

int main()
{
	return 0;
}