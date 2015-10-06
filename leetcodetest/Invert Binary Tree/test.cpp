#include"../leetcodetest/head.h"

class Solution
{
private:
	void invertNodeFun(TreeNode* root)
	{
		if (root == NULL || (root->left == NULL&&root->right == NULL))
			return;

		TreeNode *node = root->left;
		root->left = root->right;
		root->right = node;

		invertNodeFun(root->left);
		invertNodeFun(root->right);
	}

public:
	TreeNode* invertTree(TreeNode* root)
	{
		invertNodeFun(root);
		return root;
	}
};

int main()
{
	return 0;
}