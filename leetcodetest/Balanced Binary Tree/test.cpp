#include"../leetcodetest/head.h"

class Solution
{
private:
	bool isBalanced(TreeNode *root, int &depth)
	{
		if (root == NULL)
		{
			depth = 0; return true;
		}

		int left, right;
		if (isBalanced(root->left, left) && isBalanced(root->right, right))
		{
			if ((left - right <= 1) && (left - right) >= -1)
			{
				depth = 1 + (left > right ? left : right);
				return true;
			}
			else return false;
		}
		return false;
	}

public:
	bool isBalanced(TreeNode* root)
	{
		int depth = 0;
		return isBalanced(root, depth);
	}
};

int main()
{
	return 0;
}