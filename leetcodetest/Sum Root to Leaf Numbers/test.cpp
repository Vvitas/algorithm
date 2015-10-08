#include"../leetcodetest/head.h"

class Solution 
{
private:
	void sumNumbers(TreeNode* root, long long num, long long& result)
	{
		num = num * 10 + root->val;

		if (root->left || root->right)
		{
			if (root->left)
				sumNumbers(root->left, num, result);
			if (root->right)
				sumNumbers(root->right, num, result);
		}
		else
		{
			result += num;
		}
	}

public:
	int sumNumbers(TreeNode* root) 
	{
		if (root == NULL)
			return 0;

		long long num = 0, result = 0;
		sumNumbers(root, num, result);

		if (result > INT_MAX) 
			return INT_MAX;
		else return (int)result;
	}
};

int main()
{

}