#include<vector>
#include<array>
using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {

		long long num = 0, temp = 1;
		vector<int> res;

		for (size_t i = 0;i < nums.size();++i)
		{
			if (nums[i] == 0)
				++num;
			else temp *= nums[i];
		}

		if (0 == num)
		{
			for (size_t i = 0;i < nums.size();++i)
			{
				res.push_back(int(temp / nums[i]));
			}
		}
		else
		{
			for (size_t i = 0;i < nums.size();++i)
			{
				if (0 == nums[i])
				{
					if (num > 1)
						res.push_back(0);
					else res.push_back((int)temp);
				}
				else res.push_back(0);
			}
		}

		return res;
	}
};

int main()
{
	vector<int> test(2, 0);
	Solution sol;
	sol.productExceptSelf(test);

	return 0;
}