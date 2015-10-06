#include"../leetcodetest/head.h"

class Solution
{
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		if (n == 0) return;

		int i, length = m + n - 1, t1 = m - 1, t2 = n - 1;

		for (i = length; i >= 0 && t1 >= 0 && t2 >= 0; --i)
		{
			if (nums1[t1] > nums2[t2])
			{
				nums1[i] = nums1[t1--];
			}
			else
			{
				nums1[i] = nums2[t2--];
			}
		}

		if (t1 >= 0)
		{
			for (i; i >= 0; --i)
			{
				nums1[i] = nums1[t1--];
			}
		}
		else if (t2 >= 0)
		{
			for (i; i >= 0; --i)
			{
				nums1[i] = nums2[t2--];
			}
		}
	}
};

int main()
{
	return 0;
}