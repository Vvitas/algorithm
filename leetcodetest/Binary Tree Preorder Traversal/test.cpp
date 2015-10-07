#include"../leetcodetest/head.h"

class Solution
{
public:
	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int> result;
		stack<TreeNode*> sdata;
		TreeNode* node = root;

		while (root || !sdata.empty())
		{
			while (root)
			{
				sdata.push(root);
				result.push_back(root->val);
				root = root->left;
			}

			if (!sdata.empty())
			{
				root = sdata.top()->right;
				sdata.pop();
			}
		}
		return result;
	}
};

int main()
{
	return 0;
}