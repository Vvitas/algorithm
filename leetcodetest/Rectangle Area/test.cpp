#include "../leetcodetest/head.h"

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