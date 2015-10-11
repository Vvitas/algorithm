#include"../leetcodetest/head.h"

class Solution 
{
public:
	int countPrimes(int n) 
	{
		if (n <= 2) return 0;

		size_t i, j;
		vector<bool> isPrime(n,true);
		for (i = 2; i*i < n; i++)
		{
			if (isPrime[i])
			{
				for ( j = i*i; j < n; j+=i)
				{
					isPrime[j] = false;
				}
			}
		}

		int num = 1;
		for (i = 3; i < n; i += 2)
		{
			if (isPrime[i])
				++num;
		}
		return num;
	}
};

int main()
{
	return 0;
}