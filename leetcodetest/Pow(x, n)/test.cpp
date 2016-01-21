#include"../leetcodetest/head.h"

class Solution
{
private:
	bool isEqual(const double& a, const double& b)
	{
		return (fabs(a - b) < 1e-10) ? true : false;
	}

	double PowNum(const double& x, int n)
	{
		if (0 == n) return 1.0;
		else if (1 == n) return x;

		double res = PowNum(x, n >> 1);
		return (n & 0x01) ? (res*res*x) : res*res;
	}

public:
	double myPow(double x, int n)
	{
		if (isEqual(x, 0))   return 0;
		if (isEqual(x, 1.0)) return 1.0;
		if (isEqual(x, -1.0))
		{
			if (n & 0x01)    return -1.0; else return 1.0;
		}
		if (n == 0) return 1.0;

		if (n < 0)
			return 1.0 / PowNum(x, -n);
		else return PowNum(x, n);
	}
};

int main()
{
	Solution test;
	cout << test.myPow(1.1, 5) << " " << pow(1.1, 5) << endl;
	cout << test.myPow(12, -5) << " " << pow(12, -5) << endl;
	cout << test.myPow(13.2, 11) << " " << pow(13.2, 11) << endl;
	return 0;
}
