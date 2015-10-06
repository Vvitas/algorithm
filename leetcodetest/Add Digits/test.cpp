#include"../leetcodetest/head.h"

class Solution {
public:
	int addDigits(int num) {
		return (num - 1) % 9 + 1;
	}
};

int main()
{
	return 0;
}