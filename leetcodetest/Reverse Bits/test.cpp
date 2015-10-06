#include"../leetcodetest/head.h"

class Solution
{
public:
	uint32_t reverseBits(uint32_t n)
	{
		uint32_t i, bit1 = 1, bit2 = 1, res = 0;
		for (i = 0; i < 32; i++, bit1 = bit1 << 1, bit2 = 1)
		{
			if (bit1&n)
				res += bit2 << (31 - i);
		}
		return res;
	}
};

int main()
{
	return 0;
}