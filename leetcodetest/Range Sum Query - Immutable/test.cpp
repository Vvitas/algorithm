#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
	vector<long> sums;

	NumArray(vector<int> &nums) {

		if (nums.empty()) return;
		sums.reserve(nums.size());

		long num = 0;
		for (size_t i = 0;i < nums.size();++i)
		{
			num += nums[i];
			sums.push_back(num);
		}
	}

	int sumRange(int i, int j) {
		if (j > sums.size() || i<0 || i>j)
			return 0;

		if (0 == i)
			return sums[j];
		return sums[j] - sums[i - 1];
	}
};

int main()
{
	int num[] = { -2,0,3,-5,2,-1 };
	vector<int> data(num, num + sizeof(num) / sizeof(int));
	NumArray sol(data);
	cout << sol.sumRange(2, 5);

	return 0;
}
