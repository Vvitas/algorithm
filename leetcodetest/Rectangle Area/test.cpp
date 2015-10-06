#include"../leetcodetest/head.h"

class Solution
{
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
	{
		int result = (C - A)*(D - B) + (G - E)*(H - F);
		if (C<E || D<F || A>G || B>H)
			return result;

		int top = min(D, H);
		int bottom = max(B, F);
		int left = max(A, E);
		int right = min(C, G);

		return result - (right - left)*(top - bottom);
	}
};


int main()
{
	return 0;
}

class Solution
{
public:
	int reverse(int x)
	{
		queue<int> data;
		bool sign = x < 0 ? true : false;

		x *= (x < 0) ? -1 : 1;
		while (x)
		{
			data.push(x % 10);
			x = x / 10;
		}

		long long result = 0;
		while (!data.empty())
		{
			result = result * 10 + data.front();
			data.pop();

			if (result > INT_MAX) return 0;
		}

		result *= sign ? -1 : 1;

		if (result<INT_MIN || result>INT_MAX)
			return 0;
		else return (int)result;
	}
};