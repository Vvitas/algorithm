#include"../leetcodetest/head.h"

class Solution 
{
public:
	int removeDuplicates(vector<int>& data) 
	{
		if (data.size() == 0)
			return 0;
		else if (data.size() == 1)
			return 1;

		int i, j, len = 0, num = data[0], cnt = 1;

		for (i = 1; i < (int)data.size(); i++)
		{
			if (data[i] == num)
			{
				++cnt;
			}
			else
			{
				cnt = (cnt < 2) ? cnt : 2;
				for (j = 0; j < cnt; j++)
					data[len++] = num;
				cnt = 1, num = data[i];
			}
		}

		cnt = (cnt < 2) ? cnt : 2;
		for (i = 0; i < cnt; i++)
			data[len++] = num;

		return len;
	}
};

int main()
{
	int num[]{ 1,1,1 };
	vector<int> data(num, num + sizeof(num) / sizeof(int));
	Solution test;
	test.removeDuplicates(data);
	return 0;
}