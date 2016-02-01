#include<vector>
#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
	int bulbSwitch(int n) {
		return (int)sqrt(n);
	}
};

// 为了寻找规律
//class Solution {
//public:
//	int bulbSwitch(int n) {
//		vector<bool> test(n, true);
//
//		for (size_t i = 2;i <= n;++i)
//		{
//			for (size_t j = i - 1;j < n;j += i)
//			{
//				if (test[j] == true)
//				{
//					test[j] = false;
//				}
//				else test[j] = true;
//			}
//		}
//
//		int num = 0;
//		for (size_t i = 0;i < n;++i)
//		{
//			if (test[i]) ++num;
//		}
//		return num;
//	}
//};

int main()
{
	Solution sol;
	for (int i = 1;i < 65;++i)
	{
		cout << i << " : " << sol.bulbSwitch(i) << endl;
	}

	return 0;
}