#include"../leetcodetest/head.h"

class Solution {
private:
	bool isSymmetric(TreeNode *root1, TreeNode *root2)
	{
		if (root1 == NULL&&root2 == NULL)
			return true;
		if (root1 == NULL || root2 == NULL)
			return false;
		if (root1->val != root2->val)
			return false;
		return isSymmetric(root1->left, root2->right) &&
			isSymmetric(root1->right, root2->left);
	}

public:
	bool isSymmetric(TreeNode* root)
	{
		isSymmetric(root, root);
	}
};

int main()
{
	return 0;
}