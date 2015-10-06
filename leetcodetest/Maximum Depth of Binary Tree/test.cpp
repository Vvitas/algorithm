#include"../leetcodetest/head.h"

class Solution
{
private:
	void DepthofTree(TreeNode* root, int& depth)
	{
		if (root == NULL) depth = 0;
		else
		{
			int left = 0, right = 0;
			DepthofTree(root->left, left);
			DepthofTree(root->right, right);
			depth = (left > right ? left : right) + 1;
		}
	}

public:
	int maxDepth(TreeNode* root)
	{
		if (root == NULL) return 0;
		else
		{
			int depth = 0;
			DepthofTree(root, depth);
			return depth;
		}
	}
};

int main()
{
	return 0;
}