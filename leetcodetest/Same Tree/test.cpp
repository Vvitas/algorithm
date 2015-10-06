#include"../leetcodetest/head.h"

class Solution
{
public:
	bool isSameTree(TreeNode* p, TreeNode* q)
	{
		if (p == NULL && q == NULL)
			return true;
		else if (p == NULL || q == NULL)
			return false;

		bool sign = false;

		if (p->val == q->val)
		{
			sign = judgeSameTree(p, q);
		}

		if (!sign)
		{
			sign = isSameTree(p->left, q);
			if (!sign)
				sign = isSameTree(p->right, q);
		}

		return sign;
	}

	bool judgeSameTree(TreeNode *root, TreeNode *temp)
	{
		if (temp == NULL)
			return true;
		if (root == NULL)
			return false;

		if (root->val != temp->val)
			return false;
		else
			return judgeSameTree(root->left, temp->left) && judgeSameTree(root->right, temp->right);
	}
};

int main()
{
	return 0;
}