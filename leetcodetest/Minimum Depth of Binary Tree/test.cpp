#include"../leetcodetest/head.h"

class Solution
{
private:
	int getMinDepth(TreeNode* root)
	{
		if (root == NULL) return 0;

		int left = getMinDepth(root->left);
		int right = getMinDepth(root->right);

		if (left == 0 || right == 0)
			return left ? (left + 1) : (right + 1);
		else return left < right ? (left + 1) : (right + 1);
	}

public:
	int minDepth(TreeNode* root)
	{
		return getMinDepth(root);
	}
};

int main()
{
	return 0;
}