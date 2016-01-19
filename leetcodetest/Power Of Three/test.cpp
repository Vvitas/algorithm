#include<iostream>
using std::cout;
using std::endl;

// ������û�뵽���õķ���,���3�Ĵη������Ƽ�˼·
class Solution {
public:
	bool isPowerOfThree(int n) {

		if (!(n & 1) || n <= 0) return false;

		size_t num1 = 1, num2 = 3;
		while (true)
		{
			if (n == num1 || n == num2)
				return true;
			else if (n > num2)
			{
				num1 = num2;num2 *= 3;
			}
			else return false;
		}
	}
};

int main()
{
	Solution test;
	cout << std::boolalpha << test.isPowerOfThree(15) << endl;
	cout << std::boolalpha << test.isPowerOfThree(2097) << endl;
	cout << std::boolalpha << test.isPowerOfThree(81 * 81) << endl;
	return 0;
}